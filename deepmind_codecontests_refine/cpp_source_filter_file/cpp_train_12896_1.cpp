#include<iostream>
#include<string>
using namespace std;
string S, x[2][2][2] = { {{"black","blue"}, {"lime","aqua"}}, { {"red","fuchsia"} {"yellow","white"} } };
char T[9] = "89abcdef";
int a, b, c;
int main() {
	while (true) {
		a = 0; b = 0; c = 0;
		cin >> S;
		if (S == "0") { break; }
		for (int i = 0; i < 8; i++){
			if (T[i] == S[1]) {
				a = 1;
			}
		}
		for (int i = 0; i < 8; i++) {
			if (T[i] == S[3]) {
				b = 1;
			}
		}
		for (int i = 0; i < 8; i++) {
			if (T[i] == S[5]) {
				c = 1;
			}
		}
		cout << x[a][b][c] << endl;
	}
}