#include <iostream>
#include <string>
using namespace std;


int main(){
	string s;

	while (cin >> s){
		for (auto& it = s.begin(); it != s.end(); it++){
			if (*it != '@'){
				cout << *it;
				continue;
			}
			it++;
			int n = (*it) - '0';
			it++;
			for (int i = 0; i < n; i++){
				cout << *it;
			}
		}
		cout << endl;
	}

	return 0;
}