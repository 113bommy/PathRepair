#include <bits/stdc++.h>
using namespace std;
const int N = 401;
vector<int> g[N];
int n, k, u, v, id[N][N], dp[N][N], f[N], p[N][N][N], sz[N], vis[N];
void dfs(int u) {
  dp[u][1] = 0;
  dp[u][0] = sz[u] = vis[u] = 1;
  for (int v : g[u])
    if (!vis[v]) {
      f[v] = id[u][v];
      dfs(v);
      sz[u] += sz[v];
      for (int j = sz[u]; j; j--) {
        int tmp = 1e9;
        for (int k = 0; k <= min(j - 1, sz[v]); k++)
          if (tmp > dp[v][k] + dp[u][j - k])
            tmp = dp[v][k] + dp[u][j - k], p[u][v][j] = k;
        dp[u][j] = tmp;
      }
    }
}
void dfs(int u, int k) {
  for (int i = g[u].size() - 1; i >= 0; i--)
    if (id[u][g[u][i]] != f[u]) {
      int v = g[u][i];
      if (p[u][v][k])
        dfs(v, p[u][v][k]);
      else
        cout << id[u][v] << endl, k -= p[u][v][k];
    }
}
int main() {
  cin >> n >> k;
  for (int i = 1; i < n; i++) {
    cin >> u >> v;
    g[u].push_back(v), g[v].push_back(u);
    id[u][v] = id[v][u] = i;
  }
  memset(dp, 60, sizeof dp);
  dfs(1);
  int ans = dp[1][k], rt = 1;
  for (int i = 2; i <= n; i++)
    if (dp[i][k] + 1 < ans) ans = dp[i][k] + 1, rt = i;
  cout << ans << endl;
  if (ans) {
    memset(vis, 0, sizeof vis);
    if (rt != 1) cout << f[rt] << endl;
    dfs(rt, k);
    puts("");
  }
}
