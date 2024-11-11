#include <bits/stdc++.h>
using namespace std;
const int N = 1e2 + 10;
int n, m, segs;
int a[N], pos[N];
int f[3][N][N][2 * N];
double dp[2][N][N];
bool Inside(int l, int r, int p) { return l <= p && p <= r; }
double Prob(int val) { return (double)val / segs; }
int sum(int n) {
  if (n <= 0) return 0;
  return n * (n + 1) / 2;
}
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  segs = n * (n + 1) / 2;
  for (int i = 1; i <= n; ++i) {
    for (int j = i + 1; j <= n; ++j) {
      for (int l = 1; l <= i; ++l) {
        for (int r = i; r < j; ++r) f[1][i][j][l + r]++;
        for (int r = j; r <= n; ++r) f[0][i][j][l + r]++;
      }
      for (int l = i + 1; l <= j; ++l)
        for (int r = j; r <= n; ++r) f[2][i][j][l + r]++;
    }
  }
  int lim = min(m, 1000);
  for (int i = 1; i <= n; ++i)
    for (int j = i + 1; j <= n; ++j) dp[0][i][j] = (a[i] > a[j]);
  int x = 0, y = 1;
  for (int turn = 0; turn < lim; ++turn) {
    for (int i = 1; i <= n; ++i)
      for (int j = i + 1; j <= n; ++j) dp[y][i][j] = 0;
    for (int i = 1; i <= n; ++i)
      for (int j = i + 1; j <= n; ++j) {
        for (int s = 1; s <= 2 * n; ++s) {
          if (f[0][i][j][s])
            dp[y][s - j][s - i] += ((1.0 - dp[x][i][j]) * Prob(f[0][i][j][s]));
          if (f[1][i][j][s])
            dp[y][s - i][j] += dp[x][i][j] * Prob(f[1][i][j][s]);
          if (f[2][i][j][s])
            dp[y][i][s - j] += dp[x][i][j] * Prob(f[2][i][j][s]);
        }
        int num = sum(i - 1) + sum(j - i - 1) + sum(n - j);
        dp[y][i][j] += dp[x][i][j] * ((double)num / segs);
      }
    x ^= 1;
    y ^= 1;
  }
  double ans = 0;
  for (int i = 1; i <= n; ++i)
    for (int j = i + 1; j <= n; ++j) ans += dp[x][i][j];
  cout << fixed << setprecision(12) << ans;
  return 0;
}
