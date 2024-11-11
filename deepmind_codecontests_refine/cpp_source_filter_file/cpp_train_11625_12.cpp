#include <bits/stdc++.h>
using namespace std;
const int mod1 = 1e9 + 7, mod2 = 998244353, maxn = 3e5 + 5, maxlog = 20, K = 26;
const long long infll = 1e18;
const double pi = acos(-1);
int n, h[maxn], f[maxn][20], g[maxn][20];
long long res = 0;
vector<int> gr[maxn];
void dfs(int u, int pa) {
  for (auto v : gr[u]) {
    if (v != pa) {
      dfs(v, u);
      h[u] = max(h[u], h[v] + 1);
    }
  }
  f[u][1] = g[u][1] = n;
  for (long long dep = 2; dep <= 19; ++dep) {
    int lo = 0, hi = n;
    while (lo < hi) {
      int mid = (lo + hi + 1) >> 1;
      int cnt = 0;
      for (auto v : gr[u]) {
        if (v != pa) {
          if (g[v][dep - 1] >= mid) {
            cnt++;
          }
        }
      }
      if (cnt >= mid)
        lo = mid;
      else
        hi = mid - 1;
    }
    g[u][dep] = lo;
    for (auto v : gr[u]) {
      if (v != pa) f[u][dep] = max(f[u][dep], f[v][dep]);
    }
    f[u][dep] = max(f[u][dep], g[u][dep]);
  }
}
void solve() {
  cin >> n;
  for (long long i = 1; i < n; ++i) {
    int u, v;
    cin >> u >> v;
    gr[u].push_back(v);
    gr[v].push_back(u);
  }
  dfs(1, 0);
  for (long long u = 1; u <= n; ++u) {
    res += h[u];
  }
  for (long long u = 1; u <= n; ++u) {
    for (long long dep = 1; dep <= 19; ++dep) {
      int lo = 2;
      if (dep < 19) lo = max(lo, f[u][dep + 1]);
      int hi = f[u][dep];
      if (lo <= hi) {
        res += 1ll * (hi - lo + 1) * (dep - 1);
      }
    }
  }
  res += 1ll * n * n;
  cout << res;
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solve();
}
