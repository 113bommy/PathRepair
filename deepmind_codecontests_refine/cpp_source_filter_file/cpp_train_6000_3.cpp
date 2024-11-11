#include <bits/stdc++.h>
using namespace std;
int main() {
  int x, xx, y, yy;
  cin >> x >> y >> xx >> yy;
  if ((x == xx && abs(y - yy) == 1) || (y == yy && abs(x - xx) == 1)) {
    cout << 8 << endl;
    return 0;
  } else {
    if (x == xx && y > yy)
      cout << (2 * abs(x - xx)) + (2 * abs(y - (yy - 1))) + 2 << endl;
    else if (x == xx && y < yy)
      cout << (2 * abs(x - xx)) + (2 * abs(y - (yy + 1))) + 2 << endl;
    else if (y == yy && x > xx)
      cout << (2 * abs(x - (xx - 1))) + (2 * abs(y - yy)) + 2 << endl;
    else if (y == yy && x < xx)
      cout << (2 * abs(x - (xx + 1))) + (2 * abs(y - yy)) + 2 << endl;
    else {
      if (x > xx)
        cout << (2 * abs(x - (xx - 1))) + (2 * abs(y - yy)) + 2 << endl;
      else
        cout << (2 * abs(x - (xx + 1))) + (2 * abs(y - yy)) + 2 << endl;
    }
  }
  return 0;
}
