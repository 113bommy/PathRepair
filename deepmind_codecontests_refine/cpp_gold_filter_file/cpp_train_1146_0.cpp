#include <bits/stdc++.h>
using namespace std;
struct cww{cww(){ios::sync_with_stdio(false);cin.tie(0);}}star;
#define P(x) cout << (x) << "\n"
#define p(x) cout << (x)
#define all(c) (c).begin(), (c).end()
#define rall(c) (c).rbegin(), (c).rend()
#define vv(type, c, m, n, i) vector<vector<type>> c(m, vector<type>(n, i))
#define rep(i,a,n) for(int i=(a), i##_len=(n); i<i##_len; ++i)
#define rrep(i,a,n) for(int i=(a), i##_len=(n); i>i##_len; --i)
#define len(x) ((int)(x).size())
#define mp make_pair
#define eb emplace_back
#define fi first
#define se second
#define chmax(a,b) if(a<b)a=b
#define chmin(a,b) if(a>b)a=b
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<long long> vll;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef pair<int, int> pii;
void square() {
	int n; cin >> n;
	vll h(n); rep(i, 0, n) cin >> h[i];
	deque<pair<ll, ll>> st;
	st.eb(-1, -1);
	ll ans = 0, pos;
	rep(i, 0, n) {
		if (st.back().fi == h[i]) continue;
		pos = i;
		while (st.back().fi >= h[i]) {
			chmax(ans, st.back().fi * (i - st.back().se));
			pos = st.back().se;
			st.pop_back();
		}
		st.eb(h[i], pos);
	}

	while (!st.empty()) {
		chmax(ans, st.back().fi * (n - st.back().se));
		st.pop_back();
	}

	P(ans);
}
int main() {
	square();
	return 0;
}