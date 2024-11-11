#include <bits/stdc++.h>
using namespace std;
double x[1000], y[1000];
double sum, a, b, c, k;
double d(double x1, double x2, double y1, double y2) {
  double a, b, c;
  a = (x1 - x2);
  b = (y1 - y2);
  c = sqrt((a * a) + (b * b));
  return c;
}
int main() {
  int n, i, j;
  scanf("%d %lf", &n, &k);
  for (i = 0; i < n; i++) {
    scanf("%lf %lf", &x[i], &y[i]);
  }
  sum = 0;
  for (i = 0; i < n - 1; i++) {
    sum += d(x[i], x[i + 1], y[i], y[i + 1]);
  }
  sum = sum / (50 * k);
  printf("%.9lf\n", sum);
}
