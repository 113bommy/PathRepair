#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
vector<int> G[N], val[N];
long long mx, mi;
int vis[N], n, dp[N];
void dfs(int u, int fa) {
  dp[u] = 1;
  long long s1 = 0;
  int num = 0;
  for (int i = 0; i < G[u].size(); ++i) {
    int v = G[u][i];
    if (v == fa) continue;
    int w = val[u][i];
    dfs(v, u);
    dp[u] += dp[v];
    mx = (mx + min(dp[v], n - dp[v]) * w);
    if (vis[v] == 0) {
      vis[v] = 1;
      num++;
      s1 += w;
    }
  }
  if (num % 2 == 0)
    mi += s1;
  else
    mi += s1, vis[u] = 1;
}
int main() {
  int _;
  cin >> _;
  while (_--) {
    scanf("%d", &n);
    int m = 2 * n - 1;
    n = 2 * n;
    mx = mi = 0;
    for (int i = 1; i <= n; ++i)
      G[i].clear(), val[i].clear(), vis[i] = 0, dp[i] = 0;
    for (int i = 1; i <= m; ++i) {
      int u, v, w;
      scanf("%d%d%d", &u, &v, &w);
      G[u].push_back(v);
      G[v].push_back(u);
      val[u].push_back(w);
      val[v].push_back(w);
    }
    dfs(1, 0);
    printf("%lld %lld\n", mi, mx);
  }
}
