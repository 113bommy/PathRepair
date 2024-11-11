#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-8;
bool check(int n, int l, int v1, int v2, int k, double mid) {
  double t0 = (l - v2 * mid) / (v1 - v2);
  if (t0 < eps) return 0;
  double tb = mid - t0;
  if (tb < eps) return 0;
  double tback = (v2 - v1) * tb / (v2 + v1) + tb;
  if (tback + eps < tb) return 0;
  return (n - 1) / k * tback + tb < mid + eps &&
         (n - 1) / k * (tb - tback) * v2 + tb * v2 < l + eps;
}
int main() {
  int n, l, v1, v2, k;
  scanf("%d%d%d%d%d", &n, &l, &v1, &v2, &k);
  double ll = 0, rr = 1. * l / v1;
  for (int i = 1; i <= 100; i++) {
    double mid = (ll + rr) / 2;
    if (check(n, l, v1, v2, k, mid))
      rr = mid;
    else
      ll = mid;
  }
  printf("%.10f", ll);
}
