#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[200000];
signed main()
{
	int n,i,ans=0;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>a[i];
		ans^=a[i];
	}
	for(i=0;i<n;i++)
		cout<<ans^a[i]<<' ';
	return 0;
}