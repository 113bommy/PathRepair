#include <bits/stdc++.h>
using namespace std;
int n, k, e, x[111], y[111], X, Y;
double f[111][111];
int compara(double xx, double yy) {
  if (xx < (yy - 1e-10)) return -1;
  if (xx > (yy + 1e-10)) return 1;
  return 0;
}
double hypot(double xx, double yy) { return sqrt(xx * xx + yy * yy); }
double dist(int i) { return hypot(X - x[i], Y - y[i]); }
double prob(int i, double R) {
  if (compara(dist(i), R) <= 0) return 1.0;
  return exp(1.0 - (dist(i) * dist(i)) / (R * R));
}
double pre(double R) {
  for (int pos = n; pos >= 0; pos--) {
    for (int des = 0; des <= n; des++) {
      if (pos == n) {
        if (des >= k) {
          f[pos][des] = 0.0;
        } else {
          f[pos][des] = 1.0;
        }
      } else {
        double p = prob(pos, R);
        f[pos][des] = p * f[pos + 1][des + 1] + (1.0 - p) * f[pos + 1][des];
      }
    }
  }
  return f[0][0];
}
int main() {
  while (scanf("%d", &n) != EOF) {
    scanf("%d %d", &k, &e);
    scanf("%d %d", &X, &Y);
    for (int i = 0; i < n; i++) {
      scanf("%d %d", &x[i], &y[i]);
    }
    double lo = 0.0, hi = 2000.00;
    for (int it = 0; it < 100; it++) {
      double mid = (hi + lo) / 2.0;
      if (compara(pre(mid), (((double)e) / 1000.00)) <= 0) {
        hi = mid;
      } else {
        lo = mid;
      }
    }
    printf("%.20lf\n", lo);
  }
  return 0;
}
