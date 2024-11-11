#include <bits/stdc++.h>
using namespace std;
bool st = false;
double con(double x, double y, double in) {
  if (x == 0 && y == 0) return 0;
  if (x == 0 && y != 0) {
    st = true;
    return 10000000000LL;
  }
  return (y * in) / x;
}
int main() {
  double a, b, c, d, e, f;
  cin >> a >> b >> c >> d >> e >> f;
  string hr = "Hermione\n";
  string rn = "Ron\n";
  if (d == 0) {
    cout << hr;
    return 0;
  }
  if (c == 0) {
    cout << rn;
    return 0;
  }
  if (b == 0) {
    cout << hr;
    return 0;
  }
  if (a == 0) {
    cout << rn;
    return 0;
  }
  if (f == 0) {
    cout << hr;
    return 0;
  }
  if (e == 0) {
    cout << rn;
    return 0;
  }
  if (a * c * e < b * d * f)
    cout << rn;
  else
    cout << hr;
  return 0;
}
