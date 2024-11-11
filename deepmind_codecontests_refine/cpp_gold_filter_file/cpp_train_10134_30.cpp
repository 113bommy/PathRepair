#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-9;
int n, a, d;
double t[111111], v[111111];
double get_time(double v) {
  double x = v * v / (2 * a);
  if (x >= d)
    return sqrt(2.0 * d / a);
  else
    return v / a + (d - x) / v;
}
int main() {
  scanf("%d%d%d", &n, &a, &d);
  for (int i = 0; i < n; ++i) scanf("%lf%lf", &t[i], &v[i]);
  for (int i = 0; i < n; ++i) {
    t[i] += get_time(v[i]);
    if (i > 0) t[i] = max(t[i], t[i - 1]);
  }
  for (int i = 0; i < n; ++i) printf("%.10lf\n", t[i]);
  return 0;
}
