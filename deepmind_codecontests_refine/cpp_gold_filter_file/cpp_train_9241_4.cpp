#include <bits/stdc++.h>
using namespace std;

int main() {
	int k;
	string s;
	cin >> k >> s;
	if(k < s.size())
	{
		s = s.substr(0,k) + '.' + '.' + '.';
	}
	cout << s << endl;
	return 0;
}
