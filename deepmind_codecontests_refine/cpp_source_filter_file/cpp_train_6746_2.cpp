#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,ans;
int q[N],f[N];
int dp[N],a[N];
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]
	}
	memset(q,0x3f,sizeof(q));
	for(int i=1;i<=n;i++)
	{
		f[i]=upper_bound(q+1,q+n,-a[i])-q;
		q[f[i]]=-a[i];
		ans=max(ans,f[i]);
	}
	cout<<ans<<endl;
 } 