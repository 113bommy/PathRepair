#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
int n, m, dp[250][1 << 15][2][2];
char g[250][251];
int calc(int r, int c, int left, int up, int emp) {
  if (r == n) {
    for (int i = 0; i < 15; i++)
      if (c + 1 < m && (left & (1 << i)) && g[i][c + 1] == 'x')
        left &= ~(1 << i);
    return calc(0, c + 1, left, 0, emp);
  }
  if (c == m) return 1;
  int &ret = dp[r * m + c][left][up][emp];
  if (ret != -1) return ret;
  ret = 0;
  if (g[r][c] == 'x') {
    ret = calc(r + 1, c, left, 0, emp);
  } else {
    if (up || (left & (1 << r)))
      ret = (ret + calc(r + 1, c, left, up, emp)) % MOD;
    else if (!emp)
      ret = (ret + calc(r + 1, c, left, up, 1)) % MOD;
    ret = (ret + calc(r + 1, c, left | (1 << r), 1, emp)) % MOD;
  }
  return ret;
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++) scanf("%s", g[i]);
  if (n > m) {
    char tmp[250][251];
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++) tmp[j][i] = g[i][j];
    swap(n, m);
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++) g[i][j] = tmp[i][j];
  }
  memset(dp, -1, sizeof(dp));
  printf("%d\n", calc(0, 0, 0, 0, 0));
  return 0;
}
