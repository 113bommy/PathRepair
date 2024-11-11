#include <bits/stdc++.h>
using namespace std;
const long long inf = 0x3f3f3f3f3f3f3f3f;
long long dp[200005], val[200005];
const int maxn = 400005;
int tot;
int n;
vector<int> edge[maxn];
long long ans;
void dfs(int u, int fa) {
  for (int i = 0; i < edge[u].size(); i++) {
    int v = edge[u][i];
    if (v == fa) continue;
    dfs(v, u);
    val[u] += val[v];
    if (dp[u] != -inf) ans = max(ans, dp[v] + dp[u]);
    dp[u] = max(dp[u], dp[v]);
  }
  dp[u] = max(dp[u], val[u]);
}
int main() {
  while (~scanf("%d", &n)) {
    ans = -inf;
    for (int i = 0; i <= n; i++) {
      edge[i].clear();
      dp[i] = -inf;
    }
    for (int i = 1; i <= n; i++) {
      scanf("%I64d", &val[i]);
    }
    for (int i = 1; i < n; i++) {
      int u, v;
      scanf("%d%d", &u, &v);
      edge[u].push_back(v);
      edge[v].push_back(u);
    }
    dfs(1, -1);
    if (ans != -inf)
      printf("%I64d\n", ans);
    else
      printf("Impossible\n");
  }
  return 0;
}
