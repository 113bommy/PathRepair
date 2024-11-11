#include<bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(int)n;i++)
#define all(c) (c).begin(),(c).end()
#define mp make_pair
#define pb push_back
#define each(i,c) for(__typeof((c).begin()) i=(c).begin();i!=(c).end();i++)
#define dbg(x) cerr<<__LINE__<<": "<<#x<<" = "<<(x)<<endl

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
const int inf = (int)1e9;
const double INF = 1e12, EPS = 1e-9;

ll bit[131072];
ll sum(int i){
	ll res = 0;
	for(; i; i -= i & -i) res += bit[i];
	return res;
}
void add(int i, int x){
	for(; i < 131072; i += i & -i) bit[i] += x;
}

const int B = 500;
int n, p[100000];
ll ans[200000];

int main(){
	cin.tie(0); cin.sync_with_stdio(0);
	cin >> n;
	rep(i, n) cin >> p[i];
	int q; cin >> q;
	
	vector<pair<pi, int>> v; //l/B, r, l
	rep(i, q){
		int l, r; cin >> l >> r; l--;
		v.pb(mp(mp(l / B, r), mp(l, i)));
	}
	int cnt = 0;
	sort(all(v));
	int L = 0, R = 0; ll res = 0;
	for(auto &i: v){
		int r = i.first.second, l = i.second.first;
		while(R < r) { assert(L <= R); res += R - L - sum(p[R]);         add(p[R++], 1); }
		while(L > l) { assert(L <= R); res += sum(p[--L]);               add(p[L], 1); }
		while(L < l) { assert(L < R); res -= sum(p[L]) - 1;             add(p[L++], -1); }
		while(R > r) { assert(L < R); res -= R - L; res += sum(p[--R]); add(p[R], -1); }
		ans[i.second.second] = res;
	}
	rep(i, q) printf("%lld\n", ans[i]);
	
	return 0;
}