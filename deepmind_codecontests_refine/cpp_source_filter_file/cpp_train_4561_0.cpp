#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,res=0,cnt=0;
signed main()
{
	string s;
	cin>>s;
	n=s.length()
	s+='#';
	for(int i=0;i<=n;i++)
	{
		while(1)
		{
			if(s[i]=='A') cnt++,i++;
			else break;
		}
		if(s[i]=='B'&&s[i+1]=='C')
		res+=cnt,i=i+1;
		else cnt=0;
	}
	cout<<res;
}