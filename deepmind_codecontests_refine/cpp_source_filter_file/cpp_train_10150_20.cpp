#include <bits/stdc++.h>
using namespace std;
#pragma comment(linker, "/STACK:1000000000")
static char s[1000][1000];
static int dp[2][55][55];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, m, res = 0, d1, d2;
  cin >> n >> m;
  for (int i = 0; i < n; ++i) cin >> s[i];
  dp[0][0][n - 1] = 1;
  for (int d = 0; (n + m - 2 - d) >= d; ++d) {
    d1 = d & 1;
    d2 = 1 - d1;
    memset(dp[d2], 0, sizeof(dp[d2]));
    for (int x = 0; x <= min(d, n - 1); ++x)
      for (int x1 = n - 1; x1 >= 0 && (n + m - 2 - d) - x1 < m; --x1) {
        if (s[x][d - x] != s[x1][(n + m - 2 - d) - x1]) dp[d1][x][x1] = 0;
        if (d == (n + m - 2 - d) && x == x1)
          res = (res + dp[d1][x][x1]) % (long long)1000000007;
        if (d == (n + m - 2 - d) - 1 && abs(x - x1) < 2 &&
            abs((d - x) - (d + 1 - x1)) < 2)
          res = (res + dp[d1][x][x1]) % (long long)1000000007;
        if (x1) {
          dp[d2][x + 1][x1 - 1] =
              (dp[d2][x + 1][x1 - 1] + dp[d1][x][x1]) % (long long)1000000007;
          dp[d2][x][x1 - 1] =
              (dp[d2][x][x1 - 1] + dp[d1][x][x1]) % (long long)1000000007;
        }
        dp[d2][x + 1][x1] =
            (dp[d2][x + 1][x1] + dp[d1][x][x1]) % (long long)1000000007;
        dp[d2][x][x1] = (dp[d2][x][x1] + dp[d1][x][x1]) % (long long)1000000007;
      }
  }
  cout << res << endl;
  return 0;
}
