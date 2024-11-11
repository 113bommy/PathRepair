#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:1000000000,1000000000")
using namespace std;
const long long inf = 1e18 + 7;
const long long mod = 1e9 + 7;
const double eps = 1e-9;
const double PI = 2 * acos(0.0);
const double E = 2.71828;
void Solve() {
  long double a, b;
  cin >> a >> b;
  cout << setprecision(10) << fixed;
  long double s = 2.0 * a * b;
  if (b < eps) {
    cout << 1 << endl;
    return;
  }
  if (a < eps) {
    cout << 0.5 << endl;
    return;
  }
  long double y = b - a / 4.0;
  if (y < eps) {
    cout << (s - 4.0 * b * b / 2.0) / s << endl;
    return;
  }
  cout << (s - (y + b) * a / 2.0) / s << endl;
}
int main(void) {
  long long T;
  cin >> T;
  for (long long(i) = 0; (i) < (long long)(T); (i)++) {
    Solve();
  }
  return 0;
}
