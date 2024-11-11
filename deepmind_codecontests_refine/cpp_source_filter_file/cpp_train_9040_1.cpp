#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mod = 1e9+7, inf = 2e18;
ll n, a, b, x[100005], za, zb;
vector<ll> ca, cb;

ll getA (ll X) {
	if(X < za) return 0;
	if(za) return (ca[X] - ca[za-1] + mod) % mod;
	return ca[X];
}

ll getB (ll X) {
	if(X < zb) return 0;
	if(zb) return (cb[X] - cb[zb-1] + mod) % mod;
	return cb[X];
}

int main()
{
	scanf("%lld%lld%lld",&n,&a,&b);
	for(int i=1;i<=n;i++) {
		scanf("%lld",&x[i]);
	}
	x[0] = -inf;
	ca.push_back(1);
	cb.push_back(1);
	for(int i=2;i<=n;i++) {
		ll fa = min(upper_bound(x, x+n+1, x[i]-a) - x - 1, i - 2ll);
		ll fb = min(upper_bound(x, x+n+1, x[i]-b) - x - 1, i - 2ll);
		ca.push_back((getB(fb)+ca.back())%mod);
		cb.push_back((getA(fa)+cb.back())%mod);
		if(x[i-1] + a > x[i]) zb = i-1;
		if(x[i-1] + b > x[i]) za = i-1;
	}
	printf("%lld\n",(getA(n-1)+getB(n-1)) % mod);
}
