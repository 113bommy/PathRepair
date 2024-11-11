#include <bits/stdc++.h>
int main(int argc, char** argv) {
  double x1, y1, x2, y2, x3, y3, x5, y5, x1tab[10000], y1tab[10000],
      x5tab[10000], y5tab[10000], angle[10000], w[10000];
  int k, n;
  double length;
  double miny[10001];
  scanf("%lf%lf%lf%lf", &x2, &y2, &x3, &y3);
  length =
      sqrt(x2 * x2 - 2 * x2 * x3 + x3 * x3 + y2 * y2 - 2 * y2 * y3 + y3 * y3);
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%lf%lf%lf%lf", &x5tab[i], &y5tab[i], &angle[i], &w[i]);
    x1tab[i] = cos(angle[i]);
    y1tab[i] = sin(angle[i]);
  }
  scanf("%d", &k);
  for (int i = 0; i < n; i++) {
    x1 = x1tab[i];
    y1 = y1tab[i];
    x5 = x5tab[i];
    y5 = y5tab[i];
    double a, b, c, d, e;
    a = x1 * (x3 - x2) /
            sqrt(x2 * x2 - 2 * x2 * x3 + x3 * x3 + y2 * y2 - 2 * y2 * y3 +
                 y3 * y3) +
        y1 * (y3 - y2) /
            sqrt(x2 * x2 - 2 * x2 * x3 + x3 * x3 + y2 * y2 - 2 * y2 * y3 +
                 y3 * y3);
    b = x1 * (x2 - x5) + y1 * (y2 - y5);
    c = (x3 - x2) * (x3 - x2) /
            (x2 * x2 - 2 * x2 * x3 + x3 * x3 + y2 * y2 - 2 * y2 * y3 +
             y3 * y3) +
        (y3 - y2) * (y3 - y2) /
            (x2 * x2 - 2 * x2 * x3 + x3 * x3 + y2 * y2 - 2 * y2 * y3 + y3 * y3);
    d = (2 * (x2 - x5)) * (x3 - x2) /
            sqrt(x2 * x2 - 2 * x2 * x3 + x3 * x3 + y2 * y2 - 2 * y2 * y3 +
                 y3 * y3) +
        (2 * (y2 - y5)) * (y3 - y2) /
            sqrt(x2 * x2 - 2 * x2 * x3 + x3 * x3 + y2 * y2 - 2 * y2 * y3 +
                 y3 * y3);
    e = (x2 - x5) * (x2 - x5) + (y2 - y5) * (y2 - y5);
    double min1 =
        acos((a * length + b) / sqrt(c * length * length + d * length + e)) /
        w[i] / length;
    for (int j = 1; j < 100; j++) {
      double x = length * j / 100;
      double min2 = acos((a * x + b) / sqrt(c * x * x + d * x + e)) / w[i] / x;
      if (min2 < min1) min1 = min2;
    }
    miny[i] = 1 / min1;
  }
  if (k >= n) {
    printf("%.4f", 0);
  } else {
    std::sort(miny, miny + n);
    printf("%.4f", miny[n - k - 1]);
  }
}
