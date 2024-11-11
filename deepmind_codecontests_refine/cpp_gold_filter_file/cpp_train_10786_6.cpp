#include <bits/stdc++.h>
const long long inf = 1e9;
const double eps = 1e-9;
const long long infll = 1e18;
const long long mod = 1e9 + 7;
const long long N = 1001;
using namespace std;
vector<vector<long long> > g, gi, gt;
vector<vector<long long> > dp;
vector<long long> a, b;
vector<long long> u, d;
inline long long safe_add(long long a, long long b) {
  if (a + b >= mod) return a + b - mod;
  return a + b;
}
long long inv(long long a, long long m) {
  m -= 2;
  long long ans = 1;
  while (m) {
    if (m & 1) ans = (ans * a) % mod;
    a = (a * a) % mod;
    m /= 2;
  }
  return ans;
}
void ddf(long long v = 0) {
  for (long long i = 0; i < g[v].size(); i++) {
    if (d[g[v][i]] == -1) {
      d[g[v][i]] = d[v] + 1;
      ddf(g[v][i]);
    }
  }
}
inline void dfs(long long v) {
  u[v] = 1;
  a[v] = 1;
  b[v] = 1;
  bool ch = true;
  long long aa = -1, bb = -1;
  for (long long i = 0; i < g[v].size(); i++) {
    if (u[g[v][i]] == 0) {
      gi[g[v][i]].push_back(v);
      gt[v].push_back(g[v][i]);
      ch = false;
      dfs(g[v][i]);
      if (aa == -1) aa = 1;
      aa = (aa * a[g[v][i]]) % mod;
      if (bb == -1) bb = 1;
      bb = (bb * b[g[v][i]]) % mod;
    }
  }
  if (bb == -1)
    a[v] = max(aa, 1ll);
  else
    a[v] = safe_add(aa, bb);
  if (aa == -1)
    b[v] = max(bb, 1ll);
  else
    b[v] = safe_add(aa, bb);
  if (aa == -1) aa = 1;
  if (bb == -1) bb = 1;
  dp[v][0] = aa;
  dp[v][1] = bb;
}
inline void dfsinv(long long v) {
  u[v] = 1;
  bool ch = true;
  for (long long i = 0; i < gi[v].size(); i++) {
    if (u[gi[v][i]] == 0) {
      dfsinv(gi[v][i]);
    }
    long long aa = 1, bb = 1;
    for (long long j = 0; j < gt[v].size(); j++) {
      aa = (aa * a[gt[v][j]]) % mod;
      bb = (bb * b[gt[v][j]]) % mod;
    }
    long long qweq = inv(a[v], mod);
    long long sa = (dp[gi[v][i]][0] * inv(a[v], mod) + mod) % mod,
              sb = (dp[gi[v][i]][1] * inv(b[v], mod) + mod) % mod;
    long long saa;
    if (g[gi[v][i]].size() == 1) {
      saa = 1;
    } else
      saa = (sa + sb + mod) % mod;
    aa = (aa * saa) % mod;
    bb = (bb * saa) % mod;
    a[v] = safe_add(aa, bb);
    b[v] = safe_add(aa, bb);
    dp[v][0] = (aa) % mod;
    dp[v][1] = (bb) % mod;
  }
}
void solve() {
  long long n;
  cin >> n;
  g.resize(n);
  gi.resize(n);
  dp.assign(n, vector<long long>(2, 0));
  d.assign(n, -1);
  u.resize(n, 0);
  a.resize(n);
  b.resize(n);
  gt.resize(n);
  for (long long i = 0; i < n - 1; i++) {
    long long a, b;
    cin >> a >> b;
    a--;
    b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  ddf();
  long long v = 0;
  for (long long i = 0; i < n; i++) {
    if (d[i] > d[v]) v = i;
  }
  dfs(v);
  long long ans = 0;
  u.assign(n, 0);
  for (long long i = 0; i < n; i++) {
    if (u[i] == 0) {
      dfsinv(i);
    }
  }
  for (long long i = 0; i < n; i++) ans = (ans + a[i]) % mod;
  cout << ans << endl;
  return;
}
bool check(long long v, long long mask, long long mood = 1) {
  u[v] = 1;
  bool ch = 0;
  for (long long i = 0; i < g[v].size(); i++) {
    if (u[g[v][i]] == 0) {
      ch = 1;
      long long nv = g[v][i];
      bool qnv = (1 << nv) & mask;
      if (!check(g[v][i], mask, mood ^ qnv)) {
        return false;
      }
    }
  }
  if (ch == 0) return mood;
  return true;
}
void solve1() {
  long long n;
  cin >> n;
  g.resize(n);
  gi.resize(n);
  dp.assign(n, vector<long long>(2, 0));
  u.resize(n, 0);
  a.resize(n);
  b.resize(n);
  gt.resize(n);
  for (long long i = 0; i < n - 1; i++) {
    long long a, b;
    cin >> a >> b;
    a--;
    b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  long long ans = 0;
  for (long long i = 0; i < 1 << n; i++) {
    for (long long j = 0; j < n; j++) {
      u.assign(n, 0);
      if (check(j, i)) {
        ans++;
        cout << j << ' ';
        for (long long q = 0; q < n; q++) cout << (bool)((1 << q) & i) << ' ';
        cout << endl;
      }
    }
  }
  cout << ans << endl;
  return;
}
int main() {
  solve();
  return 0;
}
