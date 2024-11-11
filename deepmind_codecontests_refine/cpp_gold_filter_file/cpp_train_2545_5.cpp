#include <bits/stdc++.h>
using namespace std;
int main() {
  int x1, x2, x3, x4, y1, y2, y3, y4, l;
  cin >> x1 >> y1 >> x2 >> y2;
  if (abs(x1 - x2) != abs(y1 - y2) && x1 != x2 && y1 != y2) {
    cout << "-1" << endl;
  } else if (x1 == x2) {
    l = abs(y1 - y2);
    x3 = x1 + l;
    y3 = y1 + (y2 - y1);
    x4 = x3;
    y4 = y1;
    cout << x3 << " " << y3 << " " << x4 << " " << y4 << endl;
  } else if (y1 == y2) {
    l = abs(x1 - x2);
    x3 = x1;
    y3 = y1 - l;
    x4 = x2;
    y4 = y3;
    cout << x3 << " " << y3 << " " << x4 << " " << y4 << endl;
  } else {
    x3 = x1;
    y3 = y2;
    x4 = x2;
    y4 = y1;
    cout << x3 << " " << y3 << " " << x4 << " " << y4 << endl;
  }
  return 0;
}
