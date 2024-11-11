#include <bits/stdc++.h>
using namespace std;
#define nn 65536*4
#define ll long long
msp<ll,ll> cnt;ll a[nn];ll s[nn];
ll n;
int main()
{
	ll ans=0;cnt[0]=1;
	cin>>n;for(int i=1;i<=n;i++) 
		scanf("%lld",&a[i]),s[i]=s[i-1]+a[i],ans+=cnt[s[i]]++;
	cout<<ans;
    return 0;
}