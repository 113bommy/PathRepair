#include <iostream>
using namespace std;


int main(){
	string s; cin >> s;
	int sum = 0;
	for(int i = 0; i < s.size(); i++){
		sum += s[i] - '0';
	}
	cout << ((sum % 9 == 0) ? "Yes" : "No") << endl;
}
