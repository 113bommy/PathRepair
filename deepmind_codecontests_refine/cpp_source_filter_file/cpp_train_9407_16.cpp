#include <bits/stdc++.h>
using namespace std;
const int maxn = 500000 + 66;
const long long mod = 1e9 + 7;
int n, k;
int main() {
  double y1, y2, yw, xb, yb, r;
  scanf("%lf %lf %lf %lf %lf %lf", &y1, &y2, &yw, &xb, &yb, &r);
  double a = yw - y1 - 2 * r;
  double b = yw - yb - r;
  double x = a * xb / (a + b);
  double l = sqrt(x * x + a * a);
  double ans = x * (y2 - y1 - r) * xb / l;
  if (r - ans > 1e-10)
    cout << "-1" << endl;
  else
    printf("%.10lf", x);
}
