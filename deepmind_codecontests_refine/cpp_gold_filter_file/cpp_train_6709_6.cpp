#include <bits/stdc++.h>
using namespace std;
inline int IN() {
  int x = 0, ch = getchar(), f = 1;
  while (!isdigit(ch) && (ch != '-') && (ch != EOF)) ch = getchar();
  if (ch == '-') {
    f = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = (x << 1) + (x << 3) + ch - '0';
    ch = getchar();
  }
  return x * f;
}
double nx, ny, T, nc, w, h, Dist[1005];
int n;
struct Point {
  double x, y;
} a[1005];
double dir[4][2] = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
double sqr(double a) { return a * a; }
double dist(double xa, double ya, double xb, double yb) {
  return sqrt(sqr(xb - xa) + sqr(yb - ya));
}
double Calc(double x, double y) {
  for (int i = 0; i <= n - 1; i++) Dist[i] = dist(x, y, a[i].x, a[i].y);
  double Min1 = 1 << 30, pos1, Min2 = 1 << 30;
  for (int i = 0; i <= n - 1; i++)
    if (Dist[i] < Min1) Min1 = Dist[i], pos1 = i;
  for (int i = 0; i <= n - 1; i++)
    if (i != pos1 && Dist[i] < Min2) Min2 = Dist[i];
  return Min2;
}
int main() {
  srand((unsigned)time(NULL));
  double Max = 0;
  w = 1.0 * IN(), h = 1.0 * IN(), n = IN();
  for (int i = 0; i <= n - 1; i++) a[i].x = IN(), a[i].y = IN();
  for (int i = 1; i <= 60; i++) {
    double nx = rand() * rand() % (int)w, ny = rand() * rand() % (int)h;
    T = h, nc = Calc(nx, ny);
    while (T > 1e-12) {
      bool chg = 0;
      double X, Y;
      for (int j = 0; j <= 3; j++) {
        double x = nx + T * dir[j][0], y = ny + T * dir[j][1];
        if (x < 0 || x > w || y < 0 || y > h) continue;
        double xc = Calc(x, y);
        if (xc > nc) {
          X = x, Y = y, nc = xc;
          chg = 1;
        }
      }
      if (chg) {
        nx = X, ny = Y;
      } else
        T *= 0.9;
    }
    Max = max(Max, Calc(nx, ny));
  }
  printf("%.15lf\n", Max);
}
