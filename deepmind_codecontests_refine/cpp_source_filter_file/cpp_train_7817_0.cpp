#include <bits/stdc++.h>
using namespace std;
const int MOD = (int)1e9 + 7;
const int FFTMOD = 119 << 23 | 1;
const int INF = (int)1e9 + 23111992;
const long long LINF = (long long)1e18 + 23111992;
const long double PI = acos((long double)-1);
const long double EPS = 1e-9;
inline long long gcd(long long a, long long b) {
  long long r;
  while (b) {
    r = a % b;
    a = b;
    b = r;
  }
  return a;
}
inline long long lcm(long long a, long long b) { return a / gcd(a, b) * b; }
inline long long fpow(long long n, long long k, int p = MOD) {
  long long r = 1;
  for (; k; k >>= 1) {
    if (k & 1) r = r * n % p;
    n = n * n % p;
  }
  return r;
}
template <class T>
inline int chkmin(T& a, const T& val) {
  return val < a ? a = val, 1 : 0;
}
template <class T>
inline int chkmax(T& a, const T& val) {
  return a < val ? a = val, 1 : 0;
}
inline unsigned long long isqrt(unsigned long long k) {
  unsigned long long r = sqrt(k) + 1;
  while (r * r > k) r--;
  return r;
}
inline long long icbrt(long long k) {
  long long r = cbrt(k) + 1;
  while (r * r * r > k) r--;
  return r;
}
inline void addmod(int& a, int val, int p = MOD) {
  if ((a = (a + val)) >= p) a -= p;
}
inline void submod(int& a, int val, int p = MOD) {
  if ((a = (a - val)) < 0) a += p;
}
inline int mult(int a, int b, int p = MOD) { return (long long)a * b % p; }
inline int inv(int a, int p = MOD) { return fpow(a, p - 2, p); }
inline int sign(long double x) { return x < -EPS ? -1 : x > +EPS; }
inline int sign(long double x, long double y) { return sign(x - y); }
mt19937 mt(chrono::high_resolution_clock::now().time_since_epoch().count());
inline int myrand() { return abs((int)mt()); }
const int maxn = 1e5 + 5;
const int logn = 20;
int n, m, q;
vector<int> adj[maxn];
int lev[maxn];
int vis[maxn];
int dp[maxn];
int par[logn][maxn];
int tin[maxn];
int tou[maxn];
int tms;
void dfs(int u, int p) {
  vis[u] = 1;
  dp[u] = par[0][u];
  tin[u] = tms++;
  for (int v : adj[u]) {
    if (!vis[v]) {
      lev[v] = lev[u] + 1;
      par[0][v] = u;
      dfs(v, u);
      if (lev[dp[u]] > lev[dp[v]]) {
        dp[u] = dp[v];
      }
    } else if (v != p) {
      if (lev[dp[u]] > lev[v]) {
        dp[u] = v;
      }
    }
  }
  tou[u] = tms - 1;
}
int isanc(int u, int v) { return tin[u] <= tin[v] && tou[u] >= tou[v]; }
int query(int u, int v) {
  int res = 0;
  for (int it = (0); it < (2); ++it) {
    for (int i = (logn)-1; i >= (0); --i) {
      if (!isanc(par[i][u], v)) {
        u = par[i][u];
        res += 1 << i;
      }
    }
    swap(u, v);
  }
  if (u != v) {
    res++;
  }
  if (!isanc(u, v) || !isanc(v, u)) {
    res++;
  }
  return res;
}
void chemthan() {
  cin >> n >> m >> q;
  for (int i = (0); i < (m); ++i) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    adj[u].push_back(v), adj[v].push_back(u);
  }
  dfs(0, -1);
  for (int u = (0); u < (n); ++u) par[0][u] = dp[u];
  for (int i = (1); i < (logn); ++i)
    for (int u = (0); u < (n); ++u) par[i][u] = par[i - 1][par[i - 1][u]];
  while (q--) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    cout << query(u, v) << "\n";
  }
}
int main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0), cin.tie(0);
  if (argc > 1) {
    assert(freopen(argv[1], "r", stdin));
  }
  if (argc > 2) {
    assert(freopen(argv[2], "wb", stdout));
  }
  chemthan();
  cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
  return 0;
}
