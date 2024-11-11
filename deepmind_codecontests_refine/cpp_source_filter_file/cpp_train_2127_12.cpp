#include <bits/stdc++.h>
using namespace std;
inline long long ma(long long a, long long b) { return ((a - b > 0) ? a : b); }
inline long long mi(long long a, long long b) { return ((a - b > 0) ? b : a); }
long long dp[5][5][250];
long long ct[5][250];
inline long long solve(long long n, long long a, long long b, long long c) {
  if (n == 1) return mi(ct[a][b], ct[a][c] + ct[c][b]);
  return (solve(n - 1, a, c, b) + ct[a][b] + solve(n - 1, c, b, a));
}
inline long long solve1(long long n, long long a, long long b, long long c) {
  if (n == 1) return mi(ct[a][b], ct[a][c] + ct[c][b]);
  return solve1(n - 1, a, c, b) + ct[a][b] + solve1(n - 1, c, b, a);
}
inline long long ok(long long n, long long a, long long b, long long c) {
  if (n == 1) return mi(ct[a][b], ct[a][c] + ct[c][b]);
  if (dp[a][b][n] != -1) return dp[a][b][n];
  long long &ans = dp[a][b][n];
  ans = LONG_LONG_MAX;
  ans = mi(ans, ct[a][b] + ok(n - 1, a, c, b) + ok(n - 1, c, b, a));
  ans = mi(ans,
           ct[a][c] + ct[c][b] + ok(n - 1, a, b, c) + 2 * ok(n - 1, b, a, c));
  return ans;
}
int main() {
  for (long long(j) = (0); (j) < (3); (j)++) {
    for (long long(i) = (0); (i) < (3); (i)++) cin >> ct[j][i];
  }
  long long n;
  cin >> n;
  memset(dp, -1, sizeof(dp));
  cout << ok(n, 0, 2, 1) << endl;
  return 0;
}
