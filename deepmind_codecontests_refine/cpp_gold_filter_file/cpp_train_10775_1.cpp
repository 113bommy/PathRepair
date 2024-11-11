#include <bits/stdc++.h>
using namespace std;
const int INF = (int)(INT_MAX / 2);
const int N = (int)(0);
const long long mod = (int)(1e+9 + 7);
int main() {
  long double x1, y1, r1, x2, y2, r2;
  cin >> x1 >> y1 >> r1;
  cin >> x2 >> y2 >> r2;
  long double s = 0;
  long double r = hypot(x2 - x1, y2 - y1);
  if (r1 + r2 <= r) return puts("0"), 0;
  if (r2 - r1 >= r) {
    cout << setprecision(18) << acos(-1.0) * r1 * r1;
    return 0;
  }
  if (r1 - r2 >= r) {
    cout << setprecision(18) << acos(-1.0) * r2 * r2;
    return 0;
  }
  long double a1 = acos((r1 * r1 + r * r - r2 * r2) / (2.0 * r * r1));
  s += r1 * r1 * a1 - r1 * r1 * sin(a1) * cos(a1);
  long double a2 = acos((r2 * r2 + r * r - r1 * r1) / (2.0 * r * r2));
  s += r2 * r2 * a2 - r2 * r2 * sin(a2) * cos(a2);
  cout << setprecision(18) << s;
  return 0;
}
