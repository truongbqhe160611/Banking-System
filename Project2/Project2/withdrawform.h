#pragma once
#include "Transaction.h"
#include "BankAccount.h"
#include "User.h"
namespace Project2 {
	extern   LinkedList<User> usertList;
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for withdrawform
	/// </summary>
	public ref class withdrawform : public System::Windows::Forms::Form
	{
	public:
		withdrawform(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

		withdrawform(int userIndex) {
			// Initialize the form
			InitializeComponent();
			// Use 'user' as needed
			loggedInUserIndex = userIndex;


		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~withdrawform()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ textBox1;

	private: int loggedInUserIndex;
	protected:
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ withdraw;

	private: System::Windows::Forms::Label^ label2;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(withdrawform::typeid));
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->withdraw = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(171, 125);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(109, 22);
			this->textBox1->TabIndex = 0;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(12, 279);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(52, 24);
			this->label1->TabIndex = 1;
			this->label1->Text = L"label1";
			this->label1->Click += gcnew System::EventHandler(this, &withdrawform::label1_Click);
			// 
			// withdraw
			// 
			this->withdraw->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11));
			this->withdraw->Location = System::Drawing::Point(171, 362);
			this->withdraw->Name = L"withdraw";
			this->withdraw->Size = System::Drawing::Size(100, 38);
			this->withdraw->TabIndex = 2;
			this->withdraw->Text = L"withdraw";
			this->withdraw->UseVisualStyleBackColor = true;
			this->withdraw->Click += gcnew System::EventHandler(this, &withdrawform::button1_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::Transparent;
			this->label2->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(12, 122);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(136, 24);
			this->label2->TabIndex = 3;
			this->label2->Text = L"enter the amount";
			// 
			// withdrawform
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(870, 570);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->withdraw);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox1);
			this->Name = L"withdrawform";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"withdrawform";
			this->Load += gcnew System::EventHandler(this, &withdrawform::withdrawform_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion



		void performwithdraw(double amount) {


			User currentUser = usertList.getElementAt(loggedInUserIndex);

			// Retrieve the current balance
			double currentBalance = currentUser.getBankAccount().getBalance();


			if (amount <= currentBalance) {
				// Update the user  balance
				currentBalance -= amount;
			}
			else {
				 MessageBox::Show("the amount is bigger than your current balance", "Information", MessageBoxButtons::OK, MessageBoxIcon::Information);
			}
			

			// Set the new balance 
			currentUser.getBankAccount().setBalance(currentBalance);

		
			usertList.replaceElementAt(loggedInUserIndex, currentUser);

			

			label1->Text = "Balance after withdraw: $" + currentUser.getBankAccount().getBalance();



		}

	private: System::Void withdrawform_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {

		double inputValue;

		Double::TryParse(textBox1->Text, inputValue);

		performwithdraw(inputValue);

	
	}
private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
}
};
}
