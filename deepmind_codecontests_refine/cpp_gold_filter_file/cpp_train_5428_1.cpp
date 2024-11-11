#include <bits/stdc++.h>
using namespace std;
const int maxa = 1 << 6;
int n, m, maxm, ans, s[maxa], dp[45][maxa][maxa];
bool check(int sta1, int sta2, int sta3) {
  return ((sta1 | (sta1 << 1) | (sta1 >> 1) | sta2 | sta3) & (maxm - 1)) ==
         (maxm - 1);
}
int cal(int x) {
  int r = 0;
  while (x) {
    if (x & 1) r++;
    x >>= 1;
  }
  return m - r;
}
int main(void) {
  scanf("%d%d", &n, &m);
  if (m > n) swap(m, n);
  maxm = (1 << m);
  memset(dp, -1, sizeof(dp));
  for (int i = 0; i < maxm; i++) {
    dp[0][0][i] = 0;
    s[i] = cal(i);
  }
  for (int i = 1; i <= n; i++)
    for (int j = 0; j < maxm; j++)
      for (int k = 0; k < maxm; k++)
        if (dp[i - 1][j][k] != -1)
          for (int l = 0; l < maxm; l++)
            if (check(k, j, l))
              dp[i][k][l] = max(dp[i][k][l], dp[i - 1][j][k] + s[k]);
  for (int i = 0; i < maxm; i++) ans = max(ans, dp[n][i][0]);
  printf("%d\n", ans);
  return 0;
}
