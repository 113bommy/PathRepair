#include <bits/stdc++.h>
using namespace std;
long long dp[41][3][3][3][2];
int t[3][3];
long long solve(int n, int src, int snk, int tmp, bool smallest) {
  if (n == 1) {
    if (smallest) return min(t[src][snk], t[src][tmp] + t[tmp][snk]);
    return t[src][snk];
  }
  long long &res = dp[n][src][snk][tmp][smallest];
  if (res != -1) return res;
  res = 1LL << 61;
  res = min(res, solve(n - 1, src, tmp, snk, 1) + solve(1, src, snk, tmp, 0) +
                     solve(n - 1, tmp, snk, src, 1));
  res =
      min(res, solve(n - 1, src, snk, tmp, 1) + solve(1, src, tmp, snk, 0) +
                   solve(n - 1, snk, src, tmp, 1) + solve(1, tmp, snk, src, 0) +
                   solve(n - 1, src, snk, tmp, 1));
  return res;
}
int main() {
  int n;
  for (int i = 0; i < 3; ++i)
    for (int j = 0; j < 3; ++j) scanf("%d", t[i] + j);
  scanf("%d", &n);
  memset(dp, -1, sizeof dp);
  printf("%I64d\n", solve(n, 0, 2, 1, 1));
  return 0;
}
