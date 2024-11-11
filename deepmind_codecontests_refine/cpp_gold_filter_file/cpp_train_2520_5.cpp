#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-8;
const double pi = acos(-1.0);
int dblcmp(double d) {
  if (fabs(d) < eps) return 0;
  return d > eps ? 1 : -1;
}
double x[166], y[166];
int n;
double h(double x, double y) { return sqrt(x * x + y * y); }
int main() {
  int i, j, k;
  cin >> n >> k;
  for (i = 0; i < n; i++) cin >> x[i] >> y[i];
  double ans = 0;
  for (i = 1; i < n; i++) ans += h(x[i] - x[i - 1], y[i] - y[i - 1]);
  printf("%.10lf\n", k * 1.0 * (ans / 50.0));
  return 0;
}
