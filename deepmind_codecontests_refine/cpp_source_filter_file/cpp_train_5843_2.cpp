#include <bits/stdc++.h>
using i64 = long long;
int main() {
  int n, k, x;
  scanf("%d%d%d", &n, &k, &x);
  std::vector<i64> a(n);
  for (int i = 0; i < n; i++) {
    scanf("%lld", &a[i]);
  }
  if (k * (x + 1) - 1 < n) {
    printf("-1\n");
    return 0;
  }
  std::vector<std::vector<i64>> dp(n, std::vector<i64>(x + 1));
  for (int i = 0; i < k; i++) dp[i][1] = a[i];
  for (int j = 2; j <= x; j++) {
    std::deque<i64> q, max;
    for (int i = 0; i < k; i++) {
      while (!q.empty() && dp[q.back()][j - 1] <= dp[i][j - 1]) q.pop_back();
      q.push_back(i);
      max.push_back(dp[q.front()][j - 1]);
    }
    for (int i = k; i < n; i++) {
      if (i - k == q.front()) q.pop_front();
      while (!q.empty() && dp[q.back()][j - 1] <= dp[i][j - 1]) q.pop_back();
      q.push_back(i);
      max.push_back(dp[q.front()][j - 1]);
    }
    for (int i = j - 1; i < n; i++) {
      if (!max[i - 1]) break;
      dp[i][j] = max[i - 1] + a[i];
    }
  }
  i64 ret = 0;
  for (int i = 0; i < n; i++) ret = std::max(ret, dp[i][x]);
  printf("%lld\n", ret);
  return 0;
}
