#include <bits/stdc++.h>
using namespace std;
int n, h[5005], dp[5005][5005];
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", &h[i]);
  memset(dp, 63, sizeof dp);
  int INF = dp[0][0];
  for (int j = 0; j < n; j++) dp[0][j] = 0;
  for (int i = 1; i <= n; i++) {
    int k = 1, s = 0;
    while (k <= i) {
      s += h[i - k];
      if (s >= dp[i - k][(n - 1) - (k - 1)]) {
        dp[i][i - 1] = s;
        break;
      }
      k++;
    }
    for (int j = n - 2; j >= 0; j--) {
      while (k <= i) {
        if (j >= k - 1 && s >= dp[i - k][j - (k - 1)]) {
          dp[i][j] = s;
          break;
        }
        k++;
        if (k <= i) s += h[i - k];
      }
    }
  }
  for (int j = 0; j < n; j++)
    if (dp[n][j] != INF) {
      printf("%d\n", j);
      break;
    }
  return 0;
}
