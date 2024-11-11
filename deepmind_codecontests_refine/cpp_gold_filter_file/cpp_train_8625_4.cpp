#include <iostream>
#include <string>
using namespace std;

int main() {
	int p = 0;
	int n = 0;
	string s;
	cin >> s;
	for(int i = 0; i < s.size(); i++){
		if(s[i] == 'p') p++;
	}
	n = s.size() / 2;
	cout << (int) n - p << endl;
}