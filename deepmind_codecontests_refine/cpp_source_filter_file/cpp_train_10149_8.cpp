#include <bits/stdc++.h>
using namespace std;
void set(int& n, int first) { n = n | (1 << first); }
void reset(int& n, int first) { n = n & ~(1 << first); }
bool check(int n, int first) { return (bool)(n & (1 << first)); }
const int mx = 502;
int a[mx], dp[2][mx][mx];
int main() {
  int it, i, j, k, n, m, B, mod;
  while (scanf("%d%d%d%d", &n, &m, &B, &mod) == 4) {
    for (i = 1; i <= n; i++) scanf("%d", &a[i]);
    memset(dp, 0, sizeof dp);
    dp[0][0][0] = 1;
    for (it = 1; it <= n; it++) {
      i = it & 1;
      for (j = 0; j <= m; j++) {
        for (k = 0; k <= m; k++) {
          dp[i][j][k] = dp[i ^ 1][j][k];
          if (j > 0 && k >= a[it]) {
            dp[i][j][k] += dp[i][j - 1][k - a[it]];
          }
          while (dp[i][j][k] >= mod) dp[i][j][k] -= mod;
        }
      }
    }
    int ans = 0;
    for (i = 0; i <= B; i++) {
      ans += dp[n & 1][m][i];
      while (ans >= mod) ans -= mod;
    }
    cout << ans << endl;
  }
}
