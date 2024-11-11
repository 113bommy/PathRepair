#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
int const N = 5e5 + 20, mod = 998244353;
int n, dp[N][2], ans, sz[N], pw[N];
vector<int> g[N];
inline void add(int &a, int b) {
  a += b;
  if (a >= mod) a -= mod;
}
void dfs(int v, int par = -1) {
  sz[v] = 1;
  int d0 = 1, d1 = 0;
  for (int u : g[v]) {
    if (u == par) continue;
    dfs(u, v);
    sz[v] += sz[u];
    add(dp[u][1], dp[u][1]);
    add(dp[u][1], dp[u][0]);
    d1 = (1ll * d0 * dp[u][0] + 1ll * d1 * (dp[u][0] + dp[u][1])) % mod;
    d0 = 1ll * d0 * dp[u][1] % mod;
  }
  dp[v][0] = d0, dp[v][1] = d1;
  add(ans, pw[n - sz[v] + 1] * d1 % mod);
}
int32_t main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  pw[0] = 1;
  for (int i = 1; i < N; i++) pw[i] = 2 * pw[i - 1] % mod;
  cin >> n;
  for (int i = 0, u, v; i < n - 1; i++) {
    cin >> u >> v;
    u--, v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  dfs(0);
  cout << ans << '\n';
}
