#include <bits/stdc++.h>
long long dp[36][36];
long long count(int n, int h) {
  if (n == 0) return h >= 0;
  if (~dp[n][h]) return dp[n][h];
  dp[n][h] = 0;
  for (int i = 0; i < n; i++)
    dp[n][h] += count(i, h - 1) * count(n - i - 1, h - 1);
  return dp[n][h];
}
int main() {
  int n, h;
  memset(dp, -1, sizeof(dp));
  scanf("%d %d", &n, &h);
  printf("%I64d\n", count(n, n) - count(n, h - 1));
  return 0;
}
