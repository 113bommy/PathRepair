#include <bits/stdc++.h>
using namespace std;
bool isLargerOrEq(long double a, long double b) {
  const long double eps = 1e-14;
  return a + eps >= b;
}
int main() {
  int y1, y2, yw, xb, yb, r;
  cin >> y1 >> y2 >> yw >> xb >> yb >> r;
  long double t1 = (yw - r) - (y1 + r);
  long double t2 = (yw - r) - (yb);
  t2 = t1 / (t1 + t2);
  long double xw = xb * t2;
  t2 = (y2 - y1) / (long double)r - 1;
  cout.precision(20);
  if (isLargerOrEq(t2, 0) && isLargerOrEq(t2 * t2, 1 + t1 * t1 / xw / xw))
    cout << xw << endl;
  else
    cout << "-1" << endl;
  return 0;
}
