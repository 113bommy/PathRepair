#include <bits/stdc++.h>
using namespace std;
int main() {
  cin.sync_with_stdio(false);
  cin.tie(0);
  cout.setf(ios::fixed);
  cout.precision(12);
  double a, b, c;
  cin >> a >> b >> c;
  double d = b * b - 4.0 * a * c;
  double x1 = (-b + (sqrt(d))) / (2.0 * a);
  double x2 = (-b - (sqrt(d))) / (2.0 * a);
  cout << max(x1, x2) << "\n" << min(x1, x2);
  return 0;
}
