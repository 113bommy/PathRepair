#include <bits/stdc++.h>
#define l_ength size
const int inf = (1<<30);
const int mod = 1000003;
using ll = long long;
using namespace std;

ll modPow(ll a, int n){
	ll res = 1;
	int i = 1;
	while( i <= n ) {
		if( n & i ){
			res *= a;
			res %= mod;
		}
		i <<= 1;
		a = a*a%mod;
	}
	return res;
}

ll mf[3000100];
ll dvf[3000100];

int main(){
	int q; cin >> q;
	mf[0] = 1; dvf[0] = 1;
	for( int k = 1; k <= 3000000; ++k ){
		mf[k] = (k*mf[k-1]) % mod;
		dvf[k] = (modPow(k, mod-2)*dvf[k-1]) % mod;
	}
	while( q-- ){
		ll x, d, n; cin >> x >> d >> n;
		if( d != 1 ){
			if( d == 0 ){
				cout << modPow(x, n)%mod; << endl;
				continue;
			}
			x = (x*modPow(d, mod-2))%mod;
		}
		if( n >= mod ) cout << 0 << endl;
		else cout << ( modPow(d, n) * ( mf[x+n-1]*dvf[x-1] % mod ) ) % mod << endl;
	}
	return 0;
}