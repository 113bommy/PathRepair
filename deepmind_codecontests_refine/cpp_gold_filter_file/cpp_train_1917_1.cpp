#include <bits/stdc++.h>
using namespace std;
int n;
double t, x[111], v[111], m[111];
int main() {
  scanf("%d%lf", &n, &t);
  for (int i = 0; i < n; i++) scanf("%lf%lf%lf", &x[i], &v[i], &m[i]);
  while (true) {
    double t0 = 1e100;
    for (int i = 0; i < n - 1; i++)
      for (int j = i + 1; j < n; j++)
        if (abs(v[i] - v[j]) >= 1e-9) {
          double t1 = (x[j] - x[i]) / (v[i] - v[j]);
          if (t1 > 0 && t0 > t1) t0 = t1;
        }
    if (t0 > t || abs(t0 - t) < 1e-9) {
      for (int i = 0; i < n; i++) x[i] = x[i] + v[i] * t;
      break;
    }
    if (t0 < t) {
      t -= t0;
      for (int i = 0; i < n; i++) x[i] = x[i] + v[i] * t0;
      for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
          if (abs(x[i] - x[j]) < 1e-9) {
            double w0 =
                ((m[i] - m[j]) * v[i] + 2 * m[j] * v[j]) / (m[i] + m[j]);
            double w1 =
                ((m[j] - m[i]) * v[j] + 2 * m[i] * v[i]) / (m[i] + m[j]);
            v[i] = w0;
            v[j] = w1;
            break;
          }
    }
  }
  for (int i = 0; i < n; i++) printf("%.9lf\n", x[i]);
  return 0;
}
