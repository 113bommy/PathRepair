#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int dp[5010][5010];
int ok[5010][5010];
char str[5010];
int a[5010];
int main() {
  int n;
  scanf("%d", &n);
  scanf("%s", str);
  for (int i = 0; i < n; i++) a[i] = str[i] - '0';
  a[n] = -1;
  for (int i = 1; i < n; i++) dp[0][i] = 1;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) ok[i][j] = -1;
  for (int i = n - 1; i >= 0; i--) {
    for (int j = n - 1; j >= i + 1; j--) {
      if (a[i] != a[j])
        ok[i][j] = i;
      else if (a[i] == a[j]) {
        if (j + 1 < n && ok[i + 1][j + 1] != -1 && ok[i + 1][j + 1] < j)
          ok[i][j] = ok[i + 1][j + 1];
      }
    }
  }
  for (int i = 1; i < n; i++) {
    for (int j = 1; j <= i; j++) {
      int p2 = i - j + 1, p1 = i - 2 * j + 1;
      if (a[p2] == 0) {
        dp[i][j] = dp[i][j - 1];
        continue;
      }
      if (p1 < 0) {
        dp[i][j] = (dp[i][j - 1] + dp[i - j][i - j + 1]) % mod;
        continue;
      }
      if (ok[p1][p2] == -1) {
        dp[i][j] = (dp[i][j - 1] + dp[i - j][j - 1]) % mod;
      } else {
        int np1 = ok[p1][p2], np2 = np1 - p1 + p2;
        if (a[np1] > a[np2]) {
          dp[i][j] = (dp[i][j - 1] + dp[i - j][j - 1]) % mod;
        } else
          dp[i][j] = (dp[i][j - 1] + dp[i - j][j]) % mod;
      }
    }
    dp[i][i + 1] = (dp[i][i] + 1) % mod;
  }
  printf("%d\n", dp[n - 1][n]);
}
