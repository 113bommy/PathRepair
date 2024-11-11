#include <bits/stdc++.h>
using namespace std;
int main() {
  int x1, x2, y1, y2;
  cin >> x1 >> y1 >> x2 >> y2;
  int flag1 = 0;
  int x3 = 0, x4 = 0, y3 = 0, y4 = 0;
  if (abs(x1 - x2) == 0 || abs(y1 - y2) == 0) {
    flag1 = 1;
  }
  if (flag1 == 1) {
    if (abs(x1 - x2) == 0) {
      x3 = abs(y1 - y2) + x1;
      x4 = x3;
      y3 = y1;
      y4 = y2;
    } else {
      y3 = abs(x1 - x2) + y1;
      y4 = y3;
      x3 = x1;
      x4 = x2;
    }
  } else {
    if (abs(y1 - y2) == abs(x1 - x2)) {
      x3 = x1;
      y3 = y2;
      x4 = x2;
      y4 = y1;
    } else {
      cout << -1 << endl;
      return 0;
    }
  }
  cout << x3 << " " << y3 << " " << x4 << " " << y4 << endl;
  return 0;
}
