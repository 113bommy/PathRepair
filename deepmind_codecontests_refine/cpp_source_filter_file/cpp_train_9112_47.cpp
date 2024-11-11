#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  double k;
  scanf("%d%lf", &n, &k);
  vector<double> pos(n);
  for (auto& z : pos) scanf("%lf", &z);
  sort(pos.begin(), pos.end());
  double sum = 0;
  for (auto z : pos) sum += z;
  double l = 0.0, r = sum / (1.0 * n), mi = 0.0;
  while (r - l > 1e-6) {
    double mid = (r + l) / 2;
    double h = sum - mid * n;
    for (auto z : pos) {
      if (z < mid) {
        double x = (mid - z) / (1 - k / 100);
        h -= x * k / 100;
      }
    }
    if (h >= 0) {
      mi = mid;
      l = mid;
    } else
      r = mid;
  }
  printf("%0.6lf", mi);
  return 0;
}
