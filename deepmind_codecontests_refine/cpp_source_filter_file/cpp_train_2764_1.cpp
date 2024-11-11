#include <bits/stdc++.h>
using namespace std;
#pragma comment(linker, "/STACK:1024000000,1024000000")
const long long inf = (long long)2e18;
long long dp[20000010];
int main() {
  int n;
  long long x, y;
  while (~scanf("%d%lld%lld", &n, &x, &y)) {
    dp[1] = x;
    for (int i = 2; i <= n; i++) dp[i] = inf;
    for (int i = 2; i <= n; i++) {
      dp[i] = min(dp[i - 1] + 1, dp[i]);
      if (i & 1) {
        dp[i] = min(dp[i], dp[i / 2 + 1] + x + y);
        dp[i] = min(dp[i], dp[i / 2] + x + y);
      } else
        dp[i] = min(dp[i], dp[i / 2] + y);
    }
    printf("%lld\n", dp[n]);
  }
  return 0;
}
