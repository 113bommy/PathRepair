#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
struct point {
  double x, y, ans;
};
const int M = 10;
point p[1111], a[M];
double w, h;
int n;
double dis(point a, point b) {
  double x = (a.x - b.x) * (a.x - b.x);
  double y = (a.y - b.y) * (a.y - b.y);
  return sqrt(x + y);
}
int sgn(double x) {
  if (x > 1e-14) return 1;
  if (x < -1e-14) return -1;
  return 0;
}
double cal(point a) {
  double Min1 = 1e10, Min2 = 1e10;
  double tmp;
  int i;
  for (i = 1; i <= n; i++) {
    tmp = dis(a, p[i]);
    if (sgn(tmp - Min1) == -1)
      Min2 = Min1, Min1 = tmp;
    else if (sgn(tmp - Min2) == -1)
      Min2 = tmp;
  }
  return Min2;
}
int main() {
  scanf("%lf%lf%d", &w, &h, &n);
  int i;
  for (i = 1; i <= n; i++) scanf("%lf%lf", &p[i].x, &p[i].y);
  for (i = 0; i < M; i++) {
    a[i].x = 1.0 * (rand() % 100) / 100 * w;
    a[i].y = 1.0 * (rand() % 100) / 100 * h;
    a[i].ans = cal(a[i]);
  }
  double L = sqrt(w * w + h * h);
  while (L > 1e-11) {
    for (i = 0; i < M; i++) {
      point pp = a[i];
      int j;
      for (j = 0; j < 5; j++) {
        double ang = rand() % 100 / 100.0 * (2 * acos(-1.0));
        double xx = a[i].x + L * cos(ang);
        double yy = a[i].y + L * sin(ang);
        if (xx < 0 || xx > w || yy < 0 || yy > h) continue;
        point b;
        b.x = xx;
        b.y = yy;
        double tmp = cal(b);
        if (sgn(tmp - pp.ans) == 1) {
          pp = b;
          pp.ans = tmp;
        }
      }
      a[i] = pp;
    }
    L = L * 0.99;
  }
  double ans = 0;
  for (i = 0; i < M; i++)
    if (sgn(a[i].ans - ans) == 1) {
      ans = a[i].ans;
    }
  printf("%.12lf\n", ans);
}
