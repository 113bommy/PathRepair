#include <bits/stdc++.h>
using namespace std;
int n, m, a[200005], c[100005], t, dp[100005];
int check(int x) {
  for (int dir = 1; dir <= 2; dir++) {
    memset(dp, 0, sizeof(dp));
    dp[dir] = (dir == 1) ? 0 : max(c[dir], x);
    for (int i = dir + 1; i <= m; i++) {
      dp[i] = dp[i - 1];
      if (dp[i - 1] >= c[i] - 1) dp[i] = max(dp[i], c[i] + x);
      if (dp[i - 1] >= c[i] - x - 1) dp[i] = max(dp[i], c[i]);
      if (i != dir + 1 && dp[i - 2] >= c[i] - x - 1)
        dp[i] = max(dp[i], c[i - 1] + x);
    }
    if (dp[m] >= min(n - 1, n + c[dir] - x - 1)) return 1;
  }
  return 0;
}
int main() {
  scanf("%d%d", &n, &m);
  int maxx = -1;
  for (int i = 1; i <= m; i++) {
    scanf("%d", &a[i]);
    a[i + m] = a[i] + n;
  }
  if (m == 1) {
    printf("%d\n", n - 1);
    return 0;
  }
  sort(a + 1, a + (m << 1) + 1);
  for (int i = 1; i <= m; i++) {
    c[i] = a[i + 1] - a[i];
    if (maxx < c[i]) {
      maxx = c[i];
      t = i;
    }
  }
  for (int i = m; i >= 1; i--) {
    c[i] = a[t + i] - a[t + 1];
  }
  int l = 0, r = maxx, ans = -1;
  while (l <= r) {
    int mid = (l + r) >> 1;
    if (check(mid))
      ans = mid, r = mid - 1;
    else
      l = mid + 1;
  }
  printf("%d\n", ans);
  return 0;
}
