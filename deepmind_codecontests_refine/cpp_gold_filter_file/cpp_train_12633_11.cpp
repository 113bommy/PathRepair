#include <bits/stdc++.h>
double PI;
int main() {
  static double xx[4], yy[4];
  int n, h, i;
  double a, ca, sa, c2a, s2a;
  PI = acos(-1);
  scanf("%d", &n);
  printf("%d\n", 1 + n * 4);
  a = PI * 2 / 5;
  ca = cos(a), sa = sin(a);
  c2a = cos(a * 2), s2a = sin(a * 2);
  xx[0] = -ca, yy[0] = sa;
  xx[1] = 1 + ca + c2a, yy[1] = sa + s2a;
  xx[2] = 1 + ca, yy[2] = sa;
  xx[3] = 1, yy[3] = 0;
  printf("%.9f %.9f\n", 0.0, 0.0);
  for (i = 0; i < n; i++)
    for (h = 0; h < 4; h++) {
      double x = (xx[h] + i) * 10;
      double y = yy[h] * (i % 2 == 0 ? 10 : -10);
      printf("%.9f %.9f\n", x, y);
    }
  for (i = 0; i < n; i++)
    printf("%d %d %d %d %d\n", i * 4 + 1, i * 4 + 2, i * 4 + 3, i * 4 + 4,
           i * 4 + 5);
  printf("1");
  for (i = 0; i < n; i++) printf(" %d %d", i * 4 + 3, i * 4 + 5);
  for (i = n - 1; i >= 0; i--)
    printf(" %d %d %d", i * 4 + 2, i * 4 + 4, i * 4 + 1);
  printf("\n");
  return 0;
}
