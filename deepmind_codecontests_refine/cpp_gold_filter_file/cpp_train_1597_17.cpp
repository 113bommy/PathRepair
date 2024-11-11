#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 210;
long double p[MAX_N];
int a[MAX_N];
double f[MAX_N][MAX_N][2 * MAX_N];
int main() {
  cerr << sizeof(f) << '\n';
  int n, l, k;
  cin >> n >> l >> k;
  for (int i = 0; i < n; i++) {
    cin >> p[i];
    p[i] *= 1e-2;
  }
  for (int i = 0; i < n; i++) cin >> a[i];
  f[0][0][n + min(k, n)] = 1;
  for (int i = 0; i < n; i++)
    for (int j = 0; j <= i; j++)
      for (int k = 0; k <= 2 * n; k++) {
        f[i + 1][j][k] += (1 - p[i]) * f[i][j][k];
        f[i + 1][j + 1][min(k + a[i], 2 * n)] += p[i] * f[i][j][k];
      }
  long double ans = 0;
  for (int j = l; j <= n; j++)
    for (int k = n; k <= 2 * n; k++) ans += f[n][j][k];
  cout << fixed << setprecision(9) << ans << '\n';
  return 0;
}
