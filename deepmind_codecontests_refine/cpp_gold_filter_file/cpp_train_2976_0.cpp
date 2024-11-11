#include <bits/stdc++.h>
using namespace std;
template <class T>
bool umin(T& a, T b) {
  if (a > b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T>
bool umax(T& a, T b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
double a[100009], b[100009], c[100009], p;
int n;
double ok(double x) {
  double sum = 0;
  for (int i = 1; i <= n; i++) {
    c[i] = b[i] - a[i] * x;
    if (c[i] < 0) sum += (-1.0 * c[i]) / p;
  }
  return sum;
}
int main() {
  scanf("%d%lf", &n, &p);
  for (int i = 1; i <= n; i++) scanf("%lf%lf", &a[i], &b[i]);
  if (ok(1e15) <= 1e15) {
    puts("-1");
    return 0;
  }
  double st = 0, en = 1e15;
  while (st + (1e-9) < en) {
    double mid = (st + en) / 2.0;
    if (ok(mid) - (1e-9) <= mid)
      st = mid;
    else
      en = mid;
  }
  if (ok(en) - (1e-9) <= en)
    printf("%.12lf\n", en);
  else
    printf("%.12lf\n", st);
  return 0;
}
