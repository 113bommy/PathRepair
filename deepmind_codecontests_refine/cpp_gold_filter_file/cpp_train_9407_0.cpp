#include <bits/stdc++.h>
using namespace std;
template <class T>
inline T sqr(T x) {
  return x * x;
}
const double EPS = 1e-6;
const int INF = 0x3fffffff;
const long long LINF = INF * 1ll * INF;
const double PI = acos(-1.0);
using namespace std;
int main(void) {
  double y1, y2, yw, xb, yb, r;
  cin >> y1 >> y2 >> yw >> xb >> yb >> r;
  double tmp = y1;
  y1 = yw - y1 - 2 * r;
  yb = yw - yb - r;
  double xw = xb / ((yb / y1) + 1);
  double a = atan(xw / y1);
  if (r / sin(a) + tmp + r >= y2)
    puts("-1");
  else
    printf("%.9lf\n", xw);
}
