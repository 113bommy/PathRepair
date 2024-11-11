clude <iostream>
#include <string>
using namespace std;
#define REP(i, n) for(int i=0; i<(n); i++)
#define SZ(x) ((int)(x).size())

int main() {
	string s;
	cin >> s;
	int n = SZ(s), p = 0;
	REP(i, n)if (s[i] == 'p')p++;
	cout << n / 2 - p << endl;
}