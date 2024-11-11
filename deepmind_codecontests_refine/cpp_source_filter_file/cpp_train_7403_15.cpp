#include <bits/stdc++.h>
using namespace std;
int t, n, m, k, c[27], dp[27][20005];
int main() {
  scanf("%d", &t);
  dp[0][0] = 1;
  while (t--) {
    memset(c, 0, sizeof c);
    scanf("%d%d%d", &n, &m, &k);
    getchar();
    for (int i = 0; i < k; ++i) ++c[getchar() - 'A' + 1];
    int ans = 1e9;
    for (int i = 1; i <= 26; ++i) {
      for (int j = i; j <= 26; ++j) {
        for (int s = 0; s <= k; ++s) {
          dp[j][s] = dp[j - 1][s];
          if (s >= c[j] && i != j) dp[j][s] |= dp[j - 1][s - c[j]];
        }
      }
      for (int a = 1; a < c[i] && a <= n; ++a) {
        if (dp[26][n - a]) {
          int b = min(0, m - (k - (n - a) - c[i]));
          ans = min(ans, a * b);
        }
      }
      for (int s = c[i]; s <= k; ++s) {
        dp[i][s] |= dp[i - 1][s - c[i]];
      }
    }
    for (int s = n; s <= k - m; ++s) {
      if (dp[26][s]) {
        ans = 0;
        break;
      }
    }
    printf("%d\n", ans);
  }
}
