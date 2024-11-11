#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e3 + 5;
const int INF = 200000000;
const double EPS = 1e-6;
int x[10];
int y[10];
bool onseg(double x1, double y1, double x2, double y2, double x, double y) {
  if (min(x1, x2) < x + EPS && x < max(x1, x2) + EPS && min(y1, y2) < y + EPS &&
      y < max(y1, y2) + EPS) {
    return true;
  } else
    return false;
}
int intersect(double a1, double b1, double c1, double a2, double b2, double c2,
              double &x, double &y) {
  double dt = a1 * b2 - a2 * b1;
  double d1 = c1 * b2 - c2 * b1;
  double d2 = a1 * c2 - a2 * c1;
  if (fabs(dt) < EPS) {
    if (fabs(d1) < EPS && fabs(d2) < EPS) {
      return 2;
    } else {
      return 0;
    }
  }
  x = -d1 / dt;
  y = -d2 / dt;
  return 1;
}
int main() {
  for (int i = 0; i < 6; i++) {
    scanf("%d%d", &x[i], &y[i]);
  }
  double xm = (x[0] + x[1]) * 0.5;
  double ym = (y[0] + y[1]) * 0.5;
  double a1 = y[0] - y[1];
  double b1 = x[1] - x[0];
  double c1 = -a1 * x[0] - b1 * y[0];
  double a2 = -b1 * b1;
  double b2 = a1 * b1;
  double c2 = -a2 * xm - b2 * ym;
  double aw = y[2] - y[3];
  double bw = x[3] - x[2];
  double cw = -aw * x[2] - bw * y[2];
  double am = y[4] - y[5];
  double bm = x[5] - x[4];
  double cm = -am * x[4] - bm * y[4];
  double xn = 0, yn = 0;
  if (intersect(a1, b1, c1, aw, bw, cw, xn, yn)) {
    if (onseg(x[0], y[0], x[1], y[1], xn, yn) &&
            onseg(x[2], y[2], x[3], y[3], xn, yn) ||
        intersect(a1, b1, c1, aw, bw, cw, xn, yn) == 2 &&
            onseg(x[0], y[0], x[1], y[1], x[2], y[2]) &&
            onseg(x[0], y[0], x[1], y[1], x[3], y[3])) {
      xn = 0;
      yn = 0;
      if (intersect(a1, b1, c1, am, bm, cm, xn, yn) == 1 &&
          onseg(x[0], y[0], x[1], y[1], xn, yn) &&
          onseg(x[4], y[4], x[5], y[5], xn, yn)) {
        printf("NO");
        return 0;
      } else {
        xn = 0;
        yn = 0;
        double amp = -bm * bm;
        double bmp = am * bm;
        double cmp1 = -amp * x[0] - bmp * y[0];
        double cmp2 = -amp * x[1] - bmp * y[1];
        double xm1 = 0, ym1 = 0, xm2 = 0, ym2 = 0;
        int f1 = intersect(amp, bmp, cmp1, am, bm, cm, xm1, ym1);
        int f2 = intersect(amp, bmp, cmp2, am, bm, cm, xm2, ym2);
        if (f1 == 1 || f2 == 1) {
          double d1 =
              fabs(am * x[0] + bm * y[0] + cm) / sqrt(am * am + bm * bm);
          double d2 =
              fabs(am * x[1] + bm * y[1] + cm) / sqrt(am * am + bm * bm);
          double k = d1 / d2;
          xn = (xm1 + k * xm2) / (1 + k);
          yn = (ym1 + k * ym2) / (1 + k);
          if (onseg(x[4], y[4], x[5], y[5], xn, yn)) {
            double av = y[0] - yn;
            double bv = xn - x[0];
            double cv = -av * x[0] - bv * y[0];
            double xc = 0, yc = 0;
            if (intersect(av, bv, cv, aw, bw, cw, xc, yc)) {
              if (onseg(x[2], y[2], x[3], y[3], xc, yc) &&
                      onseg(x[0], y[0], xn, yn, xc, yc) ||
                  intersect(av, bv, cv, aw, bw, cw, xc, yc) == 2) {
                printf("NO");
                return 0;
              }
            }
            double ap = y[1] - yn;
            double bp = xn - x[1];
            double cp = -ap * x[1] - bp * y[1];
            xc = 0;
            yc = 0;
            if (intersect(ap, bp, cp, aw, bw, cw, xc, yc)) {
              if (onseg(x[2], y[2], x[3], y[3], xc, yc) &&
                      onseg(x[1], y[1], xn, yn, xc, yc) ||
                  intersect(av, bv, cv, aw, bw, cw, xc, yc) == 2) {
                printf("NO");
                return 0;
              }
            }
          } else {
            printf("NO");
            return 0;
          }
        } else {
          printf("NO");
          return 0;
        }
      }
    } else {
      xn = 0;
      yn = 0;
      if (intersect(a1, b1, c1, am, bm, cm, xn, yn) == 1) {
        if (onseg(x[0], y[0], x[1], y[1], xn, yn) &&
            onseg(x[4], y[4], x[5], y[5], xn, yn)) {
          printf("NO");
          return 0;
        }
      } else {
        printf("YES");
        return 0;
      }
    }
  } else {
    xn = 0;
    yn = 0;
    if (intersect(a1, b1, c1, am, bm, cm, xn, yn) == 1) {
      if (onseg(x[0], y[0], x[1], y[1], xn, yn) &&
          onseg(x[4], y[4], x[5], y[5], xn, yn)) {
        printf("NO");
        return 0;
      }
    } else {
      printf("YES");
      return 0;
    }
  }
  printf("YES");
  return 0;
}
