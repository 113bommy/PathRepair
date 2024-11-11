#include <bits/stdc++.h>
using namespace std;

//#define int long long
#define reps(i,s,n) for(int (i)=(s);(i)<(n);++(i))
#define rep(i,n) reps(i,0,n)
#define rept(i,n) rep(i,(n)+1)
#define repst(i,s,n) reps(i,s,(n)+1)
#define reprt(i,n,t) for(int (i)=(n);(i)>=(t);--(i))
#define repr(i,n) reprt(i,n,0)
#define each(itr,v) for(auto &(itr):(v))
#define all(c) (c).begin(),(c).end()
#define rall(c) (c).rbegin(),(c).rend()
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define tmax(x,y,z) max(x,max(y,z))
#define tmin(x,y,z) min(x,min(y,z))
#define chmin(x,y) if((x)>(y))(x)=(y)
#define chmax(x,y) if((x)<(y))(x)=(y)
#define ln '\n'
#define bln(i,n) (((i)==(n)-1)?'\n':' ')
#define dbg(x) cout<<#x" = "<<(x)<<ln<<flush
#define dbga(x,n) {cout<<#x" : ";for(int (i)=0;i<(n);++i){cout<<((x)[i])<<(i==((n)-1)?'\n':' ')<<flush;}}

typedef long double ld;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<string> vst;
typedef vector<bool> vb;
typedef vector<ld> vld;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<vector<int> > mat;

const ll inf = (ll)1e9+10;
const ll linf = (ll)1e18+10;
const ll mod = (ll)(1e9+7);
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};
const int ddx[] = {0, 1, 1, 1, 0, -1, -1, -1};
const int ddy[] = {1, 1, 0, -1, -1, -1, 0, 1};
const double eps = 1e-10;

ll mop(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) {return b?gcd(b,a%b):a;}
ll lcm(ll a,ll b) {return a*b/gcd(a,b);}

struct oreno_initializer {
	oreno_initializer() {
		cin.tie(0);
		ios::sync_with_stdio(0);
	}
} oreno_initializer;

// ━━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…
// .｡.:( ^ω^)・ﾟ＋.｡.:( ^ω^)・ﾟ＋.｡.:( ^ω^)・ﾟ＋.｡.:( ^ω^)・ﾟ＋.｡.:( ^ω^)・ﾟ＋
// ・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・‥…━━━☆・

int n, l[50], u[50], r[50], d[50];
ll s[222][222];
bool v[222][222];

void rec(int x, int y) {
	v[x][y] = true;
	rep(i,4) {
		int xx = x + dx[i], yy = y + dy[i];
		if (xx<0 || 222<=xx || yy<0 || 222<=yy || v[xx][yy] || s[xx][yy]!=s[x][y]) continue;
		rec(xx,yy);
	}
}

signed main() {
	while (1) {
		cin >> n;
		if (n==0) break;
		vi xs, ys;
		rep(i,n) {
			cin >> l[i] >> u[i] >> r[i] >> d[i];
			xs.pb(u[i]), xs.pb(d[i]), ys.pb(l[i]), ys.pb(r[i]);
		}
		sort(all(xs)), sort(all(ys));
		xs.erase(unique(all(xs),xs.end())), ys.erase(unique(all(ys),ys.end()));
		int h = 2, w = 2;
		map<int,int> x, y;
		rep(i,xs.size()) x[xs[i]] = h, h += 2;
		rep(i,ys.size()) y[ys[i]] = w, w += 2;
		memset(s,0,sizeof(s));
		rep(k,n) reps(i,x[d[k]]+1,x[u[k]]) reps(j,y[l[k]]+1,y[r[k]]) s[i][j] |= 1ll<<k;
		int res = 0;
		memset(v,0,sizeof(v));
		rep(i,222) rep(j,222) if (!v[i][j]) res++, rec(i,j);
		cout << res << ln;
	}
}
