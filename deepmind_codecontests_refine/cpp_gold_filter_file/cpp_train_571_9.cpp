#include <bits/stdc++.h>
using namespace std;
int n;
const int maxn = 100005;
double x[maxn], y[maxn];
double dist2(int i, int j) {
  return (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]);
}
void project_on_segment(int i, int j, int k, double &a, double &b) {
  double r = dist2(i, j);
  if (fabs(r) < 1e-12) {
    a = x[i];
    b = y[i];
    return;
  }
  r = ((x[k] - x[i]) * (x[j] - x[i]) + (y[k] - y[i]) * (y[j] - y[i])) / r;
  if (r < 1e-12) {
    a = x[i];
    b = y[i];
    return;
  }
  if (r + 1e-12 > 1.0) {
    a = x[j];
    b = y[j];
    return;
  }
  a = x[i] + (x[j] - x[i]) * r;
  b = y[i] + (y[j] - y[i]) * r;
}
int main() {
  scanf("%d%lf%lf", &n, &x[0], &y[0]);
  for (int i = 1; i <= n; ++i) scanf("%lf%lf", &x[i], &y[i]);
  x[n + 1] = x[1];
  y[n + 1] = y[1];
  double R1 = 1e100, R2 = 0;
  for (int i = 1; i <= n; ++i) {
    double a, b;
    project_on_segment(i, i + 1, 0, a, b);
    R1 = min(R1, (x[0] - a) * (x[0] - a) + (y[0] - b) * (y[0] - b));
    R2 = max(R2, max(dist2(0, i), dist2(0, i + 1)));
  }
  printf("%.6lf\n", (R2 - R1) * M_PI);
}
