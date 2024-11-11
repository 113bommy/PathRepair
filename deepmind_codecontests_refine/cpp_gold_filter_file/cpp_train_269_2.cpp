#include <bits/stdc++.h>
using namespace std;
const int N = 50 + 5;
const int M = N * 100 + 5;
int n, r, f[N], s[N], p[N];
double dp[N][M], mid;
double cal(int x, int y) { return y > r ? mid : dp[x][y]; }
void solve() {
  scanf("%d%d", &n, &r);
  for (int i = 0; i < n; i++) scanf("%d%d%d", &f[i], &s[i], &p[i]);
  double lo = 0, hi = 1e9;
  for (int _ = 0; _ < 120; _++) {
    mid = (lo + hi) / 2.0;
    for (int i = 0; i <= r; i++) dp[n][i] = 0;
    for (int i = n - 1; i >= 0; i--) {
      for (int j = 0; j <= r; j++) {
        dp[i][j] =
            min(mid, 0.01 * ((cal(i + 1, j + f[i]) + f[i]) * p[i] +
                             (cal(i + 1, j + s[i]) + s[i]) * (100 - p[i])));
      }
    }
    if (dp[0][0] >= mid)
      lo = mid;
    else
      hi = mid;
  }
  printf("%.17f\n", lo);
}
int main() {
  solve();
  return 0;
}
