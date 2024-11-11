#include <bits/stdc++.h>
using namespace std;
const int maxn = 5005;
const int maxl = 105;
double dp[maxn][maxn];
int n, tot;
int t[maxn];
int p[maxn];
double ans;
int main() {
  cin >> n >> tot;
  for (int i = 1; i <= tot; i++) {
    cin >> p[i] >> t[i];
  }
  dp[0][0] = 1;
  for (int i = 1; i <= n; i++) {
    double now = 0;
    double pp = 0.01 * p[i];
    double r = pow(1 - pp, t[i] - 1);
    for (int j = 1; j <= tot; j++) {
      now *= 1 - pp;
      now += pp * dp[i - 1][j - 1];
      if (j >= t[i]) {
        now -= pp * r * dp[i - 1][j - t[i]];
        now += r * dp[i - 1][j - t[i]];
        if (j - t[i] - 1 >= 0) now -= (1 - pp) * r * dp[i - 1][j - t[i] - 1];
      }
      dp[i][j] = now;
    }
    for (int j = 1; j <= tot; j++) ans += dp[i][j];
  }
  printf("%.9lf", ans);
  return 0;
}
