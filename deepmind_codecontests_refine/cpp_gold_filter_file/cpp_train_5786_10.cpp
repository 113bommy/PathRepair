#include <bits/stdc++.h>
int ans, n, i, r[22], b[22], j, k, dp[65555][130], sumr, sumb;
char ss[22][22];
int max(int a, int b) { return a > b ? a : b; }
int min(int a, int b) { return a < b ? a : b; }
int main() {
  scanf("%d\n", &n);
  for (i = 0; i < n; i++) {
    scanf("%s", ss[i]);
    scanf("%d%d\n", &r[i], &b[i]);
    sumr += r[i];
    sumb += b[i];
  }
  ans = 1111111111;
  int s = 1 << n;
  memset(dp, -1, sizeof(dp));
  dp[0][0] = 0;
  for (i = 0; i < s; i++)
    for (j = 0; j <= n * n / 2; j++)
      if (dp[i][j] != -1) {
        int A = 0, B = 0;
        for (k = 0; k < n; k++)
          if (i & (1 << k)) {
            if (ss[k][0] >= 'R')
              A++;
            else
              B++;
          }
        for (k = 0; k < n; k++)
          if ((i & (1 << k)) == 0) {
            int costr = min(r[k], A);
            int costb = min(b[k], B);
            dp[i + (1 << k)][j + costr] =
                max(dp[i + (1 << k)][j + costr], dp[i][j] + costb);
          }
        if (i == s - 1) {
          ans = min(ans, max(sumr - j, sumb - dp[i][j]));
        }
      }
  printf("%d\n", n + ans);
}
