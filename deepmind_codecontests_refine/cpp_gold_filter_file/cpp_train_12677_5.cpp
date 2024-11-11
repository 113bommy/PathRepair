#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+1000;
ll a[N],b[N];
int n,m;
ll k;
int main()
{
	cin>>n>>m>>k;
	ll ans=0;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=m;i++) cin>>b[i];
	for(int i=1;i<=n;i++) a[i]+=a[i-1];
	for(int i=1;i<=m;i++) b[i]+=b[i-1];
	for(ll i=0;i<=n;i++)
	{
		if(k>=a[i]) 
		{
			ans=max(ans,upper_bound(b+1,b+1+m,k-a[i])-b-1+i);
		 } 
	}
	cout<<ans<<endl;
}