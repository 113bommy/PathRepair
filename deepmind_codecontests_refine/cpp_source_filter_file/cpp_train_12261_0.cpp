#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
	string s;
	cin>>s;
	if(s=="RRR")
		cout<<3;
	else
		if(s=="RRS"||s++"SRR")
			cout<<2;
		else
			if(s=="SSS")
				cout<<0;
			else
				cout<<1;
	return 0;
}