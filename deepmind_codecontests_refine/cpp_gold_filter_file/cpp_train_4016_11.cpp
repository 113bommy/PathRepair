#include <bits/stdc++.h>
using namespace std;
const int N = 2e3 + 1;
int n, m, w, k, u, v, f[N], adnsduain[N], bs[N], vis[N], dp[N][N], sw[N], sb[N];
vector<int> g[N], gr[N];
void dfs(int u) {
  if (f[u]) return;
  f[u] = k;
  gr[k].push_back(u);
  sw[k] += adnsduain[u];
  sb[k] += bs[u];
  for (int v : g[u]) dfs(v);
}
int main() {
  scanf("%d%d%d", &n, &m, &w);
  for (int i = 1; i <= n; ++i) scanf("%d", adnsduain + i);
  for (int i = 1; i <= n; ++i) scanf("%d", bs + i);
  for (int i = 1; i <= m; ++i) {
    scanf("%d%d", &u, &v);
    g[u].push_back(v);
    g[v].push_back(u);
  }
  for (int i = 1; i <= n; ++i)
    if (!f[i]) ++k, dfs(i);
  for (int i = 1; i <= k; ++i) {
    for (int j = 0; j <= w; ++j) {
      dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
      if (j + sw[i] < N)
        dp[i + 1][j + sw[i]] = max(dp[i + 1][j + sw[i]], dp[i][j] + sb[i]);
      for (int l : gr[i])
        if (j + adnsduain[l] < N)
          dp[i + 1][j + adnsduain[l]] =
              max(dp[i + 1][j + adnsduain[l]], dp[i][j] + bs[l]);
    }
  }
  printf("%d\n", dp[k + 1][w]);
  return 0;
}
