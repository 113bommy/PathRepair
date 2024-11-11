#include <bits/stdc++.h>
using namespace std;
int par[200002], dp[200002][32], level[200002], p[200002];
void upd(int n) {
  int j;
  dp[n][0] = par[n];
  for (j = 1; j <= 30; j++) dp[n][j] = -1;
  for (j = 1; j <= 30; j++) {
    if (dp[n][j - 1] != -1) dp[n][j] = dp[dp[n][j - 1]][j - 1];
  }
}
int lca(int u, int v) {
  if (level[v] > level[u]) swap(u, v);
  int x;
  while (level[u] > level[v]) {
    x = log2(level[u] - level[v]);
    u = dp[u][x];
  }
  if (u == v) return u;
  for (int i = log2(level[u]); i >= 0; i--) {
    if (dp[u][i] != -1 && dp[u][i] != dp[v][i]) {
      u = dp[u][i];
      v = dp[v][i];
    }
  }
  return par[u];
}
int dist(int u, int v) {
  int uv = lca(u, v);
  return level[u] + level[v] - 2 * level[uv];
}
int main() {
  int n, i, x, y, x1, x2, x3;
  cin >> n;
  for (i = 2; i <= n; i++) cin >> p[i];
  level[1] = 1;
  par[1] = -1;
  upd(1);
  level[2] = 2;
  par[2] = 1;
  x = 1, y = 2;
  upd(2);
  cout << 1 << " ";
  for (i = 3; i <= n; i++) {
    par[i] = p[i];
    level[i] = level[p[i]] + 1;
    upd(i);
    x1 = dist(x, y);
    x2 = dist(x, i);
    x3 = dist(i, y);
    if (x1 >= x2 && x1 >= x3) {
      cout << x1 << " ";
    } else if (x2 >= x1 && x2 >= x3) {
      cout << x2 << " ";
      y = i;
    } else if (x3 >= x1 && x3 >= x2) {
      cout << x3 << " ";
      x = i;
    }
  }
  return 0;
}
