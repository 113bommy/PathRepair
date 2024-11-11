#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-7;
struct P {
  double x, y, z;
} p[105];
int n;
double dis(P a, P b) {
  return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y) +
              (a.z - b.z) * (a.z - b.z));
}
P solve() {
  if (n == 1) return p[0];
  double step = 100, ans = 1e30, mt;
  P z;
  z.x = z.y = z.z = 0;
  int s = 0;
  while (step > eps) {
    for (int i = 0; i < n; i++)
      if (dis(z, p[s]) < dis(z, p[i])) s = i;
    mt = dis(z, p[s]);
    ans = min(ans, mt);
    z.x += (p[s].x - z.x) / mt * step;
    z.y += (p[s].y - z.y) / mt * step;
    z.z += (p[s].z - z.z) / mt * step;
    step *= 0.999;
  }
  return z;
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%lf%lf%lf", &p[i].x, &p[i].y, &p[i].z);
  P z = solve();
  printf("%.10f %.10f %.10f\n", z.x, z.y, z.z);
  return 0;
}
