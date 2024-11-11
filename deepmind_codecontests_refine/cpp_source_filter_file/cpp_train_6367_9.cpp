#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
const int mod = 1e9 + 7;
int dp[N][20][2];
int pow2[20];
int n;
int f(int x, int y) { return n / (pow2[x] * (y ? 3 : 1)); }
int main() {
  scanf("%d", &n);
  int x = 0;
  while (1 << x + 1 < n) x++;
  pow2[0] = 1;
  for (int i = 1; i <= x; i++) pow2[i] = pow2[i - 1] * 2;
  dp[1][x][0] = 1;
  if ((1 << x - 1) * 3 <= n) {
    dp[1][x - 1][1] = 1;
  }
  for (int i = 1; i < n; i++) {
    for (int j = 0; j <= x; j++) {
      for (int k = 0; k < 2; k++) {
        dp[i + 1][j][k] =
            (dp[i + 1][j][k] + 1ll * dp[i][j][k] * (f(j, k) - i) % mod) % mod;
      }
    }
    for (int j = 1; j <= x; j++) {
      for (int k = 0; k < 2; k++) {
        dp[i + 1][j - 1][k] =
            (dp[i + 1][j - 1][k] +
             1ll * dp[i][j][k] * (f(j - 1, k) - f(j, k)) % mod) %
            mod;
      }
    }
    for (int j = 0; j <= x; j++) {
      dp[i + 1][j][0] =
          (dp[i + 1][j][0] + 1ll * dp[i][j][1] * (f(j, 0) - f(j, 1)) % mod) %
          mod;
    }
  }
  printf("%d\n", dp[n][0][0]);
  return 0;
}
