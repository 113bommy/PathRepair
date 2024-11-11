#include <bits/stdc++.h>
using namespace std;
int n, L, v1, v2, k;
int check(double T) {
  double l = L;
  int total = n / k + (n % k != 0);
  double t = T;
  for (int i = 0; i < total; i++) {
    if (t < 0) return 0;
    if (i < total - 1) {
      double x = (l / v1 - t) * v1 * v2 / (v2 - v1);
      if (x < 0)
        return 1;
      else if (x > l)
        return 0;
      else {
        double tt = 2 * x / (v1 + v2);
        t -= tt;
        l -= tt * v1;
      }
    } else {
      t -= l / v2;
    }
  }
  return t >= 0;
}
int main() {
  cin >> n >> L >> v1 >> v2 >> k;
  double le = 0, ri = 10000000000.0;
  for (int i = 0; i < 1000; i++) {
    double mid = (le + ri) / 2;
    if (check(mid))
      ri = mid;
    else
      le = mid;
  }
  printf("%.10lf\n", ri);
  return 0;
}
