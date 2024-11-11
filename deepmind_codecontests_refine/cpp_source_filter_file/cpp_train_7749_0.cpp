#include <bits/stdc++.h>
using namespace std;
const int N = 405;
int INF = 0x7f7f7f7f;
int dp[N][N], path[N][N][N], f[N], id[N][N];
int n, k, m;
struct Edge {
  int from, to;
  Edge(int u, int v) : from(u), to(v) {}
};
vector<Edge> edges;
vector<int> G[N];
void dfs(int u, int fa) {
  dp[u][1] = 0;
  f[u] = fa;
  if (fa != -1 && G[u].size() == 1) return;
  for (int i = 0; i <= (int)G[u].size() - 1; i++) {
    Edge& e = edges[G[u][i]];
    if (e.to == fa) continue;
    int v = e.to;
    dfs(v, u);
    for (int j = k; j >= 1; j--) {
      dp[u][j]++;
      path[u][v][j] = 0;
      for (int l = 1; l <= j - 1; l++) {
        if (dp[u][j] > dp[u][l] + dp[v][j - l] && dp[u][l] != INF &&
            dp[v][j - l] != INF) {
          dp[u][j] = dp[u][l] + dp[v][j - l];
          path[u][v][j] = j - l;
        }
      }
    }
  }
}
void out(int u, int fa, int m) {
  for (int i = (int)G[u].size() - 1; i >= 0; i--) {
    Edge& e = edges[G[u][i]];
    int v = e.to;
    if (v == fa) continue;
    if (path[u][v][m] == 0)
      printf("%d\n", id[u][v]);
    else {
      out(v, u, path[u][v][m]);
      m -= path[u][v][m];
    }
  }
}
int main() {
  scanf("%d%d", &n, &k);
  if (n == k) {
    printf("0");
    return 0;
  }
  m = 0;
  edges.clear();
  for (int i = 1; i <= n; i++) G[i].clear();
  for (int i = 1; i <= n - 1; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    edges.push_back(Edge(u, v));
    edges.push_back(Edge(v, u));
    m += 2;
    G[u].push_back(m - 2);
    G[v].push_back(m - 1);
    id[u][v] = id[v][u] = i;
  }
  memset(dp, 0x7f, sizeof(dp));
  dfs(1, -1);
  int ans = dp[1][k], p = 1;
  for (int i = 2; i <= n; i++)
    if (ans > dp[i][k] + 1) ans = dp[i][k] + 1, p = i;
  printf("%d\n", ans);
  if (p != 1) {
    printf("%d\n", id[p][f[p]]);
  }
  out(p, f[p], k);
  return 0;
}
