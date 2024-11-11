#include <bits/stdc++.h>
char aaa[110][110];
int dp[110][110];
int main() {
  int n, m, i, k, p, q, c, ans = 0;
  scanf("%d%d", &n, &m);
  for (k = 0; k < n; k++) scanf("%s", aaa[k]);
  for (k = n - 1; k >= 0; k--) {
    for (i = m - 1; i >= 0; i--) {
      if (aaa[k][i] == 'B') {
        if (dp[k][i] == 1) continue;
        c = 1 - dp[k][i];
      } else {
        if (dp[k][i] == -1) continue;
        c = -1 - dp[k][i];
      }
      ans++;
      for (p = 0; p <= k; p++) {
        for (q = 0; q <= i; q++) {
          dp[p][q] += c;
        }
      }
    }
  }
  printf("%d", ans);
}
