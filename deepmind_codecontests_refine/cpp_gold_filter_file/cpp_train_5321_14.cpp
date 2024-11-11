#include <bits/stdc++.h>
using namespace std;
const long long INF = 1000 * 1000 * 1000;
const long long LINF = INF * (long long)INF;
const int MAX = 100005;
const int mod = 1000 * 1000 * 1000 + 7;
pair<int, int> ap[105];
double dp[2][111][1015];
double coef[105];
double c, t;
double g(double val, double x) { return val / (1 + c * x) + x; }
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  coef[0] = 0.9;
  for (int i = 1; i <= 100; i++) coef[i] = coef[i - 1] * 0.9;
  int tc;
  cin >> tc;
  while (tc--) {
    int n;
    cin >> n;
    cin >> c >> t;
    for (int i = 0; i < n; i++) {
      cin >> ap[i].first >> ap[i].second;
    }
    sort(ap, ap + n);
    reverse(ap, ap + n);
    for (int i = 0; i < 2; i++) {
      for (int j = 0; j <= 100; j++) {
        for (int k = 0; k <= 1000; k++) dp[i][j][k] = LINF;
      }
    }
    dp[0][0][0] = 0;
    for (int i = 0; i < n; i++) {
      int nw = (i & 1) ^ 1;
      int cur = i & 1;
      for (int j = 0; j <= i; j++) {
        for (int k = 0; k <= 10 * i; k++) {
          dp[nw][j][k] = min(dp[nw][j][k], dp[cur][j][k]);
          dp[nw][j + 1][k + ap[i].second] =
              min(dp[nw][j + 1][k + ap[i].second],
                  dp[cur][j][k] + ap[i].first / coef[j]);
        }
      }
    }
    int ans = 0;
    for (int i = 0; i <= n; i++) {
      for (int j = 0; j <= 10 * n; j++) {
        double l = 0, r = t;
        for (int iter = 0; iter < 40; iter++) {
          double m1 = l + (r - l) / 3;
          double m2 = m1 + (r - l) / 3;
          if (g(dp[n & 1][i][j], m1) < g(dp[n & 1][i][j], m2)) {
            r = m2;
          } else {
            l = m1;
          }
        }
        if (g(dp[n & 1][i][j], l) + 10 * i <= t) {
          ans = max(ans, j);
        }
      }
    }
    cout << ans << endl;
  }
  return 0;
}
