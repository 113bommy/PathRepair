#include <bits/stdc++.h>
using namespace ::std;
const long long maxn = 2100;
const long long mod = 1e9 + 7;
const long long inf = 1e9 + 500;
bool satr[maxn];
bool sot[maxn];
long double dp[maxn][maxn];
int main() {
  long long n, m;
  cin >> n >> m;
  for (long long i = 0; i < m; i++) {
    long long x, y;
    cin >> x >> y;
    satr[x] = 1;
    sot[y] = 1;
  }
  long long xx = 0;
  for (long long i = 1; i <= n; i++) {
    xx += sot[i];
  }
  long long yy = 0;
  for (long long i = 1; i <= n; i++) {
    yy += satr[i];
  }
  dp[n][n] = 0;
  long double nn = n;
  for (long long i = n - 1; i >= 1; i--) {
    dp[i][n] = ((dp[i + 1][n] * ((nn - i) / nn)) + 1) / ((nn - i) / nn);
    dp[n][i] = dp[i][n];
  }
  for (long long x = n - 1; x >= 1; x--) {
    for (long long y = n - 1; y >= 1; y--) {
      dp[x][y] = (((nn - x) * y / (nn * nn) * dp[x + 1][y]) +
                  ((nn - y) * x / (nn * nn) * dp[x][y + 1]) +
                  ((nn - x) * (nn - y) / (nn * nn) * dp[x + 1][y + 1]) + 1) /
                 ((nn * nn - x * y) / (nn * nn));
    }
  }
  cout << fixed << setprecision(100) << dp[xx][yy];
}
