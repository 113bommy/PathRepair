#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1.0);
const double eps = 1e-9;
double theta;
double a, b, L;
double calcu(double x) {
  return (b * L * cos(x) - L * L * cos(x) * sin(x) + a * L * sin(x)) / L;
}
double mini(double a, double b) { return a < b ? a : b; }
double maxi(double a, double b) { return a > b ? a : b; }
int main() {
  scanf("%lf%lf%lf", &a, &b, &L);
  double l = 0, r = pi / 2, mid1, mid2;
  while (l + eps < r) {
    mid1 = (l + r) / 2;
    mid2 = (l + mid1) / 2;
    if (calcu(mid1) > calcu(mid2))
      r = mid1;
    else
      l = mid2;
  }
  if (calcu(mid1) < eps)
    printf("My poor head =(\n");
  else {
    double tp = maxi(a, b), tm;
    if (L < tp)
      tm = mini(a, b);
    else
      tm = 0;
    printf("%.7lf\n", mini(L, maxi(tm, calcu(mid1))));
  }
  return 0;
}
