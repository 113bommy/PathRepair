#include <bits/stdc++.h>
using namespace std;
int a[505], dp[505][505];
int len;
int main() {
  int n;
  int i, j, k;
  scanf("%d", &n);
  for (i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
  }
  memset(dp, 0, sizeof(dp));
  for (len = 1; len <= n; len++) {
    for (i = 1, j = i + len - 1; j <= n; i++, j++) {
      if (len == 1)
        dp[i][j] = 1;
      else {
        dp[i][j] = 1 + dp[i + 1][j];
        if (a[i] == a[i + 1]) dp[i][j] = min(dp[i + 2][j] + 1, dp[i][j]);
        for (k = 2; i + k <= j; k++) {
          if (a[i] == a[i + k]) {
            dp[i][j] = min(dp[i + 1][k - 1] + dp[k + 1][j], dp[i][j]);
          }
        }
      }
    }
  }
  printf("%d\n", dp[1][n]);
}
