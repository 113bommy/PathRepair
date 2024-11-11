#include <bits/stdc++.h>
using namespace std;
const int maxn = 100000;
int main() {
  double l, d, v, g, r;
  cin >> l >> d >> v >> g >> r;
  double t = d / v;
  int k = t / (g + r);
  double t1 = t - k * (g + r);
  if (t1 >= g) t1 = g + r;
  t = t1 + k * (g + r) + (l - d) / v;
  printf("%.6lf\n", t);
  return 0;
}
