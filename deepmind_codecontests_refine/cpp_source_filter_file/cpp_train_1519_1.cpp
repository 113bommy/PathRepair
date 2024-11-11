#include <bits/stdc++.h>
using namespace std;
int dp[1 << 22], a[30][30], pre[30];
char s[200010];
int main() {
  int n, k, t, i, j, l, r, tot = 0, ans = 0;
  scanf("%d%d%d%s", &n, &k, &t, s);
  for (i = 0; i < k; i++) scanf("%d", &dp[1 << i]);
  for (i = 0; i < k; i++)
    for (j = 0; j < k; j++) scanf("%d", &a[i][j]);
  memset(pre, -1, sizeof(pre));
  for (i = 0; i < n; i++) {
    r = s[i] - 'A';
    tot |= (1 << r);
    for (l = 0; l < k; l++)
      if (~pre[l]) {
        if (!(pre[l] & (1 << l)) && !(pre[r] & (1 << r))) {
          dp[pre[l]] += a[l][r];
          dp[pre[l] | (1 << l)] -= a[l][r];
          dp[pre[l] | (1 << r)] -= a[l][r];
          dp[pre[l] | (1 << l) | (1 << r)] += a[l][r];
        }
        pre[l] |= (1 << r);
      }
    pre[r] = 0;
  }
  for (i = 0; i < k; i++)
    for (j = 0; j <= tot; j++)
      if ((1 << i) & j) dp[j] += dp[j ^ (1 << i)];
  for (i = tot & (tot - 1); i < tot; i = (i - 1) & tot)
    if (dp[i] <= t) ans++;
  printf("%d\n", ans);
}
