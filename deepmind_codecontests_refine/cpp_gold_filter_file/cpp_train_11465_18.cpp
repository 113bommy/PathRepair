#include <bits/stdc++.h>
using namespace std;
double a, b, r, s, d;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> d;
    a = 0, b = d;
    r = 1, s = 0;
    while (r >= 0.0000000000001) {
      s = 0;
      double x = a, y = b;
      while (s < 10 * r) {
        if ((a + s) * (b - s) > x * y and (a + s) * (b - s) <= d) {
          x = a + s;
          y = b - s;
        }
        s += r;
      }
      a = x, b = y;
      r /= 10;
    }
    double diff = d - a * b;
    if (diff > 0.000001) {
      cout << "N\n";
    } else {
      cout << "Y ";
      cout << setprecision(11) << a << " " << b << "\n";
    }
  }
  return 0;
}
