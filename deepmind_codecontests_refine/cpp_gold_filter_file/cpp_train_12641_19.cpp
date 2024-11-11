#include <bits/stdc++.h>
using namespace std;
long long xp[1000000], yp[1000000];
int main() {
  long long n, m, x, y, z, p, i, xx, yy, tmp;
  cin >> n >> m >> x >> y >> z >> p;
  for (i = 0; i < p; i++) {
    cin >> xp[i] >> yp[i];
  }
  x = x % 4;
  for (i = 0; i < p; i++) {
    xx = xp[i];
    yy = yp[i];
    if (x == 1) {
      xp[i] = yy;
      yp[i] = n - xx + 1;
    } else if (x == 2) {
      xp[i] = n - xx + 1;
      yp[i] = m - yy + 1;
    } else if (x == 3) {
      xp[i] = m - yy + 1;
      yp[i] = xx;
    }
  }
  if (x == 1 || x == 3) {
    tmp = n;
    n = m;
    m = tmp;
  }
  y = y % 2;
  for (i = 0; i < p; i++) {
    xx = xp[i];
    yy = yp[i];
    if (y == 1) {
      xp[i] = xx;
      yp[i] = m - yy + 1;
    }
  }
  z = z % 4;
  z = (4 - z) % 4;
  for (i = 0; i < p; i++) {
    xx = xp[i];
    yy = yp[i];
    if (z == 1) {
      xp[i] = yy;
      yp[i] = n - xx + 1;
    } else if (z == 2) {
      xp[i] = n - xx + 1;
      yp[i] = m - yy + 1;
    } else if (z == 3) {
      xp[i] = m - yy + 1;
      yp[i] = xx;
    }
  }
  for (i = 0; i < p; i++) cout << xp[i] << " " << yp[i] << endl;
  return 0;
}
