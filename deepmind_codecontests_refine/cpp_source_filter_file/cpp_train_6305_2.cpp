#include <bits/stdc++.h>
using namespace std;
int main() {
  long long x, y, z, k, xx = 0, yy = 0, zz = 0, minn;
  cin >> x >> y >> z >> k;
  if (k >= x + y + z - 3) {
    cout << x * y * z << endl;
    return 0;
  }
  minn = min(min(x, y), z);
  minn--;
  if (k - 3 * (minn) > 0) {
    k = k - 3 * (minn);
    xx = minn;
    yy = minn;
    zz = minn;
    y = y - yy;
    x = x - yy;
    z = z - yy;
    if (x == 1) {
    } else if (y == 1) {
      int t = x;
      x = y;
      y = t;
    } else if (z == 1) {
      int t = x;
      x = z;
      z = x;
    }
    minn = min(y, z);
    minn--;
    if (k - 2 * (minn) > 0) {
      k = k - 2 * (minn);
      yy += minn;
      zz += minn;
      if (y - yy == 1) {
        cout << (xx + 1) * (yy + 1) * (zz + 1 + k) << endl;
      } else {
        cout << (xx + 1) * (yy + 1 + k) * (zz + 1) << endl;
      }
    } else {
      if (k % 2 == 1) {
        cout << (xx + 1) * (xx + k / 2 + 1 + 1) * (xx + k / 2 + 1) << endl;
      } else {
        cout << (xx + 1) * (xx + k / 2 + 1) * (xx + k / 2 + 1) << endl;
      }
    }
  } else {
    if (k % 3 == 1) {
      cout << (k / 3 + 1) * (k / 3 + 1) * (k / 3 + 1 + 1) << endl;
    } else if (k % 3 == 0) {
      cout << (k / 3 + 1) * (k / 3 + 1) * (k / 3 + 1) << endl;
    } else if (k % 3 == 2) {
      cout << (k / 3 + 1) * (k / 3 + 1 + 1) * (k / 3 + 1 + 1) << endl;
    }
  }
}
