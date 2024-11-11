#include <bits/stdc++.h>
using namespace std;
long long a[202000], b[200020];
long long dp[2020][2020];
int main() {
  long long n, k, p;
  while (~scanf("%lld%lld%lld", &n, &k, &p)) {
    for (long long i = 1; i <= n; i++) scanf("%lld", &a[i]);
    for (long long i = 1; i <= k; i++) scanf("%lld", &b[i]);
    memset(dp, 0, sizeof(dp));
    sort(a + 1, a + n + 1);
    sort(b + 1, b + k + 1);
    long long ans = 0x3f3f3f3f3f3f;
    for (long long i = 1; i <= n; i++) {
      for (long long j = i; j <= k; j++) {
        long long key = abs(a[i] - b[j]) + abs(b[j] - p);
        long long tmp = max(key, dp[i - 1][j - 1]);
        if (i == j)
          dp[i][j] = tmp;
        else
          dp[i][j] = min(tmp, dp[i][j - 1]);
      }
    }
    for (long long i = n; i <= k; i++) ans = min(ans, dp[n][i]);
    printf("%lld\n", ans);
  }
  return 0;
}
