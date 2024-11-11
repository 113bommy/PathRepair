#include <bits/stdc++.h>
using namespace std;
const int N = 350;
const int Mod = 1e9 + 7;
int dp[2][N][N];
void add(int &x, int y) {
  x += y;
  if (x >= Mod) x -= Mod;
}
int n, m, x;
int main() {
  scanf("%d%d%d", &m, &n, &x);
  if (m > n) {
    puts("0");
    return 0;
  }
  int i = 0;
  dp[0][0][0] = 1;
  for (int u = 1; u <= n; u++) {
    for (int j = 0; j <= m; j++)
      for (int k = 0; k <= j; k++) {
        int &val = dp[i][j][k];
        if (!val) continue;
        if (j < m) {
          add(dp[i ^ 1][j + 1][k + 1], val);
          add(dp[i ^ 1][j + 1][k], val);
        }
        if (u ^ x) {
          if (k < j) add(dp[i ^ 1][j][k + 1], val);
          add(dp[i ^ 1][j][k], val);
        }
        val = 0;
      }
    i ^= 1;
  }
  int ans = dp[i][m][m];
  for (int s = 1; s <= m; s++) ans = 1ll * s * ans % Mod;
  printf("%d\n", ans);
  return 0;
}
