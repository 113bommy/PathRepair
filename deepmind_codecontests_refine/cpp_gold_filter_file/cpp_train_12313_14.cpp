#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, x, y;
  cin >> a >> x >> y;
  if (y % a == 0) {
    cout << "-1";
    return 0;
  }
  if (y / a == 0 || (y / a) % 2 == 1)
    if ((a % 2 == 0 && x < a / 2 && x > -(a / 2)) ||
        (a % 2 == 1 && x <= a / 2 && x >= (-a / 2))) {
      if (y / a == 0)
        cout << 1;
      else
        cout << ((y / a) / 2) * 3 + 2;
      return 0;
    } else {
      cout << -1;
      return 0;
    }
  else if (x >= a || x <= -a || x == 0) {
    cout << -1;
    return 0;
  } else {
    if (x < 0)
      cout << 3 * ((y / a) / 2);
    else
      cout << 3 * ((y / a) / 2) + 1;
  }
  return 0;
}
