#include <bits/stdc++.h>
long long m;
int k, num[100];
long long dp[100][100];
long long dfs(int pos, int sum, bool lim) {
  if (!pos) return (sum == k);
  if (!lim && dp[pos][sum] != -1) return dp[pos][sum];
  int up = lim ? num[pos] : 1;
  long long ans = 0;
  for (int i = 0; i <= up; i++)
    if (sum + (i == 1) <= k)
      ans += dfs(pos - 1, sum + (i == 1), lim && (i == up));
  if (!lim) dp[pos][sum] = ans;
  return ans;
}
long long solve(long long x) {
  int len = 0;
  while (x) num[++len] = x & 1, x >>= 1;
  return dfs(len, 0, 1);
}
long long calc(long long x) { return solve(x << 1) - solve(x); }
int main() {
  scanf("%lld %d", &m, &k);
  memset(dp, -1, sizeof(dp));
  long long l = 1, r = 1e18;
  while (l <= r) {
    long long mid = (l + r) >> 1, ans = calc(mid);
    if (ans == m)
      return !printf("%lld", mid);
    else if (ans > m)
      r = mid - 1;
    else
      l = mid + 1;
  }
  return 0;
}
