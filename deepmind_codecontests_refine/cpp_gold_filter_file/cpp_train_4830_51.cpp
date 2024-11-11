#include <bits/stdc++.h>
using namespace std;
struct vec {
  double dx, dy;
} A[105];
double Sx, Sy;
int main() {
  int n, m, i, j, k, l;
  scanf("%d", &n);
  srand((unsigned)time(NULL) * n);
  if (n < 5) {
    printf("No solution\n");
    return 0;
  }
  Sx = 0;
  Sy = 0;
  double deg = 0, det = 3.1415926535 * 2 / n;
  j = 10;
  for (i = 1; i <= n; i++) {
    j += rand() % 11 + 1;
    A[i].dx = cos(deg) * j / (10.0);
    A[i].dy = sin(deg) * j / (10.0);
    Sx += A[i].dx;
    Sy += A[i].dy;
    deg += det;
  }
  if (Sx > (1e-5)) {
    for (i = 1; i <= n; i++)
      if (A[i].dx < -(1e-5)) break;
    double t = -Sx / A[i].dx;
    Sy += A[i].dy * t;
    Sx += A[i].dx * t;
    A[i].dy += t * A[i].dy;
    A[i].dx += t * A[i].dx;
  } else if (Sx < -(1e-5)) {
    for (i = 1; i <= n; i++)
      if (A[i].dx > (1e-5)) break;
    double t = -Sx / A[i].dx;
    Sy += A[i].dy * t;
    Sx += A[i].dx * t;
    A[i].dy += t * A[i].dy;
    A[i].dx += t * A[i].dx;
  }
  if (fabs(Sy) > (1e-5)) {
    int tx, ty;
    for (i = 1; i <= n; i++)
      if (A[i].dy * Sy < -(1e-5))
        for (j = i + 1; j <= n; j++)
          if (A[j].dy * Sy < -(1e-5) && A[i].dx * A[j].dx < -(1e-5)) {
            tx = i;
            ty = j;
          }
    double t2 = (A[tx].dx * Sy) / (A[ty].dx * A[tx].dy - A[tx].dx * A[ty].dy),
           t1 = -(A[ty].dx * t2) / A[tx].dx;
    Sx += t1 * A[tx].dx + t2 * A[ty].dx;
    Sy += t1 * A[tx].dy + t2 * A[ty].dy;
    A[tx].dx += t1 * A[tx].dx;
    A[tx].dy += t1 * A[tx].dy;
    A[ty].dx += t2 * A[ty].dx;
    A[ty].dy += t2 * A[ty].dy;
  }
  double tx = 0, ty = 0;
  for (i = 1; i <= n; i++) {
    tx += A[i].dx;
    ty += A[i].dy;
    printf("%.5f %.5f\n", tx, ty);
  }
  return 0;
}
