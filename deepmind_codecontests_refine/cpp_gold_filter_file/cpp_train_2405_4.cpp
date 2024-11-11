#include <bits/stdc++.h>
using namespace std;
long long x, y, ax[4], ay[4], by, bx, xx, yy;
bool ok() {
  long long d = abs(x * x + y * y);
  for (int i = 0; i < 4; i++) {
    xx = ax[i] - bx;
    yy = ay[i] - by;
    if ((xx == 0 && yy == 0) || ((x || y) && abs(x * xx + y * yy) % d == 0 &&
                                 abs(y * xx - x * yy) % d == 0)) {
      return true;
    }
  }
  return false;
}
int main() {
  cin >> ax[0] >> ay[0] >> bx >> by >> x >> y;
  for (int i = 1; i <= 3; i++) {
    ax[i] = ay[i - 1];
    ay[i] = -ax[i - 1];
  }
  if (ok())
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return 0;
}
