#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
int n, m, k;
int ans = 0;
int used[22];
int g[22][22], a[22][22], f[22][22];
int Log2[1 << 20];
int dfs(int x, int y) {
  if (y == m + 1) {
    x++;
    y = 1;
  }
  if (x == n + 1) {
    return 1;
  }
  int cc = (f[x - 1][y] | f[x][y - 1]);
  int sa = -1, p = 0;
  for (int i = (~cc) & ((1 << k) - 1); i != 0; i -= (i & (-i))) {
    int t = Log2[i & (-i)] + 1;
    if (g[x][y] == 0 || g[x][y] == t) {
      f[x][y] = cc | (1 << (t - 1));
      used[t]++;
      if (used[t] == 1) {
        if (sa == -1) {
          sa = dfs(x, y + 1);
        }
        p += sa;
      } else if (used[t]) {
        p += dfs(x, y + 1);
      }
      if (p >= MOD) p -= MOD;
      used[t]--;
    }
  }
  return p;
}
int main() {
  cin >> n >> m >> k;
  if (n + m - 1 > k) {
    cout << 0 << endl;
    return 0;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> g[i][j];
      used[g[i][j]]++;
    }
  }
  for (int i = 1; i <= k; i++) {
    Log2[1 << i] = i;
  }
  cout << dfs(1, 1) << endl;
  return 0;
}
