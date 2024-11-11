#include <bits/stdc++.h>
using namespace std;
int a[100010], b[100010], l[100010], dp[100010], dp0[100010];
int n, m;
int main() {
  int i, j;
  scanf("%d%d", &n, &m);
  for (i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
  }
  sort(a + 1, a + 1 + n);
  for (i = 1; i <= m; ++i) scanf("%d", &b[i]);
  sort(b + 1, b + 1 + m);
  l[1] = 1;
  for (i = 2; i <= n; ++i) l[i] = a[i] == a[i - 1] ? l[i - 1] : i;
  for (i = 1; i <= n; ++i) {
    int p = upper_bound(b + 1, b + 1 + m, a[i]) - b - 1;
    if (i == l[i])
      dp[i] = max(dp[i], dp0[i - 1]);
    else
      dp[i] = max(dp[i], dp[i - 1]);
    for (j = 1; j <= p; ++j) {
      int k = a[i] - b[j];
      if (k < i) dp[i] = max(dp[i], dp0[l[i - k] - 1] + p - j + 1);
    }
    dp0[i] = max(dp0[i], dp[i]);
    for (j = p + 1; j <= m; ++j) {
      int k = b[j] - a[i];
      if (i + k <= n) dp0[i + k] = max(dp0[i + k], dp[i] + j - p);
    }
    dp0[i + 1] = max(dp0[i + 1], dp0[i]);
  }
  printf("%d\n", dp0[n]);
  return 0;
}
