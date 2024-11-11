#include <bits/stdc++.h>
#define ADD(a, b) a = (a + ll(b)) % mod
#define MUL(a, b) a = (a * ll(b)) % mod
#define MAX(a, b) a = max(a, b)
#define MIN(a, b) a = min(a, b)
#define rep(i, a, b) for(int i = int(a); i < int(b); i++)
#define rer(i, a, b) for(int i = int(a) - 1; i >= int(b); i--)
#define all(a) (a).begin(), (a).end()
#define sz(v) (int)(v).size()
#define pb push_back
#define sec second
#define fst first
#define debug(fmt, ...) Debug(__LINE__, ":", fmt, ##__VA_ARGS__)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef pair<int, pi> ppi;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vl> mat;
typedef complex<double> comp;
void Debug() {cout << '\n'; }
template<class FIRST, class... REST>void Debug(FIRST arg, REST... rest){
	cout<<arg<<" ";Debug(rest...);}
template<class T>ostream& operator<<(ostream& out,const vector<T>& v) {
	out<<"[";if(!v.empty()){rep(i,0,sz(v)-1)out<<v[i]<<", ";out<<v.back();}out<<"]";return out;}
template<class S, class T>ostream& operator<<(ostream& out,const pair<S, T>& v){
	out<<"("<<v.first<<", "<<v.second<<")";return out;}
const int MAX_N = 300010;
const int MAX_V = 100010;
const double eps = 1e-6;
const ll mod = 1000000007;
const int inf = 1 << 30;
const ll linf = 1LL << 60;
const double PI = 3.14159265358979323846;
///////////////////////////////////////////////////////////////////////////////////////////////////

int N, D;
int S[1010][1010];
int E[2010][2010];
int F[2010][2010];

bool ok(ll m) {
	ll sv = m / D, lv = m / D + 1;
	ll l = 0;
	rep(i, 0, D) if(i + D * sv < m) l++;
	memset(E, 0, sizeof(E)); memset(F, 0, sizeof(F));
	int lcnt = 0;
	rep(i, 0, D) {
		rep(j, 0, D) {
			if(D[i][j] > lv * lv) return false;
		}
	}
	rep(i, 0, D * 2) {
		rep(j, 0, D * 2) {
			if(S[i % D][j % D] > lv * sv) {
				lcnt++;
				E[i + 1][j + 1]++;
			}
			if(S[i % D][j % D] > sv * sv) {
				F[i + 1][j + 1]++;
			}
			E[i + 1][j + 1] += E[i][j + 1] + E[i + 1][j] - E[i][j];
			F[i + 1][j + 1] += F[i][j + 1] + F[i + 1][j] - F[i][j];
		}
	}
	lcnt /= 4;
	// debug(sv, lv, l);
	// rep(i, 0, D) debug(vi(S[i], S[i] + D));
	// rep(i, 0, 2 * D + 1) debug(vi(E[i], E[i] + 2 * D + 1));
	// rep(i, 0, 2 * D + 1) debug(vi(E[i], E[i] + 2 * D + 1));
	rep(i, 0, D) {
		rep(j, 0, D) {
			if(E[i + l][j + l] - E[i][j + l] - E[i + l][j] + E[i][j] == lcnt) {
				int x = i + l, y = j + l;
				int nx = i + D, ny = i + D;
				if(F[nx][ny] - F[nx][y] - F[x][ny] + F[x][y] == 0) return true;
			}
		}
	}
	return false;
}

void solve() {
	cin >> N >> D;
	rep(i, 0, N) {
		int x, y; cin >> x >> y;
		S[x % D][y % D]++;
	}
	ll lv = 0, rv = 1000000000;
	while(rv - lv > 1) {
		ll m = (lv + rv) / 2;
		if(ok(m)) rv = m;
		else lv = m;
	}
	cout << rv - 1 << "\n";
}

int main() {
#ifndef LOCAL
	ios::sync_with_stdio(false);
    cin.tie(0);
#endif
    cout << fixed;
	cout.precision(20);
	srand((unsigned int)time(NULL));
#ifdef LOCAL
	//freopen("in.txt", "wt", stdout); //for tester
    freopen("in.txt", "rt", stdin);
#endif	
	solve();
#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
	return 0;
}

