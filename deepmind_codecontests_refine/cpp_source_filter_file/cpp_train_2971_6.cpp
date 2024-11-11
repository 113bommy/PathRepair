#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c, d, e, f, x, y, m = 0;
  cin >> a >> b >> c >> d >> e >> f;
  x = max((a * 1000), 1000);
  y = x;
  if (a == 0 && b >= 0) {
    x = b * x;
    if (b > 0 && d > 0) m = 1;
  } else
    x = (b * x) / a;
  if (c == 0 && d >= 0) {
    x = d * y;
    if ((d > 0)) m = 1;
  } else
    x = (d * x) / c;
  x = x - 1;
  if (e == 0 && f >= 0)
    x = f * y;
  else
    x = (f * x) / e;
  if ((x >= y && (d > 0)) || (m == 1))
    cout << "Ron" << endl;
  else
    cout << "Hermione" << endl;
  return 0;
}
