#include <bits/stdc++.h>
using namespace std;

int main() {
	string s;
	cin >> s;
	int sl = s.size();
	for(int i = 1;i < s.size()/2;i++)
	{
		sl -= 2;
		if(s.substr(0,sl/2) == s.substr(sl/2,sl/2))
		{
			break;
		}
	}
    cout << sl << endl;
	return 0;
}
