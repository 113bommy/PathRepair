#include <bits/stdc++.h>
using namespace std;
struct node {
  long long v, s1, s2;
} dp[300005];
long long goods[4][300005];
long long num[4];
long long sum[300005];
int cmp(long long a, long long b) { return a > b; }
int main() {
  long long n, m, w, c;
  while (~scanf("%lld %lld", &n, &m)) {
    memset(goods, 0, sizeof(goods));
    memset(num, 0, sizeof(num));
    memset(dp, 0, sizeof(dp));
    for (long long i = 0; i < n; i++) {
      scanf("%lld %lld", &w, &c);
      goods[w][++num[w]] = c;
    }
    for (long long i = 1; i <= 3; i++) {
      sort(goods[i] + 1, goods[i] + 1 + num[i], cmp);
    }
    for (long long i = 1; i <= num[3]; i++) {
      sum[i] = sum[i - 1] + goods[3][i];
    }
    for (long long i = 1; i <= m; i++) {
      dp[i] = dp[i - 1];
      if (dp[i - 1].v + goods[1][dp[i - 1].s1 + 1] > dp[i].v) {
        dp[i].v = dp[i - 1].v + goods[1][dp[i - 1].s1 + 1];
        dp[i].s1 = dp[i - 1].s1 + 1;
        dp[i].s2 = dp[i - 1].s2;
      }
      if (i >= 2 && dp[i - 2].v + goods[2][dp[i - 2].s2 + 1] > dp[i].v) {
        dp[i].v = dp[i - 2].v + goods[2][dp[i - 2].s2 + 1];
        dp[i].s1 = dp[i - 2].s1;
        dp[i].s2 = dp[i - 2].s2 + 1;
      }
    }
    long long ans = 0;
    for (long long i = 0; i <= num[3] && i * 3 <= m; i++) {
      ans = max(ans, dp[m - i * 3].v + sum[i]);
    }
    printf("%lld\n", ans);
  }
}
