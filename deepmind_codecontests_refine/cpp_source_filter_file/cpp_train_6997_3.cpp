#include <bits/stdc++.h>
using namespace std;
const int maxn = 3100;
struct edge {
  int v, next;
};
edge g[maxn << 1];
int head[maxn];
int p[maxn][maxn], siz[maxn][maxn];
long long dp[maxn][maxn];
void insert(int u, int v) {
  static int id;
  g[++id].v = v;
  g[id].next = head[u];
  head[u] = id;
}
void dfs(int root, int u) {
  siz[root][u] = 1;
  for (int i = head[u]; i; i = g[i].next) {
    int v = g[i].v;
    if (v != p[root][u]) {
      p[root][v] = u;
      dfs(root, v);
      siz[root][u] += siz[root][v];
    }
  }
}
int solve(int u, int v) {
  if (u == v) return 0;
  if (dp[u][v] != -1) return dp[u][v];
  dp[u][v] = (long long)siz[v][u] * siz[u][v] +
             max(solve(p[v][u], v), solve(p[u][v], u));
  return dp[u][v];
}
int main() {
  int n;
  cin >> n;
  memset(dp, -1, sizeof dp);
  for (int i = 1; i <= n - 1; i++) {
    int x, y;
    cin >> x >> y;
    insert(x, y);
    insert(y, x);
  }
  for (int i = 1; i <= n; i++) dfs(i, i);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) solve(i, j);
  }
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) ans = max(ans, dp[i][j]);
  }
  cout << ans << endl;
  return 0;
}
