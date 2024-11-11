#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5 + 5;
int INF = 1e9 + 7;
long long a[maxn];
long long dp[20];
int main() {
  int n, m, k;
  scanf("%d%d%d", &n, &m, &k);
  for (int q = 1; q <= n; q++) scanf("%lld", &a[q]);
  long long ans = 0;
  for (int q = 1; q <= n; q++) {
    for (int w = min(m, q); w > 1; w--) dp[w] = dp[w - 1] + a[q];
    dp[1] = a[q] - k + max(0ll, dp[0]);
    dp[0] = dp[m];
    for (int w = 0; w <= min(q, m); w++) ans = max(ans, dp[w]);
  }
  printf("%lld\n", ans);
  return 0;
}
