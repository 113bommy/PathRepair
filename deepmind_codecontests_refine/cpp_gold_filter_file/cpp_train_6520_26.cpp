#include <bits/stdc++.h>
using namespace std;
int ax, ay, az, vx, vy, vz, R, n, m;
int ox, oy, oz, r, px, py, pz;
double ans = 1e15;
void calc(int x, int y, int z, int r) {
  long long A, B, C, delta;
  double x1, x2, s;
  x = ax - x;
  y = ay - y;
  z = az - z;
  A = vx * vx + vy * vy + vz * vz;
  B = 2 * (vx * x + vy * y + vz * z);
  C = x * x + y * y + z * z - r * r;
  delta = B * B - 4 * A * C;
  if (delta < 0) return;
  s = sqrt(delta);
  x1 = (-B - s) / (2 * A);
  x2 = (-B + s) / (2 * A);
  if (x1 >= 1e-9) ans = ((x1) < (ans) ? (x1) : (ans));
  if (x2 >= 1e-9) ans = ((x2) < (ans) ? (x2) : (ans));
}
int main() {
  scanf("%d%d%d%d%d%d%d", &ax, &ay, &az, &vx, &vy, &vz, &R);
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d%d%d%d%d", &ox, &oy, &oz, &r, &m);
    calc(ox, oy, oz, r + R);
    while (m--) {
      scanf("%d%d%d", &px, &py, &pz);
      calc(ox + px, oy + py, oz + pz, R);
    }
  }
  if (ans == 1e15)
    puts("-1");
  else
    printf("%.8lf\n", ans);
  return 0;
}
