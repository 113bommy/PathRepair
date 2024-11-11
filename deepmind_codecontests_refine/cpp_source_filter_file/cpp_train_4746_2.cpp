#include <bits/stdc++.h>
const int MAXN = 250;
const int MOD = 1000000009;
char s[4 * MAXN + 2][4 * MAXN + 2];
int dp[MAXN + 2], can1[MAXN], can2[MAXN];
char mp[MAXN + 1][MAXN + 1];
int main() {
  int i, j, k, m, n, x, y;
  scanf("%d%d", &n, &m);
  for (i = 0; i < 4 * n + 1; i++) scanf("%s", s[i]);
  for (x = 0; x < n; x++)
    for (y = 0; y < m; y++) {
      int t = 0;
      mp[x][y] = 1 | 2;
      for (j = 1; j < 4; j++)
        for (k = 1; k < 4; k++) {
          if (s[j + x * 4][k + y * 4] == 'O') t++;
        }
      if (t == 3 || t == 2) {
        if (s[1 + x * 4][1 + y * 4] == 'O')
          mp[x][y] = 1;
        else
          mp[x][y] = 2;
      } else if (t == 6) {
        if (s[1 + x * 4][2 + y * 4] == 'O')
          mp[x][y] = 1;
        else
          mp[x][y] = 2;
      }
    }
  for (j = 0; j < m; j++) {
    can1[j] = (n % 2 == 0);
    for (i = 0; i < n; i++) can1[j] &= !!(mp[i][j] & 2);
  }
  for (j = 0; j + 1 < m; j++) {
    int cnt[MAXN + 2] = {0};
    cnt[0] = 1;
    for (i = 0; i < n; i++) {
      if (mp[i][j] & mp[i][j + 1] & 1) cnt[i + 1] = (cnt[i + 1] + cnt[i]) % MOD;
      if (i + 1 < n &&
          (mp[i][j] & mp[i][j + 1] & mp[i + 1][j] & mp[i + 1][j + 1] & 2))
        cnt[i + 2] = (cnt[i + 2] + cnt[i]) % MOD;
    }
    can2[j] = (cnt[n] - (can1[j] * can1[j + 1]) + MOD) % MOD;
  }
  dp[0] = 1;
  for (i = 0; i < m; i++) {
    dp[i + 1] = (dp[i + 1] + (dp[i] * can1[i])) % MOD;
    if (i > 0)
      dp[i + 1] = (dp[i + 1] + (long long)dp[i - 1] * can2[i - 1]) % MOD;
  }
  printf("%d\n", dp[m]);
  scanf("%*d");
}
