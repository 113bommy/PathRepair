#include<iostream>
#include<string>
using namespace std;
int n;
string str;
bool check(int num) {
	int a = 0, b = 0, c = 0;
	for (int i = n - 1; i > -1; --i) {
		if (str[i] == 'I') {
			if (a < num)++a;
			else if (c < b)++c;
		}
		else if (str[i] == 'O') {
			if (b < a) {
				++b;
			}
		}
		else if (c < b)++c;
	}
	if (c >= num)return true;
	else return false;
}
int main() {
	cin >> n >> str;
	int ni = 1, na = n / 3 + 1;
	while (ni < na) {
		int nd = (ni + na) / 2;
		if (check(nd)) {
			ni = nd + 1;
		}
		else {
			na = nd;
		}
	}
	cout << ni - 1 << endl;
	return 0;
}