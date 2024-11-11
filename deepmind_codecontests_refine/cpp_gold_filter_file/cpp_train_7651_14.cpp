#include <bits/stdc++.h>
using namespace std;
int dp[35][35][55];
int t, n, m, k;
int main() {
  scanf("%d", &t);
  dp[1][1][1] = 0;
  dp[1][1][0] = 0;
  for (int i = 1; i <= 31; i++) {
    for (int j = 1; j <= 31; j++) {
      if (i == 1 && j == 1) continue;
      int op = min(i * j, 52);
      for (int k = 1; k < op; k++) {
        dp[i][j][k] = 100000000;
        for (int s = 1; s <= (i / 2) + 1 && i - s >= 0; s++) {
          for (int q = 0; q <= s * j && q <= k; q++) {
            if ((k - q) > (i - s) * j) continue;
            dp[i][j][k] =
                min(dp[i][j][k], dp[i - s][j][k - q] + dp[s][j][q] + j * j);
          }
        }
        for (int s = 1; s <= (j / 2) + 1 && j - s >= 0; s++) {
          for (int q = 0; q <= i * s && q <= k; q++) {
            if (k - q > i * (j - s)) continue;
            dp[i][j][k] =
                min(dp[i][j][k], dp[i][j - s][k - q] + dp[i][s][q] + i * i);
          }
        }
      }
    }
  }
  while (t--) {
    scanf("%d", &n), scanf("%d", &m), scanf("%d", &k);
    printf("%d\n", dp[n][m][k]);
  }
  return 0;
}
