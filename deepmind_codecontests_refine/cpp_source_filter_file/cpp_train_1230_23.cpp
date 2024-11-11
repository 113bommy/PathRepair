#include <bits.stdc++.h>
using namespace std;

string s;

int main() {
	cin >> s;
	int res = 0;
	for(int i=0;i<4;i++) {
		if (s[i]=='+') res++;
		else res--;
    }
	cout << res << endl;
}