#include <bits/stdc++.h>
using namespace std;
double EPS = 1e-6;
void handle(int rz, int vz, int z_1, int z_2, double &l, double &r) {
  if (vz == 0) {
    if (rz < z_1 || rz > z_2) {
      puts("-1");
      exit(0);
    }
  }
  if (vz > 0) {
    l = max(l, (z_1 - rz) * 1. / vz);
    r = min(r, (z_2 - rz) * 1. / vz);
  }
  if (vz < 0) {
    l = max(l, (z_2 - rz) * 1. / vz);
    r = min(r, (z_1 - rz) * 1. / vz);
  }
}
int main() {
  int n;
  scanf("%d", &n);
  int x_1, y_1, x_2, y_2;
  scanf("%d%d%d%d", &x_1, &y_1, &x_2, &y_2);
  double l = 0, r = 1e9;
  for (int i = 0; (i) < (n); ++i) {
    int rx, ry, vx, vy;
    scanf("%d%d%d%d", &rx, &ry, &vx, &vy);
    handle(rx, vx, x_1, x_2, l, r);
    handle(ry, vy, y_1, y_2, l, r);
  }
  if (r <= l + EPS) {
    puts("-1");
    return 0;
  }
  printf("%.20f\n", l);
  return 0;
}
