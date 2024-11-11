#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, k, c, d, i, j;
  cin >> c >> d >> n >> m >> k;
  int targ = n * m - k;
  int bestres = 100000000;
  if (targ <= 0) {
    cout << 0;
    return 0;
  }
  for (int osn = 0; osn < 1001; osn++) {
    for (int dop = 0; dop < 1001; dop++) {
      if (osn * c + dop * d > bestres) break;
      if (osn * n + dop >= targ) {
        bestres = min(bestres, osn * c + dop * d);
      }
    }
  }
  cout << bestres;
}
