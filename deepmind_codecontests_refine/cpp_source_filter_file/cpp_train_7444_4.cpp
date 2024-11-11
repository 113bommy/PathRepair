#include <bits/stdc++.h>
using namespace std;
const int maxn = 100010;
int n;
double p, q;
double a[maxn], b[maxn];
double f(double x1) {
  double x2 = 1;
  for (int i = 1; i <= n; i++) x2 = min(x2, (1. - a[i] * x1) / b[i]);
  return x1 * p + x2 * q;
}
void Work() {
  double l = 0, r = 1;
  for (int i = 1; i <= n; i++) r = min(r, 1. / a[i]);
  while (r - l > 1e-8) {
    double M1 = (l + l + r) / 3, M2 = (l + r + r) / 3;
    if (f(M1) > f(M2))
      r = M2;
    else
      l = M1;
  }
  printf("%.10lf\n", f((l + r) / 2));
}
void Init() {
  scanf("%d%lf%lf", &n, &p, &q);
  for (int i = 1; i <= n; i++) scanf("%lf%lf", &a[i], &b[i]);
}
int main() {
  Init();
  Work();
  return 0;
}
