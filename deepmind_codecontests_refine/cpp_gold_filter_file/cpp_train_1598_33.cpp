#include <bits/stdc++.h>
using namespace std;
double dp[202][202][420];
int N, l, k;
int a[202];
double p[202];
void scan() {
  cin >> N >> l >> k;
  for (int i = 0; i < N; ++i) {
    cin >> p[i];
    p[i] /= 100.;
  }
  for (int i = 0; i < N; ++i) cin >> a[i];
}
void solve() {
  dp[0][0][202 + k] = 1;
  for (int i = 0; i < N; ++i)
    for (int won = 0; won <= N; ++won)
      for (int space = 0; space <= 419; ++space) {
        if (dp[i][won][space] < 1e-12) continue;
        if (a[i] == -1) {
          dp[i + 1][won + 1][space - 1] += (dp[i][won][space] * p[i]);
          dp[i + 1][won][space] += (dp[i][won][space] * (1. - p[i]));
        } else {
          int nxt = min(419, space + a[i]);
          dp[i + 1][won + 1][nxt] += (dp[i][won][space] * p[i]);
          dp[i + 1][won][space] += (dp[i][won][space] * (1. - p[i]));
        }
      }
  double res = 0.;
  for (int won = l; won <= N; ++won)
    for (int space = 202; space < 420; ++space) res += dp[N][won][space];
  printf("%.10f\n", res);
}
int main() {
  scan();
  solve();
}
