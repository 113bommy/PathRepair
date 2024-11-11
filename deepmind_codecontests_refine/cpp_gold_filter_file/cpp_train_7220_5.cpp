#include <bits/stdc++.h>
using namespace std;
const int MOD = (int)1e9 + 7;
const int FFTMOD = 1007681537;
const int INF = (int)1e9;
const long long LINF = (long long)1e18;
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
inline long long isqrt(long long k) {
  long long r = sqrt(k) + 1;
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
const int maxn = 3000 + 5;
int n;
vector<pair<int, int> > adj[maxn];
int tot;
int f[maxn];
int dp[maxn][2];
void dfs(int u, int p) {
  for (int i = (0); i < (int((adj[u]).size())); i++) {
    int v = adj[u][i].first;
    int w = adj[u][i].second;
    if (v != p) {
      tot += w;
      dp[v][0] = dp[u][0] + w;
      dp[v][1] = min(dp[u][0], dp[u][1]) + 1 - w;
      f[v] = f[u] + w;
      dfs(v, u);
    }
  }
}
void solve() {
  cin >> n;
  for (int i = (0); i < (n - 1); i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    adj[u].push_back(make_pair(v, 0));
    adj[v].push_back(make_pair(u, 1));
  }
  int ans = INF;
  for (int u = (0); u < (n); u++) {
    fill_n(f, n, 0);
    tot = f[u] = dp[u][0] = dp[u][1] = 0, dfs(u, -1);
    for (int v = (0); v < (n); v++) {
      chkmin(ans, tot - f[v] + min(dp[v][0], dp[v][1]));
    }
  }
  cout << ans << "\n";
}
int main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0), cin.tie(0);
  int JUDGE_ONLINE = 1;
  if (argc > 1) {
    JUDGE_ONLINE = 0;
    assert(freopen(argv[1], "r", stdin));
  }
  if (argc > 2) {
    JUDGE_ONLINE = 0;
    assert(freopen(argv[2], "w", stdout));
  }
  solve();
  if (!JUDGE_ONLINE) {
    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
  }
  return 0;
}
