#include <bits/stdc++.h>
using namespace std;
double f[201][30][30], u;
int main() {
  int n, m;
  cout.precision(15);
  cin >> n >> m;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  for (int i = 0; i < n; ++i)
    for (int j = i + 1; j < n; ++j) f[0][i][j] = 1;
  u = 1. / (n * (n - 1));
  for (int t = 1; t <= m; ++t) {
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < n; ++j)
        if (i != j) {
          for (int a = 0; a < n; ++a)
            for (int b = a; b < n; ++b) {
              int x = i, y = j;
              if (x >= a && x <= b) x = a + b - x;
              if (y >= a && y <= b) y = a + b - y;
              f[t][i][j] += u * f[t - 1][x][y];
            }
        }
  }
  double ret = 0;
  for (int i = 0; i < n; ++i)
    for (int j = i + 1; j < n; ++j) {
      ret += a[i] > a[j] ? f[m][i][j] : 1 - f[m][i][j];
    }
  cout << ret << endl;
}
