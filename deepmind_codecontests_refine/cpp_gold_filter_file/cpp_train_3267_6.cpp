#include <bits/stdc++.h>
using namespace std;
struct point {
  double x, y, z;
};
point pt[11111], a, v, u;
int n;
double f, ans1, ans2, t1, t2;
const double inf = 1e9, eps = 1e-9;
int main() {
  int i, j, s, p, q;
  scanf("%d", &n);
  for (i = 0; i < n; i++) scanf("%lf%lf", &pt[i].x, &pt[i].y);
  scanf("%lf%lf%lf%lf%lf", &a.x, &a.y, &v.x, &v.y, &v.z);
  scanf("%lf", &f);
  scanf("%lf%lf%lf", &u.x, &u.y, &u.z);
  double a1, b1, c1, a2, b2, c2, aa1, bb1, cc1, aa2, bb2, cc2;
  a1 = v.x + u.x * v.z / fabs(u.z);
  b1 = u.x * f / fabs(u.z);
  c1 = a.x;
  a2 = v.y + u.y * v.z / fabs(u.z);
  b2 = u.y * f / fabs(u.z);
  c2 = a.y;
  ans1 = ans2 = inf;
  for (i = 0; i < n; i++) {
    double x1, y1, x2, y2;
    x1 = pt[i].x;
    y1 = pt[i].y;
    x2 = pt[(i + 1) % n].x;
    y2 = pt[(i + 1) % n].y;
    aa1 = a2 * (x2 - x1) - a1 * (y2 - y1);
    bb1 = b2 * (x2 - x1) - b1 * (y2 - y1);
    cc1 = (c2 - y2) * (x2 - x1) - (c1 - x2) * (y2 - y1);
    if (fabs(bb1) > eps) {
      t1 = 0;
      t2 = -cc1 / bb1;
      if (a1 * t1 + b1 * t2 + c1 > min(x1, x2) - eps &&
          a1 * t1 + b1 * t2 + c1 < max(x1, x2) + eps) {
        if (t2 > -eps && a2 * t1 + b2 * t2 + c2 > min(y1, y2) - eps &&
            a2 * t1 + b2 * t2 + c2 < max(y1, y2) + eps &&
            v.z * t1 + f * t2 > -eps) {
          if (ans1 > t1 + eps) {
            ans1 = t1;
            ans2 = t2;
          } else if (fabs(ans1 - t1) < eps && ans2 > t2)
            ans2 = t2;
        }
      }
    }
    if (fabs(aa1) > eps) {
      t1 = -cc1 / aa1;
      t2 = 0;
      if (t1 > -eps) {
        if (a1 * t1 + b1 * t2 + c1 > min(x1, x2) - eps &&
            a1 * t1 + b1 * t2 + c1 < max(x1, x2) + eps) {
          if (a2 * t1 + b2 * t2 + c2 > min(y1, y2) - eps &&
              a2 * t1 + b2 * t2 + c2 < max(y1, y2) + eps &&
              v.z * t1 + f * t2 > -eps) {
            if (ans1 > t1 + eps) {
              ans1 = t1;
              ans2 = t2;
            } else if (fabs(ans1 - t1) < eps && ans2 > t2)
              ans2 = t2;
          }
        }
      }
    }
    double A, B;
    A = a1 * b2 - a2 * b1;
    B = (c1 - x1) * b2 - (c2 - y1) * b1;
    if (fabs(A) > eps) {
      t1 = -B / A;
      B = (c2 - y1) * a1 - (c1 - x1) * a2;
      t2 = -B / A;
      if (t1 > -eps && t2 > -eps) {
        if (a1 * t1 + b1 * t2 + c1 > min(x1, x2) - eps &&
            a1 * t1 + b1 * t2 + c1 < max(x1, x2) + eps) {
          if (a2 * t1 + b2 * t2 + c2 > min(y1, y2) - eps &&
              a2 * t1 + b2 * t2 + c2 < max(y1, y2) + eps &&
              v.z * t1 + f * t2 > -eps) {
            if (ans1 > t1 + eps) {
              ans1 = t1;
              ans2 = t2;
            } else if (fabs(ans1 - t1) < eps && ans2 > t2)
              ans2 = t2;
          }
        }
      }
      B = (c1 - x2) * b2 - (c2 - y2) * b1;
      t1 = -B / A;
      B = (c2 - y2) * a1 - (c1 - x2) * a2;
      t2 = -B / A;
      if (t1 > -eps && t2 > -eps) {
        if (a1 * t1 + b1 * t2 + c1 > min(x1, x2) - eps &&
            a1 * t1 + b1 * t2 + c1 < max(x1, x2) + eps) {
          if (a2 * t1 + b2 * t2 + c2 > min(y1, y2) - eps &&
              a2 * t1 + b2 * t2 + c2 < max(y1, y2) + eps &&
              v.z * t1 + f * t2 > -eps) {
            if (ans1 > t1 + eps) {
              ans1 = t1;
              ans2 = t2;
            } else if (fabs(ans1 - t1) < eps && ans2 > t2)
              ans2 = t2;
          }
        }
      }
    }
    A = (bb1 * v.z / f - aa1);
    B = cc1;
    if (fabs(A) > eps) {
      t1 = B / A;
      t2 = -v.z * t1 / f;
      if (t1 > -eps && t2 > -eps) {
        if (a1 * t1 + b1 * t2 + c1 > min(x1, x2) - eps &&
            a1 * t1 + b1 * t2 + c1 < max(x1, x2) + eps) {
          if (a2 * t1 + b2 * t2 + c2 > min(y1, y2) - eps &&
              a2 * t1 + b2 * t2 + c2 < max(y1, y2) + eps) {
            if (ans1 > t1 + eps) {
              ans1 = t1;
              ans2 = t2;
            } else if (fabs(ans1 - t1) < eps && ans2 > t2)
              ans2 = t2;
          }
        }
      }
    }
  }
  if (ans1 == inf) ans1 = ans2 = -1;
  printf("%.20f %.20f\n", ans1, ans2);
  return 0;
}
