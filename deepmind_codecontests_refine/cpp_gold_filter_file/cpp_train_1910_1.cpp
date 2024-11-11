#include <bits/stdc++.h>
using namespace std;
struct point {
  double x, y;
} pt[255], inter, A, B;
int ans[1000010];
double xmult(point p1, point p2, point p0) {
  return (p1.x - p0.x) * (p2.y - p0.y) - (p2.x - p0.x) * (p1.y - p0.y);
}
int dots_inline(point p1, point p2, point p3) {
  return (((xmult(p1, p2, p3)) > 0 ? (xmult(p1, p2, p3))
                                   : -(xmult(p1, p2, p3))) < 1e-8);
}
point intersection(point u1, point u2, point v1, point v2) {
  point ret = u1;
  double t = ((u1.x - v1.x) * (v1.y - v2.y) - (u1.y - v1.y) * (v1.x - v2.x)) /
             ((u1.x - u2.x) * (v1.y - v2.y) - (u1.y - u2.y) * (v1.x - v2.x));
  ret.x += (u2.x - u1.x) * t;
  ret.y += (u2.y - u1.y) * t;
  return ret;
}
int main() {
  int n, m, i, j, k, tmp;
  A.x = 0, A.y = 0;
  B.x = 1, B.y = 0;
  while (scanf("%d%d", &n, &m) != EOF) {
    fill(ans + 1, ans + n + 5, 1);
    for (i = 0; i < m; i++) scanf("%lf%lf", &pt[i].x, &pt[i].y);
    for (i = 0; i < m; i++)
      for (j = 0; j < i; j++)
        if (pt[j].y != pt[i].y) {
          inter = intersection(A, B, pt[j], pt[i]);
          if (inter.x >= 1.0 - 1e-8 && inter.x <= n + 1e-8 &&
              ((((inter.x - floor(inter.x)) > 0
                     ? (inter.x - floor(inter.x))
                     : -(inter.x - floor(inter.x))) < 1e-8) &&
               (((inter.x - ceil(inter.x)) > 0
                     ? (inter.x - ceil(inter.x))
                     : -(inter.x - ceil(inter.x))) < 1e-8))) {
            tmp = 0;
            for (k = 0; k < m; k++)
              if (dots_inline(pt[j], pt[i], pt[k])) tmp++;
            ans[int(inter.x)] = max(ans[int(inter.x)], tmp);
          }
        }
    for (tmp = 0, i = 1; i <= n; i++) tmp += ans[i];
    printf("%d\n", tmp);
  }
  return 0;
}
