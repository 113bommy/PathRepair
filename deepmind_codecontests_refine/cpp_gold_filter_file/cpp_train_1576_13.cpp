#include <bits/stdc++.h>
using namespace std;
int main() {
  double n, r;
  cin >> n >> r;
  cout << setprecision(10) << fixed;
  double d;
  d = cos((360 / n) * 3.14159265358 / 180);
  double ans, a, b, c;
  a = (1 + d);
  b = (d - 1) * 2 * r;
  c = (d - 1) * r * r;
  ans = (-b + sqrt(b * b - 4 * a * c)) / (2 * a);
  cout << ans;
}
