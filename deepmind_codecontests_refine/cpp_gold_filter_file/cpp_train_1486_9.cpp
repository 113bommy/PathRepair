#include <bits/stdc++.h>
using namespace std;
int n, m;
char s[1009000];
int a[4][1009000];
int dp[4][1009000];
int main() {
  scanf("%d%d", &n, &m);
  if (n >= 4) {
    printf("-1\n");
    return 0;
  }
  if (n == 1) {
    printf("0\n");
    return 0;
  }
  for (int i = 1; i <= n; ++i) {
    scanf("%s", s + 1);
    for (int j = 1; j <= m; ++j) a[i][j] = s[j] - '0';
  }
  int ans = 1e9;
  if (n == 2) {
    for (int i = 0; i < (1 << n); ++i) {
      int num = 0;
      for (int j = 1; j <= n; ++j) {
        if (a[j][1] != ((i >> j - 1) & 1))
          dp[j][1] = a[j][1] ^ 1, num++;
        else
          dp[j][1] = a[j][1];
      }
      for (int j = 2; j <= m; ++j) {
        dp[1][j] = a[1][j];
        dp[2][j] = a[2][j];
        int t = dp[1][j - 1] + dp[1][j] + dp[2][j - 1] + dp[2][j];
        if ((t & 1) == 0) dp[1][j] ^= 1, num++;
      }
      ans = min(ans, num);
    }
  } else {
    for (int i = 0; i < (1 << n); ++i) {
      int num = 0;
      for (int j = 1; j <= n; ++j) {
        if (a[j][1] != ((i >> j - 1) & 1))
          dp[j][1] = a[j][1] ^ 1, num++;
        else
          dp[j][1] = a[j][1];
      }
      for (int j = 2; j <= m; ++j) {
        dp[1][j] = a[1][j];
        dp[2][j] = a[2][j];
        dp[3][j] = a[3][j];
        int t = dp[1][j - 1] + dp[1][j] + dp[2][j - 1] + dp[2][j];
        int t2 = dp[2][j - 1] + dp[2][j] + dp[3][j - 1] + dp[3][j];
        if ((t & 1) == 0 && (t2 & 1) == 0) dp[2][j] ^= 1, num++;
        if ((t & 1) == 1 && (t2 & 1) == 0) dp[3][j] ^= 1, num++;
        if ((t & 1) == 0 && (t2 & 1) == 1) dp[1][j] ^= 1, num++;
      }
      ans = min(ans, num);
    }
  }
  printf("%d\n", ans);
  return 0;
}
