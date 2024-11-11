#include <bits/stdc++.h>
using namespace std;
int main() {
  double l, d, v, g, r;
  cin >> l >> d >> v >> g >> r;
  double x = d / v - floor(d / v / (g + r)) * (g + r);
  if (x < g)
    printf("%.8lf\n", l / v);
  else
    printf("%.8lf\n", l / v + g + r - x);
  return 0;
}
