#include <bits/stdc++.h>
double h, w, r;
double f(double, double);
int main(void) {
  scanf("%lf", &r);
  for (w = 1; w <= 10; ++w) {
    for (h = 1; h <= 10; ++h) {
      if (((r - f(w / 2, h)) > 0 ? (r - f(w / 2, h)) : (-(r - f(w / 2, h)))) <=
          1e-6) {
        printf("%f %f\n", w, h);
        return 0;
      }
    }
  }
  return 0;
}
double f(double a, double h) { return a * h / sqrt(a * a + h * h); }
