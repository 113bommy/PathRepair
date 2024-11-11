#include <bits/stdc++.h>
using namespace std;
const int N = 2e3 + 10;
int n, t;
double f[N][N], p;
signed main() {
  ios::sync_with_stdio(false);
  cin >> n >> p >> t;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= t; j++) {
      f[i][j] = (f[i - 1][j - 1] + 1) * p + f[i][j - 1] * (1 - p);
    }
  }
  cout << setprecision(10) << f[n][t] << endl;
  return 0;
}
