#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c, s;
  cin >> s >> a >> b >> c;
  if (a == b && b == c && c == 0) {
    cout << "0.0 0.0 0.0";
    return 0;
  }
  double k = (double)s / (a + b + c);
  cout << setprecision(10) << fixed;
  double x = (double)k * a - 0.0000000001;
  if (x < 0) x = 0;
  double y = (double)k * b - 0.0000000001;
  if (y < 0) y = 0;
  double z = (double)k * c - 0.0000000001;
  if (z < 0) z = 0;
  cout << x << ' ' << y << ' ' << z;
  return 0;
}
