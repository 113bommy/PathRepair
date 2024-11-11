#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1);
int n;
int main() {
  scanf("%d", &n);
  if (n == 3 || n == 4) {
    puts("No Solution");
    return 0;
  }
  double v = 5000;
  if (n < 50) v = 500;
  for (int i = 0; i < n; i++) {
    double lx = (v + i * 0.015) * cos(2 * i * pi / n),
           ly = (v + i * 0.015) * sin(2 * i * pi / n),
           rx = (v + ((i + 1) % n) * 0.015) * cos(2 * (i + 1) * pi / n),
           ry = (v + ((i + 1) % n) * 0.015) * sin(2 * (i + 1) * pi / n);
    double a = lx, b = ly, c = lx * lx + ly * ly, d = rx, e = ry,
           f = rx * rx + ry * ry;
    if (fabs(a) < 1e-6) {
      swap(a, d);
      swap(b, e);
      swap(c, f);
    }
    double y = (a * f - c * d) / (a * e - b * d);
    printf("%.6lf %.6lf\n", (c - b * y) / a, y);
  }
  return 0;
}
