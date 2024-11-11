#include <bits/stdc++.h>
using namespace std;

#define int long long

int n,a[100005],b[100005],ans=0;

signed main()
{
	cin>>n;
	for(int i=1;i<=n+1;cin>>a[i++]);
	for(int i=1;i<=n;cin>>b[i++]);
	for(int i=1;i<=n;i++)
	{
		if(b[i]>=a[i])
		{
			ans += min(b[i],a[i]+a[i+1]);
			a[i+1] = max(a[0],a[i+1]-b[i]+a[i]);
		}
		else
			ans += b[i];
	}
	cout<<ans<<endl;
	
	return 0;
}