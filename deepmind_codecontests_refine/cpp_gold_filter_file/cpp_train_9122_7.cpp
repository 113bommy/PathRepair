#include <bits/stdc++.h>
using namespace std;
int adj[102][102];
int n, m, dp[102][102][27][2];
int rec(int i, int j, int c, int prev) {
  int &ret = dp[i][j][c][prev];
  if (ret != -1) return ret;
  ret = 0;
  if (prev == 0) {
    for (int v = 1; v <= n; v++) {
      if (adj[i][v] >= c) {
        ret = max(ret, 1 - rec(v, j, adj[i][v], 1));
      }
    }
  } else {
    for (int v = 1; v <= n; v++) {
      if (adj[j][v] >= c) {
        ret = max(ret, 1 - rec(i, v, adj[j][v], 0));
      }
    }
  }
  return ret;
}
int main() {
  memset(dp, -1, sizeof dp);
  memset(adj, -1, sizeof adj);
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    int u, v;
    char c;
    cin >> u >> v >> c;
    int ch = (c - 'a') + 1;
    adj[u][v] = ch;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (rec(i, j, 0, 0) == 1) {
        cout << 'A';
      } else {
        cout << 'B';
      }
    }
    cout << "\n";
  }
  return 0;
}
