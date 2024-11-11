#include <bits/stdc++.h>
using namespace std;
int n, m, R, r, ax, ay, az, vx, vy, vz, ox, oy, oz, ex, ey, ez;
double gao(int x, int y, int z, int o) {
  int a = vx * vx + vy * vy + vz * vz;
  int b = -2 * (x * vx + y * vy + z * vz);
  int c = x * x + y * y + z * z - o * o;
  long long d = 1ll * b * b - 4ll * a * c;
  if (d < 0) return 1e10;
  double p = (-b + sqrt(d)) / a / 2;
  double q = (-b - sqrt(d)) / a / 2;
  return min(p < 0 ? 1e10 : p, q < 0 ? 1e10 : q);
}
int main() {
  scanf("%d%d%d", &ax, &ay, &az);
  scanf("%d%d%d", &vx, &vy, &vz);
  scanf("%d%d", &R, &n);
  double ans = 1e10;
  for (int i = 0; i < n; i++) {
    scanf("%d%d%d%d%d", &ox, &oy, &oz, &r, &m);
    ans = min(ans, gao(ox - ax, oy - ax, oz - ax, R + r));
    for (int i = 0; i < m; i++) {
      scanf("%d%d%d", &ex, &ey, &ez);
      ans = min(ans, gao(ox + ex - ax, oy + ey - ax, oz + ez - ax, R));
    }
  }
  if (ans > 1e9)
    puts("-1");
  else
    printf("%.12f\n", ans);
}
