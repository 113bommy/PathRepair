#include <bits/stdc++.h>
using namespace std;
long long n, t;
long long dp[22][5][11][2];
long long rec(long long x, long long y, long long c, long long cn) {
  if (x > n) return 0;
  if (x == n && cn == t && y > 0) return 1;
  if (y <= 0 || y > 4) return 0;
  if (dp[x][y][cn][c] != -1) return dp[x][y][cn][c];
  long long k = 0;
  if (cn == t)
    k += rec(x + 1, y - 1, 0, t) + rec(x + 1, y - 2, 0, t) +
         rec(x + 1, y - 3, 0, t);
  else {
    if (c == 1) {
      k += rec(x + 1, y + 1, 1, cn) + rec(x + 1, y + 2, 1, cn) +
           rec(x + 1, y + 3, 1, cn);
      k += rec(x + 1, y - 1, 0, cn + 1) + rec(x + 1, y - 2, 0, cn + 1) +
           rec(x + 1, y - 3, 0, cn + 1);
    } else {
      k += rec(x + 1, y - 1, 0, cn) + rec(x + 1, y - 2, 0, cn) +
           rec(x + 1, y - 3, 0, cn);
      k += rec(x + 1, y + 1, 1, cn) + rec(x + 1, y + 2, 1, cn) +
           rec(x + 1, y + 3, 1, cn);
    }
  }
  return dp[x][y][cn][c] = k;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> t;
  memset(dp, -1, sizeof(dp));
  long long ans = 0;
  ans += rec(2, 2, 1, 0);
  ans += 2 * rec(2, 3, 1, 0);
  ans += 3 * rec(2, 4, 1, 0);
  cout << ans;
  return 0;
}
