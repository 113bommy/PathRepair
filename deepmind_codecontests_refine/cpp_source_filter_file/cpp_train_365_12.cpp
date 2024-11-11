#include <bits/stdc++.h>
int a, b, c, d, e, f, g, h, i, j;
struct node {
  int x, y;
};
struct node Point[1005];
struct node ch;
int left, right;
int Cover(struct node x, struct node y, struct node z, int xx, int yy) {
  int ii, jj, kk;
  double alpha, beta, cita;
  ch.x = xx;
  ch.y = yy;
  alpha = atan2(x.x - y.x, x.y - y.y) - atan2(ch.x - y.x, ch.y - y.y) +
          2 * 3.141592653589793238462643;
  while (alpha - 2 * 3.141592653589793238462643 > -(1e-9))
    alpha -= 2 * 3.141592653589793238462643;
  beta = atan2(ch.x - y.x, ch.y - y.y) - atan2(z.x - y.x, z.y - y.y) +
         2 * 3.141592653589793238462643;
  while (beta - 2 * 3.141592653589793238462643 > -(1e-9))
    beta -= 2 * 3.141592653589793238462643;
  cita = atan2(x.x - y.x, x.y - y.y) - atan2(z.x - y.x, z.y - y.y) +
         2 * 3.141592653589793238462643;
  while (cita - 2 * 3.141592653589793238462643 > -(1e-9))
    cita -= 2 * 3.141592653589793238462643;
  if (fabs(alpha + beta - cita) <= 1e-9) return 1;
  return 0;
}
int main() {
  scanf("%d", &a);
  for (i = 1; i <= a; i++) scanf("%d%d", &Point[i].x, &Point[i].y);
  left = Point[1].x;
  right = Point[2].x;
  Point[a + 1] = Point[1];
  if (left > right) {
    e = left;
    left = right;
    right = e;
  }
  for (i = 3; i <= a; i++) {
    for (; left <= right; left++)
      if (Cover(Point[i - 1], Point[i], Point[i + 1], left, Point[1].y)) break;
    for (; right >= left; right--)
      if (Cover(Point[i - 1], Point[i], Point[i + 1], right, Point[1].y)) break;
  }
  printf("%d\n", right - left + 1);
  return 0;
}
