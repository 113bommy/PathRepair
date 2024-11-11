#include <bits/stdc++.h>
using namespace std;
const int MX = 1500 + 5;
const int INF = 0x3f3f3f3f;
const double exps = 1e-10;
const double pi = acos(-1.0);
int T, X, Y, n;
double fx[MX], fy[MX], best[MX], tmp[MX];
double PX[MX], PY[MX];
double Rand(double L, double R) {
  return (rand() % (1000)) / 1000.0 * (R - L) + L;
}
double dist(double x1, double y1, double x2, double y2) {
  return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}
int main() {
  srand(time(NULL));
  while (~scanf("%d%d%d", &X, &Y, &n)) {
    for (int i = 1; i <= n; i++) {
      scanf("%lf%lf", &PX[i], &PY[i]);
    }
    for (int i = 1; i <= 10; i++) {
      fx[i] = Rand(1, X);
      fy[i] = Rand(1, Y);
      double tp1 = 1e100, tp2 = 1e100;
      for (int j = 1; j <= n; j++) {
        tp2 = min(tp2, dist(fx[i], fy[i], PX[j], PY[j]));
        if (tp2 < tp1) {
          double tt = tp2;
          tp2 = tp1;
          tp1 = tt;
        }
      }
      best[i] = tp2;
    }
    double step = max(X, Y);
    while (step > exps) {
      for (int i = 1; i <= 10; i++) {
        for (int j = 1; j <= 10; j++) {
          double angel = Rand(0, 2 * pi);
          double nx = fx[i] + cos(angel) * step;
          double ny = fy[i] + sin(angel) * step;
          if (nx < 0 || nx > X || ny < 0 || ny > Y) continue;
          double d = INF;
          double tp1 = 1e100, tp2 = 1e100;
          for (int k = 1; k <= n; k++) {
            tp2 = min(tp2, dist(nx, ny, PX[k], PY[k]));
            if (tp2 < tp1) {
              double tt = tp2;
              tp2 = tp1;
              tp1 = tt;
            }
          }
          d = tp2;
          if (d > best[i]) {
            best[i] = d;
            fx[i] = nx;
            fy[i] = ny;
          }
        }
      }
      step *= 0.97;
    }
    double t = 0;
    for (int i = 1; i <= 30; i++) {
      t = max(t, best[i]);
    }
    printf("%.17f\n", sqrt(t));
  }
  return 0;
}
