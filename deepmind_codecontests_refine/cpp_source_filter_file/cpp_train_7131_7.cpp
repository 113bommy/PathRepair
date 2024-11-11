#include <bits/stdc++.h>
using namespace std;
const int N = 155;
int n, K, s, dp[2][N][N * N / 2];
int q[N];
int main(void) {
  int i, j, k;
  while (~scanf("%d%d%d", &n, &K, &s)) {
    for (i = 0; i < n; i++) scanf("%d", &q[i]);
    if (s >= (n - 1) * n / 2) {
      sort(q, q + n);
      int ans = 0;
      for (i = 0; i < K; i++) ans += q[i];
      printf("%d\n", ans);
      continue;
    }
    int cur = 0, nxt = 1;
    memset(dp[cur], 0x3f, sizeof(dp[cur]));
    dp[0][0][0] = 0;
    for (i = 0; i < n; i++) {
      memset(dp[nxt], 0x3f, sizeof(dp[nxt]));
      for (j = 0; j <= min(i, K); j++) {
        for (k = 0; k <= s; k++) {
          if (dp[cur][j][k] == 0x3f3f3f3f) continue;
          dp[nxt][j][k] = min(dp[nxt][j][k], dp[cur][j][k]);
          if (k + i - j <= s)
            dp[nxt][j + 1][k + i - j] =
                min(dp[nxt][j + 1][k + i - j], dp[nxt][j][k] + q[i]);
        }
      }
      swap(cur, nxt);
    }
    int ans = 0x3f3f3f3f;
    for (i = 0; i <= s; i++) ans = min(ans, dp[cur][K][i]);
    printf("%d\n", ans);
  }
  return 0;
}
