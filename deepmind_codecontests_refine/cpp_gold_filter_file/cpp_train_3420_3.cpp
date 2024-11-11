#include <bits/stdc++.h>
using namespace std;
 
int n;
string s[100010], t;
int main()
{
	cin >> n;
	for(int i = 1; i <= n; i ++)
		cin >> s[i];
	cin >> t;
	int ansl = 1, ansr = 1;
	for(int i = 1; i <= n; i ++)
	{
		bool L = 0, R = 0;
		string x = s[i];
		for(int j = 0; j < x.size(); j ++)
			if(s[i][j] == '?') x[j] = 'z';
		if(x >= t) R = 1;
		for(int j = 0; j < x.size(); j ++)
			if(s[i][j] == '?') x[j] = 'a';
		if(x <= t) L = 1;
		if(L && R) ansr ++;
		else if(L) ansl ++, ansr ++;
	}
	for(int i = ansl; i <= ansr; i ++)
		cout<<i<<" \n"[i==ansr];
        return 0;
}