#include <bits/stdc++.h>
using namespace std;
int ans = 1e8;
int from, to, cost;
int n, k, m;
int left, right;
int D[81][81][81][81];
vector<vector<int> > g;
void read() {
  for (int i = 0; i < 81; i++)
    for (int j = 0; j < 81; j++)
      for (int l = 0; l < 81; l++)
        for (int k = 0; k < 81; k++) D[i][j][l][k] = 0;
  cin >> n >> k;
  cin >> m;
  g.resize(81, vector<int>(81, 0));
  for (int i = 0; i < m; i++) {
    cin >> from >> to >> cost;
    if (from != to) {
      if (g[from][to] == 0)
        g[from][to] = cost;
      else if (cost < g[from][to])
        g[from][to] = cost;
    }
  }
}
void DP(int v, int tl, int tr, int cur, int cash) {
  if (cur == k) {
    if (cash < ans) ans = cash;
  }
  if (tl > tr) return;
  if (D[v][tl][tr][cur] != 0) {
    if (cash < D[v][tl][tr][cur])
      D[v][tl][tr][cur] = cash;
    else
      return;
  } else
    D[v][tl][tr][cur] = cash;
  for (int i = tl; i <= tr; i++) {
    if (g[v][i] != 0) {
      DP(i, tl, i - 1, cur + 1, cash + g[v][i]);
      DP(i, i + 1, tr, cur + 1, cash + g[v][i]);
    }
  }
}
int main() {
  read();
  for (int i = 1; i <= n; i++) {
    DP(i, 1, i - 1, 1, 0);
    DP(i, i + 1, n, 1, 0);
  }
  if (ans == 1e8)
    cout << -1;
  else
    cout << ans;
  return 0;
}
