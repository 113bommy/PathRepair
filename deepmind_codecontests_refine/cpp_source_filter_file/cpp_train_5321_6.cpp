#include <bits/stdc++.h>
using namespace std;
const int N = 101;
const long double eps = 1e-8;
long double a[N], c[N], dp[N][N][10 * N], z[N][N];
int b[N];
int main() {
  int i, j, n, k, x, l, tc;
  long double C, T;
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> tc;
  for (int test = 0; test < tc; ++test) {
    vector<pair<long double, int> > v;
    cin >> n >> C >> T;
    for (i = 0; i < n; ++i) {
      cin >> a[i] >> b[i];
      v.push_back({-a[i], b[i]});
    }
    sort(v.begin(), v.end());
    for (i = 0; i < n; ++i) {
      a[i] = -v[i].first;
      b[i] = v[i].second;
    }
    c[0] = 0.9;
    for (i = 1; i <= n; ++i) c[i] = c[i - 1] * 0.9;
    for (i = 0; i < n; ++i)
      for (j = 0; j <= n; ++j) z[i][j] = a[i] / c[j];
    for (i = 0; i <= n; ++i)
      for (j = 0; j <= i; ++j)
        for (l = 0; l <= 10 * j; ++l) dp[i][j][l] = 1e50;
    dp[0][0][0] = 0;
    for (i = 0; i < n; ++i)
      for (j = 0; j <= i; ++j)
        for (l = 0; l <= 10 * j; ++l) {
          dp[i + 1][j][l] = min(dp[i + 1][j][l], dp[i][j][l]);
          dp[i + 1][j + 1][l + b[i]] =
              min(dp[i + 1][j + 1][l + b[i]], dp[i][j][l] + a[i] / c[j]);
        }
    int ans = 0;
    for (j = 0; j <= n; ++j)
      for (l = 0; l <= 10 * j; ++l) {
        long double x = dp[n][j][l];
        long double F = T - 10 * j;
        long double kA = C * C, kB = 1 - C * F, kC = x - F;
        long double D = kB * kB - 4 * kA * kC;
        if (F >= 0 && D >= 0 && sqrt(D) - kB >= -eps &&
            (-sqrt(D) - kB) / (2 * kA) <= F - eps)
          ans = max(ans, l);
      }
    cout << ans << endl;
  }
}
