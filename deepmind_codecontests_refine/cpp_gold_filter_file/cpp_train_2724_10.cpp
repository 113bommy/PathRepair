#include <bits/stdc++.h>
using namespace std;
const long long MOD = (long long)1e8;
int k[3];
int dp[105][105][3][11];
long long solve(int n1, int n2, int prev, int prevcount) {
  if (n1 == 0 && n2 == 0) return 1;
  if (dp[n1][n2][prev][prevcount] != -1) return dp[n1][n2][prev][prevcount];
  long long ret = 0;
  if (prev == 1) {
    if (n2 > 0) ret += solve(n1, n2 - 1, 2, 1);
    if (n1 > 0 && prevcount + 1 <= k[prev])
      ret += solve(n1 - 1, n2, prev, prevcount + 1);
  } else if (prev == 2) {
    if (n1 > 0) ret += solve(n1 - 1, n2, 1, 1);
    if (n2 > 0 && prevcount + 1 <= k[prev])
      ret += solve(n1, n2 - 1, prev, prevcount + 1);
  }
  return dp[n1][n2][prev][prevcount] = ret % MOD;
}
int main() {
  int n[2];
  scanf("%d %d %d %d", &n[0], &n[1], &k[1], &k[2]);
  memset(dp, -1, sizeof dp);
  long long ans = 0;
  ans += solve(n[0] - 1, n[1], 1, 1);
  ans += solve(n[0], n[1] - 1, 2, 1);
  printf("%lld\n", ans % MOD);
  return 0;
}
