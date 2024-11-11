#include <bits/stdc++.h>
#define INF (1<<30)
#define MOD 1000000007
#define l_ength size
using ll = long long;
using namespace std;

ll fenwick[200100];

void add( int a, int x ){
	for( int i = a; i <= 200010; i += ( i & -i ) ) fenwick[i] += x;
}

ll sum( int a ){
	ll res = 0;
	for( int i = a; i > 0; i -= ( i & -i ) ) res += fenwick[i];
	return res;
}

int main(){
	ll n; cin >> n;
	vector<int> v(n);
	ll maxi = 0;
	for( auto &i : v ){
		cin >> i;
		maxi = max(i, maxi);
	}
	ll thres = n*(n+1)/4;
	ll l = 0, r = maxi+1;
	while( r-l > 1 ){
		ll m = (r+l)/2;
		vector<ll> s(n+1);
		s[0] = 100001;
		for( int i = 1; i <= n; ++i ){
			s[i] = s[i-1] + ( ( v[i-1] >= m ) ? 1 : -1 );
		}
        ll ans = 0;
		memset( fenwick, 0ll, sizeof(fenwick) );
        for( int i = 0; i <= n; ++i ){
            ans += sum(s[i]);
            add( s[i], 1 );
        }
		// cout << l << " " << m << " " << r << " " << ans << endl;
		if( ans >= thres ){
			l = m;
		} else {
			r = m;
		}
	}
	cout << l << endl;
	return 0;
}