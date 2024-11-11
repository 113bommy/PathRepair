#include <bits/stdc++.h>
using namespace std;
long long MOD = 1000000007;
long long n, x, y;
long long dp[(int)2e7 + 5];
long long solve(long long pos) {
  if (pos == 1) return x;
  if (dp[pos]) return dp[pos];
  if (pos % 2) {
    dp[pos] = min(solve(pos - 1) + x, solve((pos + 1) / 2) + x + y);
  } else {
    dp[pos] = min(solve(pos - 1) + x, solve(pos / 2) + y);
  }
  return dp[pos];
}
int main() {
  scanf("%I64d %I64d %I64d", &n, &x, &y);
  printf("%I64d", solve(n));
}
