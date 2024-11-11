#include <bits/stdc++.h>
using namespace std;
int a[100010], b[2010], n, m;
int pre[100010], nxt[100010];
int dp[100010];
int main() {
  int i, j, k, l, r, z;
  scanf("%d%d", &n, &m);
  for (i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (i = 0; i < m; i++) scanf("%d", &b[i]);
  sort(a + 1, a + n + 1);
  sort(b, b + m);
  a[0] = -1;
  for (i = 1; i <= n; i++)
    if (a[i - 1] + 1 == a[i])
      pre[i] = pre[i - 1];
    else
      pre[i] = i;
  for (i = n; i >= 1; i--)
    if (a[i] + 1 == a[i + 1])
      nxt[i] = nxt[i + 1];
    else
      nxt[i] = i;
  for (i = 1; i <= n; i++) {
    l = -1;
    r = m;
    while (l + 1 < r) {
      z = (l + r) >> 1;
      if (b[z] <= a[i])
        l = z;
      else
        r = z;
    }
    int t = dp[i - 1];
    for (j = l; j >= 0; j--) {
      k = i - (a[i] - b[j]);
      if (k <= 0) break;
      t = max(t, dp[pre[k] - 1] + l - j + 1);
    }
    dp[i] = max(dp[i], t);
    for (j = l + 1; j < m; j++) {
      k = i + b[j] - a[i];
      if (k > n) break;
      dp[nxt[k]] = max(dp[nxt[k]], t + j - l);
    }
  }
  printf("%d\n", dp[n]);
  return 0;
}
