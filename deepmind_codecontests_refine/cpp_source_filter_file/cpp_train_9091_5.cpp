#include <bits/stdc++.h>
using namespace std;
int main() {
  int x1, x2, y1, y2, r1, r2;
  cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
  long double dist = sqrt(((x2 - x1) * (x2 - x1)) + ((y2 - y1) * (y2 - y1)));
  long double hi = 1e-7;
  if (dist > r1 + r2)
    cout << fixed << setprecision(20) << (dist - r1 - r2) / 2;
  else if (dist < abs(r1 - r2))
    cout << fixed << setprecision(20) << abs(r1 - r2) - dist;
  else
    cout << 0;
  return 0;
}
