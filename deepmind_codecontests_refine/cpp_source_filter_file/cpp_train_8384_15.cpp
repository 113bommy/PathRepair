#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-8;
double L, v1, v2;
int n, k;
double l, r;
bool check(double t) {
  double lx = L - v1 * t;
  int c;
  if (n % k == 0)
    c = n / k;
  else
    c = n / k + 1;
  return (double)c * (lx / (v2 - v1)) + (double)(c - 1) * (lx / (v1 + v2)) < t;
}
int main() {
  scanf("%d%lf%lf%lf%d", &n, &L, &v1, &v2, &k);
  l = 0;
  r = l / v1;
  for (int i = 1; i <= 1000000; i++) {
    double mid = (l + r) / 2;
    if (check(mid))
      r = mid;
    else
      l = mid;
  }
  printf("%.10lf", l);
  return 0;
}
