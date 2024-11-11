#include <bits/stdc++.h>
char a[501][501], tmp;
long long DP[501][501], ans;
int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; i++) {
    scanf("%c", &tmp);
    for (int j = 1; j <= m; j++) {
      scanf("%c", &a[i][j]);
    }
  }
  if (a[1][1] != a[n][m]) {
    printf("0\n");
    return 0;
  }
  DP[1][n] = 1;
  for (int i = 1; i <= (n + m) / 2 - 1; i++) {
    for (int j = i + 1; j >= 1; j--) {
      for (int k = n - i; k <= n; k++) {
        if (a[j][i + 2 - j] == a[k][n + m - i - k]) {
          DP[j][k] = (DP[j][k] + DP[j - 1][k] + DP[j][k + 1] +
                      DP[j - 1][k + 1] + 1000000007) %
                     1000000007;
        } else {
          DP[j][k] = 0;
        }
      }
    }
  }
  if ((n + m) & 1) {
    for (int i = 1; i <= n; i++)
      ans = (ans + DP[i][i] + DP[i][i + 1] + 1000000007) % 1000000007;
  } else {
    for (int i = 1; i <= n; i++)
      ans = (ans + DP[i][i] + 1000000007) % 1000000007;
  }
  printf("%lld\n", ans);
  return 0;
}
