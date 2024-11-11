#include <bits/stdc++.h>
using namespace std;
int main() {
  long double y1, y2, y3, mx, my, r, k2, b2, x, k, x2, y, su;
  cin >> y1 >> y2 >> y3 >> mx >> my >> r;
  y3 = y3 - r;
  y1 += r;
  k = (2 * y3 - y1 - my) / mx;
  x = (y3 - y1) * mx / (2 * y3 - y1 - my);
  x2 = (y2 - y1) / (k + 1 / k);
  y = k * x2 + y1;
  y = (-1 / k) * x2 + y2;
  su = sqrt((y2 - y) * (y2 - y) + x2 * x2);
  if (su < r) {
    cout << -1;
    return 0;
  }
  cout.precision(20);
  cout << x;
}
