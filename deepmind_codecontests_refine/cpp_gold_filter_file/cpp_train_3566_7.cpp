#include <bits/stdc++.h>
const int maxn = 2e5 + 10;
long long d1[maxn], d2[maxn], a[maxn], dp[maxn];
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
      scanf("%d", a + i);
    }
    for (int i = 0; i < n - 1; i += 2) {
      d1[i] = a[i + 1] - a[i];
    }
    for (int i = 1; i < n - 1; i += 2) d2[i] = a[i] - a[i + 1];
    long long ans = 0;
    long long tmp = 0, maxx = -1e18;
    if (d1[0] > 0) dp[0] = d1[0];
    for (int i = 1; i < n; i++) {
      dp[i] = std::max(dp[i - 1] + d1[i], d1[i]);
      ans = std::max(ans, dp[i]);
    }
    dp[0] = d2[0];
    for (int i = 1; i < n; i++) {
      dp[i] = std::max(dp[i - 1] + d2[i], d2[i]);
      ans = std::max(ans, dp[i]);
    }
    long long sum = 0;
    for (int i = 0; i < n; i++) {
      if (i & 1) continue;
      sum += a[i];
    }
    sum += ans;
    printf("%lld\n", sum);
  }
}
