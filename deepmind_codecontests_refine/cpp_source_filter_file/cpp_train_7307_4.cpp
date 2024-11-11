#include <bits/stdc++.h>
const int N = 200;
int n, k, a[N + 1];
class Graph {
 public:
  static const int NODE = N;
  static const int EDGE = N - 1 << 1;
  int ver_[EDGE + 1];
  int head_[NODE + 1], nxt_[EDGE + 1];
  int tot_ = 0;
  inline void addEdge(int u, int v) {
    ver_[++tot_] = v, nxt_[tot_] = head_[u], head_[u] = tot_;
  }
} g;
int dp[N + 1][N + 1];
void dfs(int u, int fa) {
  dp[u][0] = a[u];
  for (int i = g.head_[u]; i; i = g.nxt_[i]) {
    int v = g.ver_[i];
    if (v == fa) continue;
    dfs(v, u);
  }
  for (int i = g.head_[u]; i; i = g.nxt_[i]) {
    int v = g.ver_[i];
    if (v == fa) continue;
    dp[u][0] += dp[v][k - 1];
  }
  for (int t = 1; t <= k; ++t)
    for (int i = g.head_[u]; i; i = g.nxt_[i]) {
      int v = g.ver_[i];
      if (v == fa) continue;
      int cont = dp[v][t - 1];
      for (int j = g.head_[u]; j; j = g.nxt_[j]) {
        int w = g.ver_[j];
        if (w == fa || w == v) continue;
        cont += dp[w][std::max(t - 1, k - t - 1)];
      }
      dp[u][t] = std::max(dp[u][t], cont);
    }
  for (int i = k - 1; ~i; --i) dp[u][i] = std::max(dp[u][i], dp[u][i + 1]);
}
int main() {
  scanf("%d%d", &n, &k);
  ++k;
  for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
  for (int i = 1; i < n; ++i) {
    int u, v;
    scanf("%d%d", &u, &v);
    g.addEdge(u, v);
    g.addEdge(v, u);
  }
  dfs(1, 0);
  printf("%d\n", dp[1][0]);
  return 0;
}
