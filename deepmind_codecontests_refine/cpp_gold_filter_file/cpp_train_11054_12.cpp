#include <bits/stdc++.h>
int n, col, a[400005], cnt[25];
long long dp[1 << 20], sum[25], con[25][25];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i)
    scanf("%d", a + i), col = std::max(col, a[i]),
                        sum[a[i]] += i - cnt[a[i]] - 1, ++cnt[a[i]];
  for (int i = 1; i <= col; ++i) {
    for (int j = 1, cur = 0; j <= n; ++j) {
      if (a[j] == i)
        ++cur;
      else
        con[a[j]][i] += cur;
    }
  }
  for (int s = 1; s < (1 << col); ++s) {
    dp[s] = 0x3f3f3f3f3f3f3f;
    for (int i = 1; i <= col; ++i) {
      if (!(s & (1 << (i - 1)))) continue;
      long long tmp = 0, tot = 0;
      for (int j = 1; j <= col; ++j)
        if (((1 << (j - 1)) & s) && j != i) tmp += con[j][i], tot += cnt[j];
      dp[s] = std::min(dp[s], dp[s ^ (1 << (i - 1))] + tmp);
    }
  }
  printf("%lld\n", dp[(1 << col) - 1]);
  return 0;
}
