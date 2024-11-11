#include <bits/stdc++.h>
using namespace std;
template <typename T>
bool chkmax(T &x, T y) {
  return x < y ? x = y, true : false;
}
template <typename T>
bool chkmin(T &x, T y) {
  return x > y ? x = y, true : false;
}
const double PI = 3.14159265358979323846;
const double eps = 1e-10;
int n, m, a[55];
double f[55][55][55];
double C[55][55];
void solve() {
  cin >> n >> m;
  for (decay<decltype(m + 1)>::type i = (1), _i = (m + 1); i < _i; ++i)
    cin >> a[i];
  for (decay<decltype(n + 1)>::type i = (0), _i = (n + 1); i < _i; ++i)
    f[i][0][0] = 1;
  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= n; j++) {
      for (int k = 0; k <= n; k++) {
        int mi = (k - 1) * a[i] + 1, mx = k * a[i];
        for (int l = 0; l <= k; l++) {
          for (int p = max(mi, 0); p <= min(mx, j); p++) {
            f[i][j][k] += C[n - j + p][p] * f[i - 1][j - p][l];
          }
        }
        for (int p = 0; p < mi && p <= j; p++)
          f[i][j][k] += C[n - j + p][p] * f[i - 1][j - p][k];
      }
    }
  }
  double ans = 0;
  for (int i = 1; i <= n; i++) ans += f[m][n][i] * i;
  ans /= pow(m, n);
  cout << fixed << setprecision(10) << ans << endl;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  for (int i = 0; i < 55; i++) {
    C[i][0] = 1;
    for (int j = 1; j <= i; j++) {
      C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
    }
  }
  int T = 1;
  while (T--) {
    solve();
  }
  return 0;
}
