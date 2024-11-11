#include <bits/stdc++.h>
using namespace std;
int n;
int a[1005][1005];
int dp[605][303][303];
int calc(int t, int c, int cc) {
  if (t == 2 * (n - 1)) {
    if (c == n && cc == n)
      return a[n][n];
    else
      return -(1e8);
  }
  if (dp[t][c][cc] != -1) return dp[t][c][cc];
  int r = 2 + t - c;
  int rr = 2 + t - cc;
  int ans = -(1e9);
  int x = 0;
  if (c == cc)
    x = a[c][r];
  else
    x = a[c][r] + a[cc][rr];
  if (r < n && cc < n) ans = max(ans, x + calc(t + 1, c, cc + 1));
  if (rr < n && c < n) ans = max(ans, x + calc(t + 1, c + 1, cc));
  if (c < n && cc < n) ans = max(ans, x + calc(t + 1, c + 1, cc + 1));
  if (r < n && rr < n) ans = max(ans, x + calc(t + 1, c, cc));
  return dp[t][c][cc] = ans;
}
int main() {
  memset(dp, -1, sizeof dp);
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= n; ++j) scanf("%d", &a[i][j]);
  printf("%d\n", calc(0, 1, 1));
  return 0;
}
