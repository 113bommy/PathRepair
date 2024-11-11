#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e3 + 10;
int n;
int sz[maxn][maxn];
int pai[maxn][maxn];
int dp[maxn][maxn];
vector<int> grafo[maxn];
void dfs(int u, int p, int root) {
  sz[root][u] = 1;
  for (auto v : grafo[u]) {
    if (v == p) continue;
    pai[root][v] = u;
    dfs(v, u, root);
    sz[root][u] += sz[root][v];
  }
}
long long solve(int u, int v) {
  if (u == v) return 0;
  if (dp[u][v] != -1) return dp[u][v];
  return dp[u][v] = 1ll * sz[u][v] * sz[v][u] +
                    max(solve(pai[v][u], v), solve(u, pai[u][v]));
}
int main(void) {
  scanf("%d", &n);
  for (int i = 1; i < n; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    grafo[u].push_back(v);
    grafo[v].push_back(u);
  }
  for (int i = 1; i <= n; i++) dfs(i, 0, i);
  long long ans = 0;
  memset(dp, -1, sizeof dp);
  for (int u = 1; u <= n; u++)
    for (int v = 1; v <= n; v++) ans = max(ans, solve(u, v));
  printf("%lld\n", ans);
}
