#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using ld=long double;
using P=pair<ll,ll>;
#define MOD 1000000007ll
#define INF 1000000000ll
#define EPS 1e-10
#define FOR(i,n,m) for(ll i=n;i<(ll)m;i++)
#define REP(i,n) FOR(i,0,n)
#define DUMP(a) REP(d,a.size()){cout<<a[d];if(d!=a.size()-1)cout<<" ";else cout<<endl;}
#define ALL(v) v.begin(),v.end()
#define UNIQUE(v) sort(ALL(v));v.erase(unique(ALL(v)),v.end());
#define pb push_back

ll gcd(ll a, ll b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}
ll n, m;
vector<ll> a;
vector<ld> p;
vector<ll> dp[(1ll << 20)];

ll _lcm(ll bit) {
	if(bit == 0) return INF * INF + INF;
	bitset<31> bi(bit);
	vector<ll> v;
	REP(i,n) {
		if(bi[i]) v.pb(a[i]);
	}
	__int128 g = v[0];
	FOR(i,1,v.size()) {
		ll tmp = gcd(g, v[i]);
		g = tmp * (g / tmp) * (v[i] / tmp);
		if(g > INF * INF) return INF * INF + INF;
	}
	return g;
}

ld solve() {
	cin >> n >> m;
	a.resize(n); p.resize(n);
	REP(i,n) cin >> a[i]; REP(i,n) cin >> p[i]; REP(i,n) p[i] /= 100;
	ld ans = 0;
	FOR(bit,1,(1 << n)) {
		bitset<31> bi(bit);
		ld prob = 1;
		REP(i,n) {
			if(bi[i]) prob *= p[i];
			else prob *= (1 - p[i]);
		}
		ll g = lcm(bit);
		ll crt = 0;
		if(bi.count() % 2) crt = m / g;
		else crt = -(m / g);
		ll sum = 0;
		REP(i,n) {
			if(bi[i]) {
				if(sum != 0) {
					dp[bit].emplace_back(crt + dp[bit ^ (1 << i)][sum - 1]);
				} else {
					ll _g = 0;
					if(!(bi.count() % 2)) _g = (m / lcm(bit ^ (1 << i)));
					else _g = -(m / lcm(bit ^ (1 << i)));
					dp[bit].emplace_back(crt + _g);
				}
				crt = dp[bit].back();
				sum++;
			}
		}
		ans += prob * crt;
		dp[bit].shrink_to_fit();
	}
	return ans;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cout << fixed << setprecision(39) << solve() << endl;
	return 0;
}

