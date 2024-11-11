#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,s,a;
signed main()
{
	cin>>s>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a;
		s-=a;
	}
	cout<<max(-1,s);
}