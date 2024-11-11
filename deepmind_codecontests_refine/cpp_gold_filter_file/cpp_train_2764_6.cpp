#include <bits/stdc++.h>
using namespace std;
long long dp[10000000 + 10];
int main() {
  int n;
  long long x, y;
  scanf("%d%I64d%I64d", &n, &x, &y);
  dp[1] = x;
  for (int i = 2; i <= n; i++) {
    dp[i] = min(dp[i - 1] + x, dp[(i + 1) / 2] + y + x * (i & 1));
  }
  printf("%I64d", dp[n]);
  return 0;
}
