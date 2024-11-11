#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MaxN = 2e5 + 7, Pt = 1e9 + 7;

ll fac[MaxN + 5], inv[MaxN + 5];

ll qwr(ll x, int y) {
	LL res = 1;
	while(y) {
		if(y & 1) res = res * x % Pt;
		y >>= 1;
		x = x * x % Pt;
	}
	return res;
}

ll C(int n, int m) {
	return fac[n] * inv[n - m] % Pt * inv[m] % Pt;
}


int main() {
	ll res = 1;
	fac[0] = 1;
	for (LL i = 1; i <= MaxN; i++) fac[i] = fac[i - 1] * i % Pt;
	inv[MaxN] = qwr(fac[MaxN], Pt - 2);
	inv[0] = 1;
	for(ll i = MaxN - 1; i >= 1; i--) inv[i] = inv[i + 1] * (i + 1) % Pt;
	int n, m;
	scanf("%d %d", &n, &m);
	int t = m;
	for(int i = 2; i * i <= m; i++) {
		if(t % i == 0) {
			int cnt = 0;
			while(t % i == 0) t /= i, cnt++;
			res = res * C(n + cnt - 1, n - 1) % Pt;
		}
	}
	if(t > 1) res = res * C(n, n - 1) % Pt;
	printf("%lld\n", res);
    return 0;
}
