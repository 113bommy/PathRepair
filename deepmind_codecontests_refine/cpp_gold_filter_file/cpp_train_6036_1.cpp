#include <iostream>
#include <string>

using namespace std;

int main(){
	string input;
	cin >> input;
	if (input.length() < 6){
		cout << "INVALID" << endl;
		return 0;
	}
	int flag = 0;
	for (int i = 0; i < input.length(); i++){
		if (input[i] >= '0'&&input[i] <= '9'){
			flag = 1;
			break;
		}
	}
	if (!flag){
		cout << "INVALID" << endl;
		return 0;
	}
	flag = 0;
	for (int i = 0; i < input.length(); i++){
		if (input[i] >= 'A'&&input[i] <= 'Z'){
			flag = 1;
			break;
		}
	}
	if (!flag){
		cout << "INVALID" << endl;
		return 0;
	}
	flag = 0;
	for (int i = 0; i < input.length(); i++){
		if (input[i] >= 'a'&&input[i] <= 'z'){
			flag = 1;
			break;
		}
	}
	if (!flag){
		cout << "INVALID" << endl;
		return 0;
	}
	cout << "VALID" << endl;
	return 0;
}