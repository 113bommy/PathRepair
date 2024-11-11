#include <bits/stdc++.h>
using namespace std;
const int maxn = 88;
const int INF = 1e9 + 7;
int n, a[maxn], cnt;
int dp[maxn][maxn * maxn][maxn];
int b[maxn];
int getwei(int x, int y, int l) { return max(l + x - y, b[x]); }
int ans[maxn * maxn];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    if (a[i] == 1) b[++cnt] = i;
  }
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= n * n; j++) {
      for (int l = 0; l <= n; l++) {
        dp[i][j][l] = -INF;
      }
    }
  }
  dp[0][0][0] = 0;
  for (int i = 1; i <= cnt; i++) {
    for (int j = 0; j <= n * (n - 1) / 2; j++) {
      for (int l = 0; l <= n; l++) {
        if (dp[i - 1][j][l] == -INF) continue;
        int g = i;
        int d = 0;
        for (int m = l + 1; m <= n - cnt + i; m++) {
          if (m <= getwei(i, i - 1, l)) {
            d = getwei(i, i - 1, l) - m;
            dp[i][j + d][m] =
                max(dp[i][j + d][m],
                    dp[i - 1][j][l] + (m - l - 1) * (n - m - cnt + i));
          } else {
            while (g <= cnt && getwei(g, i - 1, l) < m) g++;
            d += g - i;
            dp[i][j + d][m] =
                max(dp[i][j + d][m],
                    dp[i - 1][j][l] + (m - l - 1) * (n - m - cnt + i));
          }
        }
      }
    }
  }
  for (int i = 1; i <= cnt; i++) {
    for (int j = 0; j <= n * (n - 1) / 2; j++) {
      for (int l = 0; l <= n; l++) {
        ans[j] = max(ans[j], dp[i][j][l]);
      }
    }
  }
  int ma = 0;
  for (int i = 0; i <= n * (n - 1) / 2; i++) {
    ma = max(ma, ans[i]);
    if (i != 0) printf(" ");
    printf("%d", ma);
  }
  printf("\n");
  return 0;
}
