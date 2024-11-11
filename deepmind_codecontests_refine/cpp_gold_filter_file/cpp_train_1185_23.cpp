#include <bits/stdc++.h>
using namespace std;
const long long oo = 1e9 + 7;
int main() {
  double a, x1, y1, b, c, d, x, y, k, f;
  int i;
  cin >> a >> b >> c >> d;
  x = a / b;
  y = c / d;
  x1 = x;
  y1 = (1 - x) * (1 - y);
  f = x1;
  for (i = 0; i < 10000; i++) {
    f = x1 + y1 * f;
  }
  cout << fixed << setprecision(12) << f;
  return 0;
}
