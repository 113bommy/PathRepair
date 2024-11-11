#include <bits/stdc++.h>
using namespace std;
long double R[4][2];
int main() {
  int i, j, n;
  scanf("%d", &n);
  printf("%d\n", 4 * n + 1);
  long double L = 20.0 * cos(M_PI / 5.0);
  long double X = L * cos(M_PI / 2.5), Y = L * sin(M_PI / 2.5);
  R[1][0] = 10.0, R[1][1] = 0.0;
  R[2][0] = L * cos(M_PI / 5.0), R[2][1] = L * sin(M_PI / 5.0);
  R[3][0] = -10.0 * cos(M_PI / 2.5), R[3][1] = 10.0 * sin(M_PI / 2.5);
  for (i = 0; i < n; i++)
    for (j = 0; j < 4; j++)
      printf("%.12lf %.12lf\n", (double)(((long double)i) * X + R[j][0]),
             (double)(((long double)i) * Y + R[j][1]));
  printf("%.12lf %.12lf\n", (double)(((long double)n) * X),
         (double)(((long double)n) * Y));
  for (i = 0; i < n; i++)
    printf("%d %d %d %d %d\n", 4 * i + 1, 4 * i + 2, 4 * i + 3, 4 * i + 5,
           4 * i + 4);
  for (i = 0; i <= n; i++) printf("%d ", 4 * i + 1);
  for (i = n - 1; i >= 0; i--)
    printf("%d %d %d %d ", 4 * i + 2, 4 * i + 4, 4 * i + 3, 4 * i + 1);
  return 0;
}
