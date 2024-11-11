#include <bits/stdc++.h>
using namespace std;
bool vis[100000 + 3];
int dpth[100000 + 2], n, pa[100000 + 2], dp[100000 + 2], rmq[50][100000 + 2];
vector<int> G[100000 + 2];
void dfs(int u) {
  vis[u] = 1;
  dp[u] = 1;
  for (int i = 0; i < G[u].size(); i++) {
    int v = G[u][i];
    if (!vis[v]) {
      dpth[v] = dpth[u] + 1;
      pa[v] = u;
      dfs(v);
      dp[u] += dp[v];
    }
  }
}
void RMQ() {
  memset(rmq, -1, sizeof(rmq));
  for (int i = 0; i < n; i++) rmq[0][i] = pa[i];
  for (int k = 1; k <= 21; k++)
    for (int i = 1; i < n; i++) rmq[k][i] = rmq[k - 1][rmq[k - 1][i]];
}
int lca(int a, int b) {
  if (dpth[a] > dpth[b]) swap(a, b);
  int dist = dpth[b] - dpth[a];
  for (int i = 0; i < 21; i++)
    if (dist & (1 << i)) b = rmq[i][b];
  if (a == b) return a;
  for (int i = 21; i >= 0; i--) {
    if (rmq[i][a] != rmq[i][b]) a = rmq[i][a], b = rmq[i][b];
  }
  return pa[a];
}
int padre(int x, int dist) {
  int b = x;
  for (int i = 0; i < 21; i++)
    if (dist & (1 << i)) b = rmq[i][b];
  return b;
}
int res(int x, int y) {
  int z = lca(x, y);
  if (x == y) return n;
  int dist = dpth[x] - dpth[z] + dpth[y] - dpth[z] + 1;
  if (dist & 1) {
    if (dpth[x] == dpth[y]) {
      int x1 = padre(x, dist / 2 - 1), x2 = padre(y, dist / 2 - 1);
      return n - dp[x1] - dp[x2];
    } else {
      if (dpth[x] < dpth[y]) swap(x, y);
      int x1 = padre(x, dist / 2), x2 = padre(x, dist / 2 - 1);
      return dp[x1] - dp[x2];
    }
  } else {
    return 0;
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin >> n;
  for (int i = 0; i < n - 1; i++) {
    int x, y;
    cin >> x >> y;
    x--, y--;
    G[x].push_back(y);
    G[y].push_back(x);
  }
  dfs(0);
  RMQ();
  int q;
  cin >> q;
  for (int i = 0; i < q; i++) {
    int x, y;
    cin >> x >> y;
    x--, y--;
    cout << res(x, y) << endl;
  }
}
