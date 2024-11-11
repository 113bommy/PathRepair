#include <bits/stdc++.h>
using namespace std;
int main() {
  int x, y;
  cin >> x >> y;
  if (x == y)
    ;
  else if (x > 0 && y <= 0 && x == -y + 1)
    ;
  else if (x < 0 && y > 0 && x == -y)
    ;
  else {
    if (x >= 0 && y >= 0) {
      if (x > y)
        y = x;
      else
        x = -y;
    } else if (x <= 0 && y >= 0) {
      if (-x < y)
        x = -y;
      else
        y = x;
    } else if (x <= 0 && y <= 0) {
      if (x < y)
        y = x;
      else
        x = -y + 1;
    } else if (y <= 0 && x >= 0) {
      if (-y > x)
        x = -y + 1;
      else
        y = x;
    }
  }
  int ans = 0, x1 = 1, y1 = 0;
  if (x != 0 && y != 0) {
    while (x1 != x || y1 != y) {
      ans++;
      if (x1 > 0 && y1 <= 0)
        y1 = x1;
      else if (x1 > 0 && y1 > 0)
        x1 = -x1;
      else if (x1 < 0 && y1 > 0)
        y1 = -y1;
      else if (x1 < 0 && y1 < 0)
        x1 = -y1 + 1;
    }
  }
  cout << ans;
  return 0;
}
