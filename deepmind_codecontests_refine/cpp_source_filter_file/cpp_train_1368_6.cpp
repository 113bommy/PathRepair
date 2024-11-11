#include <bits/stdc++.h>
using namespace std;
const int MaxN = 1e6;
const int Inf = 1 << 30;
int cnt[MaxN + 5];
int dp[2][3][3][3];
int main() {
  int n, m, a, b, c, flag;
  while (~scanf("%d %d", &n, &m)) {
    for (int i = 1; i <= n; i++) cnt[i] = 0;
    for (int i = 1; i <= n; i++) {
      scanf("%d", &a);
      cnt[a]++;
    }
    flag = 0;
    memset(dp, 0, sizeof(dp));
    a = min(2, min(cnt[1], min(cnt[2], cnt[3])));
    b = min(2, min(cnt[2], min(cnt[3], cnt[4])));
    for (int i = 0; i <= a; i++) dp[1][0][0][i] = i + (cnt[1] - i) / 3;
    for (int i = 0; i <= b; i++) {
      for (int j = 0; j <= a; j++) {
        if (i + j <= cnt[2]) {
          dp[0][0][j][i] = dp[1][0][0][j] + i + (cnt[2] - i - j) / 3;
        }
      }
    }
    for (int i = 3; i <= n; i++) {
      flag ^= 1;
      if (i > 3) {
        a = b;
        b = c;
      }
      c = min(2, min(cnt[i], min(cnt[i + 1], cnt[i + 2])));
      for (int j = 0; j <= a; j++) {
        for (int k = 0; k <= b; k++) {
          if (cnt[i] < j + k) continue;
          for (int l = 0; l <= c; l++) {
            if (cnt[i] >= j + k + l) {
              dp[flag][j][k][l] =
                  dp[flag ^ 1][0][j][k] + l + (cnt[i] - j - k - l) / 3;
              dp[flag][0][k][l] = max(dp[flag][0][k][l], dp[flag][j][k][l]);
            }
          }
        }
      }
    }
    printf("%d\n", dp[flag][0][0][0]);
  }
  return 0;
}
