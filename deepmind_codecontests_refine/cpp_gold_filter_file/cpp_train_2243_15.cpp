#include <bits/stdc++.h>
using namespace std;
int n, m;
long long ans, dp[800005];
long long fp(long long x, long long y) {
  if (!y) return 1;
  if (y == 1) return x;
  long long son = fp(x, y / 2) % 1000003;
  son = (son * son) % 1000003;
  return (y % 2 ? son * x : son) % 1000003;
}
int main() {
  scanf("%d %d", &n, &m);
  dp[0] = 1;
  for (int i = 1; i <= m + n; i++) dp[i] = (dp[i - 1] * i) % 1000003;
  for (int i = 1; i <= n; i++) {
    ans =
        (ans + dp[m + i - 1] * fp((dp[i] * dp[m - 1]) % 1000003, 1000003 - 2)) %
        1000003;
  }
  printf("%lld", ans);
}
