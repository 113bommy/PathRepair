#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[200005],sum;
signed main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		sum+=a[i];
	}
	sort(a+1,a+n+1);
	for(int i=n;i>=max(n-m+1,1);i--)
		sum-=a[i];
	cout<<sum;
	return 0;
}