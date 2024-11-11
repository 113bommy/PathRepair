#include <bits/stdc++.h>
#define INF (1ll<<60)
#define MOD 1000000007
#define BOUND 27182818284
#define l_ength size
using ll = long long;
using namespace std;

int main(){
	int a, b, q; cin >> a >> b >> q;
	vector<ll> s(a+2);
	vector<ll> t(b+2);
	s.front() = t.front() = -BOUND;
	s.back() = t.back() = BOUND;
	for( int i = 1; i < a+1; ++i ){
		cin >> s[i];
	}
	for( int i = 1; i < b+1; ++i ){
		cin >> t[i];
	}
	for( int i = 0; i < q; ++i ){
		ll v; cin >> v;
		ll sb = upper_bound( s.begin(), s.end(), v ) - s.begin();
		ll sa = sb-1;
		sb = s[sb]; sa = s[sa];
		ll td = upper_bound( t.begin(), t.end(), v ) - t.begin();
		ll tc = td-1;
		td = t[td]; tc = t[tc];
		ll ans = min({ abs(sa-v)+abs(tc-sa), abs(sa-v)+abs(td-sa), abs(sb-v)+abs(tc-sb), abs(sb-v)+abs(td-sb),  abc(tc-v)+abs(sa-tc), abs(tc-v)+abs(sb-tc), abc(td-v)+abs(sa-td), abs(td-v)+abs(sb-td) });
		cout << ans << endl;
	}
	return 0;
}