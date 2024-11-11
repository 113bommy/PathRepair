#include <bits/stdc++.h>
using namespace std;
bool ch(int x1, int y1, int x2, int y2, int& x3, int& y3, int& x4, int& y4,
        int l) {
  if (x2 == x1 && y2 == y1 + l) {
    x3 = x1 + l, y3 = y1, x4 = x3, y4 = y2;
    return 9;
  } else if (x2 == x1 + l && y2 == y1) {
    x3 = x1, y3 = y1 + l, x4 = x2, y4 = y3;
    return 9;
  } else if (x2 == x1 + l && y2 == y1 + l) {
    x3 = x1, y3 = y2, x4 = x2, y4 = y1;
    return 9;
  } else if (x2 == x1 + l && y2 == y1 - l) {
    x3 = x1, y3 = y2, x4 = x2, y4 = y1;
    return 9;
  }
  return 0;
}
int main() {
  int x1, y1, x2, y2, x3, y3, x4, y4, l;
  cin >> x1 >> y1 >> x2 >> y2;
  l = max(abs(x2 - x1), (abs(y2 - y1)));
  if (ch(x1, y1, x2, y2, x3, y3, x4, y4, l)) {
    cout << x3 << " " << y3 << " " << x4 << " " << y4 << endl;
  } else if (ch(x2, y2, x1, y1, x3, y3, x4, y4, l)) {
    cout << x3 << " " << y3 << " " << x4 << " " << y4 << endl;
  } else
    cout << "-1" << endl;
  return 0;
}
