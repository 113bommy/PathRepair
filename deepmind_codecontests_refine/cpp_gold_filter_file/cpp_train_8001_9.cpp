#include <iostream>
#include <string>
using namespace std;

int main(){
	string str;
	getline(cin, str);
	for(int i = 0; i < str.size(); i++){
		if(str[i] < 90){
			continue;
		}
		else{
			str[i] -= 32;
		}
	}
	cout << str << endl;
	return 0;
}