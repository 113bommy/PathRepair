#include <bits/stdc++.h>
using namespace std;
long long extendedEuclid(long long a, long long b, long long &x, long long &y) {
  if (b == 0) {
    x = 0;
    y = 1;
    return a;
  }
  long long x1, y1;
  long long ret = extendedEuclid(b, a % b, x1, y1);
  x = y1 - b / a * x1;
  y = x1;
  return ret;
}
int32_t main() {
  long long a, b, x, y, c;
  cin >> a >> b >> c;
  long long xxx = extendedEuclid(a, b, x, y);
  c = c * (-1);
  if (c % xxx == 0) {
    cout << x * (c / xxx) << " " << y * (c / xxx) << "\n";
  } else
    cout << "-1"
         << "\n";
}
