#include <bits/stdc++.h>
using namespace std;
int n, m, p, s, q, t, i, I, j, k, x, y, z, c, d, l, r, l1, l2, lst, a, b, mn,
    mx, cnt, res, ans, cur, u, v;
const int mod = 1000000007;
int dp[3000][3000];
int add(int a, int b) {
  a += b;
  if (a >= mod) a -= mod;
  if (a < 0) a += mod;
  return a;
}
int main() {
  cin >> n >> k;
  for (i = 1; i <= n; i++) {
    dp[1][i] = 1;
  }
  for (i = 1; i < k; i++) {
    for (j = 1; j <= n; j++) {
      for (p = j; p <= n; p += j) {
        dp[i + 1][p] = add(dp[i + 1][p], dp[i][j]);
      }
    }
  }
  for (i = 1; i <= n; i++) {
    ans = add(ans, dp[k][i]);
  }
  cout << ans;
}
