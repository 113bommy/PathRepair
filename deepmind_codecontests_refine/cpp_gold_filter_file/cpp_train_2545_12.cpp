#include <bits/stdc++.h>
using namespace std;
int dif(int x, int y);
int main() {
  int a, b, x1, x2, y1, y2;
  cin >> x1 >> y1 >> x2 >> y2;
  a = dif(x1, x2);
  b = dif(y1, y2);
  if (a == b) {
    cout << x1 << " " << y2 << " " << x2 << " " << y1;
  } else if (a && !b) {
    cout << x1 << " " << y1 + a << " " << x2 << " " << y2 + a;
  } else if (b && !a) {
    cout << x1 + b << " " << y1 << " " << x2 + b << " " << y2;
  } else
    cout << "-1";
  return 0;
}
int dif(int x, int y) {
  if (x >= 0 && y >= 0)
    return abs(y - x);
  else if (y < x)
    return abs(y) + x;
  else
    return abs(x) + y;
}
