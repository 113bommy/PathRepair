#include<bits/stdc++.h>
#define N (100009)
#define ll long long
using namespace std;
ll n,q,x,a[N],c,A[N],f[N];
ll main()
{
	cin>>n>>q;
	a[++c]=n;
	for (ll i=1; i<=q; ++i)
	{
		cin>>x;
		while (c && x<=a[c]) --c;
		a[++c]=x;
	}
	f[c]=1;
	for (ll i=c; i; --i)
	{
		ll k=a[i];
		while (k>a[1])
		{
			ll t=lower_bound(a+1,a+c+1,k)-a-1;
			f[t]+=f[i]*(k/a[t]);
			k%=a[t];
		}
		A[k]+=f[i];
	}
	for (ll i=n; i; --i) A[i]+=A[i+1];
	for (ll i=1; i<=n; ++i) cout<<A[i]<<endl;
}