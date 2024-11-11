#include <bits/stdc++.h>
int a[710], n;
bool dp[710][710][2];
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%d", a + i);
  for (int i = 1; i <= n - 1; ++i) {
    if (gcd(a[i], a[i + 1]) > 1) dp[i][i][1] = dp[i + 1][i + 1][0] = true;
  }
  for (int l = 3; l <= n; ++l) {
    for (int i = 1; i <= n - l + 1; ++i) {
      int j = i + l - 1;
      if (i >= 2) {
        if (dp[i + 1][j][0] && gcd(a[i - 1], a[i]) > 1) dp[i][j][0] = true;
        for (int k = i + 1; !dp[i][j][0] && k < j; ++k) {
          if (dp[i][k - 1][1] && dp[k + 1][j][0] && gcd(a[i - 1], a[k]) > 1)
            dp[i][j][0] = true;
        }
        if (dp[i][j - 1][1] && gcd(a[i - 1], a[j]) > 1) dp[i][j][0] = true;
      }
      if (j < n) {
        if (dp[i + 1][j][0] && gcd(a[i], a[j + 1]) > 1) dp[i][j][1] = true;
        for (int k = i + 1; !dp[i][j][1] && k < j; ++k) {
          if (dp[i][k - 1][1] && dp[k + 1][j][0] && gcd(a[k], a[j + 1]) > 1)
            dp[i][j][1] = true;
        }
        if (dp[i][j - 1][1] && gcd(a[i], a[j + 1]) > 1) dp[i][j][1] = true;
      }
    }
  }
  bool valid = false;
  for (int i = 1; i <= n; ++i)
    if (dp[1][i - 1][1] && dp[i + 1][n][0]) valid = true;
  if (n >= 2 && (dp[1][n - 1][1] || dp[2][n][0])) valid = true;
  puts(valid ? "Yes" : "No");
  return 0;
}
