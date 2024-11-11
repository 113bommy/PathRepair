#include <bits/stdc++.h>
using namespace std;
int main() {
  int x1, x2, y1, y2, x3, x4, y3, y4;
  cin >> x1 >> y1 >> x2 >> y2;
  bool b = 1;
  if (x1 != x2 && y1 != y2) {
    if (abs(x2 - x1) != abs(y2 - y1))
      cout << "-1";
    else
      cout << x1 << ' ' << y2 << ' ' << x2 << ' ' << y1;
  } else if (x1 == x2 && y1 != y2) {
    int c = abs(y1 - y2);
    cout << x1 + c << ' ' << y1 << ' ' << x2 + c << ' ' << y2;
  } else if (y1 == y2 && x1 != x2) {
    int c = abs(x1 - x2);
    cout << x1 << ' ' << y1 + c << ' ' << x2 << ' ' << y2 + c;
  } else
    cout << "-1";
  return 0;
}
