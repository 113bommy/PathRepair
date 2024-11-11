#include<bits/stdc++.h>

using namespace std;

#define FOR(i, x, y) for(int i = (x); i < (y); ++i)
#define REP(i, x, y) for(int i = (x); i <= (y); ++i)
#define PB push_back
#define MP make_pair
#define PH push
#define fst first
#define snd second
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef pair<int, int> pii;

const int maxn = 131072;
const int maxh = 1e5 + 5;
const int INF = 998244353;
const int G = 3;

int n, ans;
int cnt[maxh], fac[maxn], ifac[maxn], g[maxn];
vector<int> a, f;

inline  qpow(ll x, ll y){
	ll ret = 1;
	for(; y; y >>= 1){
		if(y & 1)
			(ret *= x) %= INF;
		(x *= x) %= INF;
	}
	return ret;
}

inline int C(int x, int y){ return 1ll * fac[x] * ifac[y] % INF * ifac[x - y] % INF; }

inline void fft(vector<int> &coe, int siz, int IDFT){
	for(; coe.size() < siz; coe.PB(0));
	for(int i = 0, j = 0; i < siz; ++i){
		if(i < j)
			swap(coe[i], coe[j]);
		for(int l = siz >> 1; (j ^= l) < l; l >>= 1);
	} 
	for(int step = 1; step < siz; step <<= 1){
		ll w;
		if(~IDFT)
			w = qpow(G, (INF - 1) / (step << 1));
		else
			w = qpow(G, INF - 1 - (INF - 1) / (step << 1));
		for(int i = 0; i < siz; i += step << 1){
			ll cur = 1;
			FOR(j, 0, step){
				int x = coe[i + j], y = 1ll * cur * coe[i + j + step] % INF;
				coe[i + j] = (x + y) % INF;
				coe[i + j + step] = (x - y + INF) % INF;
				(cur *= w) %= INF; 
			}
		}
	}
	if(!~IDFT){
		int inv = qpow(siz, INF - 2);
		FOR(i, 0, siz)
			coe[i] = 1ll * coe[i] * inv % INF;
	}
	return;
}

inline vector<int> mul(vector<int> a, vector<int> b){
	int siz = 1;
	for(; siz < a.size() + b.size(); siz <<= 1);
	fft(a, siz, 1);
	fft(b, siz, 1);
	vector<int> c;
	c.resize(siz);
	FOR(i, 0, siz)
		c[i] = 1ll * a[i] * b[i] % INF;
	fft(c, siz, -1);
//	FOR(i, 0, c.size())
//		printf("%d ", c[i]);
//	puts("");
	return c;
}

inline vector<int> solve(int l, int r){
	vector<int> ret; ret.PB(1);
	if(l == r){
   		REP(i, 1, a[l] / 2)
			ret.PB(1ll * C(a[l], i * 2) * g[i * 2]);
//		FOR(i, 0, ret.size())
//			printf("%d ", ret[i]);
//		puts(""); 
		return ret;
	}
	int md = l + r >> 1;
//	printf("l = %d r = %d\n", l, r);
	return mul(solve(l, md), solve(md + 1, r));
}

inline void precalc(){
	g[0] = 1;
	for(int i = 2; i < maxn; i += 2)
		g[i] = 1ll * g[i - 2] * (i - 1) % INF;
	fac[0] = 1;
	FOR(i, 1, maxn)
		fac[i] = 1ll * fac[i - 1] * i % INF;
	ifac[maxn - 1] = qpow(fac[maxn - 1], INF - 2);
	for(int i = maxn - 2; i >= 0; --i)
		ifac[i] = 1ll * ifac[i + 1] * (i + 1) % INF;
	return;
}

int main(){
	precalc();
	scanf("%d", &n);
	FOR(i, 0, n * 2){
		int x; scanf("%d", &x);
		++cnt[x];
	} 
	REP(i, 1, 100000) if(cnt[i])
		a.PB(cnt[i]);
	f = solve(0, a.size() - 1);
	REP(i, 1, n){
		int res = 1ll * f[i] * g[n * 2 - i * 2] % INF;
		if(i & 1)
			(ans += res) %= INF;
		else
			((ans -= res) += INF) %= INF;
	}
	
	ans = INF - ans;
	(ans += g[n * 2]) %= INF;
	printf("%d\n", ans);
	return 0;
}
