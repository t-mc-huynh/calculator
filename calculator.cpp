#include <iostream>
//#include <cmath> // isgreater(x, y) returns bool (value)
#include <fstream>
#include <string>
using namespace std;

class digit
{
public:
	int data;
	digit *next = NULL;
};

digit *loadNumber(ifstream &file);
char getOperator(ifstream &file);
void writeNumber(digit *num, ofstream &file);
void deleteNumber(digit *num);
digit *addNumbers(digit *left, digit *right);
digit *subNumbers(digit *left, digit *right); // optional

int main()
{
	ifstream inFile;
	inFile.open("largeNumbers.txt");

	char operatorSymbol;

	digit * firstNumber, * secondNumber;
	firstNumber = new digit;
	secondNumber = new digit;

	// stores first and second numbers for the operation
	firstNumber = loadNumber(inFile);
	
	cout << endl;
	secondNumber = loadNumber(inFile);

	cout << endl;

	// stores the operator for the operation
	operatorSymbol = getOperator(inFile);
	cout << operatorSymbol << endl;

	if (operatorSymbol == '+')
		addNumbers(firstNumber, secondNumber);
	else if (operatorSymbol == '-')
		subNumbers(firstNumber, secondNumber);
}

digit *loadNumber(ifstream &file)
{
	if (file.eof())
		return nullptr;
		
	digit * head = new digit;
	digit * number = head;

	char temp;

	file.get(temp);
	
	while (temp != '\n' && !file.eof()) {
		head->data = int(temp - '0');
		cout << head->data << "\t";
		file.get(temp);
		head = new digit;
		head->next = number;
		number = head;
	}

	// while(head->next != NULL) {
	// 	cout << head->data << "\t";
	// 	head = head->next;
	// }

	return head;
}

char getOperator(ifstream &file)
{
	char operatorSymbol;
	string temp;

	file.get(operatorSymbol);

	// gets the rest of the line
	getline(file, temp);

	return operatorSymbol;
}

digit *addNumbers(digit *left, digit *right)
{
	digit * result = new digit;
	digit * head;

	//cout << left->data << endl;
	while (left->next != NULL)
	{
		result->data = left->data + right->data;
		cout << result->data << "\t";
		head = new digit;
		result->next = head;
		left = left->next;
		right = right->next;
	}

	return result;
}

digit *subNumbers(digit *left, digit *right)
{
	digit * result = new digit;

	return result;
}