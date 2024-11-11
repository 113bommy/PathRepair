#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int x = 0;
  char ch = getchar();
  bool positive = 1;
  for (; ch < '0' || ch > '9'; ch = getchar())
    if (ch == '-') positive = 0;
  for (; ch >= '0' && ch <= '9'; ch = getchar()) x = x * 10 + ch - '0';
  return positive ? x : -x;
}
const double EPS = 1e-9;
int N;
double Ax, Ay, Az, vx, vy, vz, Ar, Bx, By, Bz, Br;
inline double work(double Bx, double By, double Bz, double Br) {
  double a = 0, b = 0, c = 0;
  a += vx * vx, b += 2 * vx * (Ax - Bx), c += (Ax - Bx) * (Ax - Bx);
  a += vy * vy, b += 2 * vy * (Ay - By), c += (Ay - By) * (Ay - By);
  a += vz * vz, b += 2 * vz * (Az - Bz), c += (Az - Bz) * (Az - Bz);
  c -= (Ar + Br) * (Ar + Br);
  double delta = b * b - 4 * a * c;
  if (delta < -EPS) return 1 << 30;
  if (delta < 0) delta = 0;
  double x1 = (-b + sqrt(delta)) / (2 * a), x2 = (-b - sqrt(delta)) / (2 * a);
  if (x1 > x2) swap(x1, x2);
  if (x2 < -EPS) return 1 << 30;
  return max(x1, 0.0);
}
int main() {
  Ax = read(), Ay = read(), Az = read();
  vx = read(), vy = read(), vz = read();
  Ar = read();
  double ans = 1 << 30;
  N = read();
  for (int i = 1; i <= N; ++i) {
    Bx = read(), By = read(), Bz = read(), Br = read();
    ans = min(ans, work(Bx, By, Bz, Br));
    int m = read();
    for (int i = 1; i <= m; ++i) {
      double x = read(), y = read(), z = read();
      ans = min(ans, work(Bx + x, By + y, Bz + z, 0));
    }
  }
  if (ans < 1 << 30)
    printf("%.10lf\n", ans);
  else
    printf("-1\n");
  return 0;
}
