#include <bits/stdc++.h>
using namespace std;
ifstream fin(".in");
int i, j, n, m, k, sol, s, i2, j2, ii, jj, violas, expected, a, b;
int ma[20][20];
int main() {
  cin >> n >> m >> violas >> expected;
  for (i = 1; i <= violas; ++i) {
    cin >> a >> b;
    ma[a][b] = 1;
  }
  for (i = 1; i <= n; ++i) {
    for (j = 1; j <= m; ++j) {
      for (i2 = i; i2 <= n; ++i2) {
        for (j2 = j; j2 <= m; ++j2) {
          s = 0;
          for (ii = i; ii <= i2; ++ii) {
            for (jj = j; jj <= j2; ++jj) {
              s += ma[ii][jj];
            }
          }
          if (s >= expected) sol++;
        }
      }
    }
  }
  cout << sol;
  return 0;
}
