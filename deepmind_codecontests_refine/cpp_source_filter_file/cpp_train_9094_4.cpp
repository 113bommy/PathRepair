#include <bits/stdc++.h>
using namespace std;
long long dp[55][55], ans, n, t;
long long get(long long x) {
  long long tmp = 1, cnt = 0;
  while (tmp != x) {
    if (tmp > x) return -1;
    tmp *= 2;
    cnt++;
  }
  return cnt;
}
int main() {
  for (int i = 0; i <= 50; i++) {
    dp[i][0] = dp[i][i] = 1;
  }
  for (int i = 1; i <= 50; i++) {
    for (int j = 1; j <= 50; j++) {
      dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
    }
  }
  scanf("%lld%lld", &n, &t);
  t = get(t);
  if (t < 0) {
    puts("0");
    return 0;
  }
  long long now = 1, tmp = 2;
  while (tmp <= n) {
    n -= tmp;
    ans += dp[now][t];
    tmp *= 2;
    now++;
  }
  now = 0;
  for (int i = 50; i >= 1; i--) {
    if (n & (1ll << i)) {
      if (t - now >= 0) ans += dp[i][t - now];
      now++;
    }
  }
  printf("%lld\n", ans);
}
