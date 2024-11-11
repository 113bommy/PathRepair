#include <bits/stdc++.h>
using namespace std;
long double p, ans, f[2005][2005];
int main() {
  int n, t;
  cin >> n >> p >> t;
  f[0][0] = 1;
  for (int i = (0); i <= (t - 1); ++i) {
    f[i + 1][n] += f[i][n];
    for (int j = (0); j <= (n - 1); ++j) {
      f[i + 1][j + 1] += p * f[i][j];
      f[i + 1][j] += (1 - p) * f[i][j];
    }
  }
  for (int i = (0); i <= (n); ++i) ans += f[t][i] * i;
  printf("%.10Lf\n", ans);
  return 0;
}
