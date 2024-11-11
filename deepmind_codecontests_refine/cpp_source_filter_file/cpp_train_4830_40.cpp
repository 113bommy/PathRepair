#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1);
struct point {
  double x, y;
};
struct point a[110];
int n;
int main() {
  int i, j;
  double l, ang;
  scanf("%d", &n);
  if (n <= 3) {
    printf("No solution\n");
    return 0;
  }
  a[1].x = 0;
  a[1].y = 0;
  l = 1000;
  for (i = 2; i <= n; i++) {
    ang = (i - 1) * 2 * pi / n;
    if (i == n) l = -a[i - 1].y / sin(ang);
    a[i].x = a[i - 1].x + l * cos(ang);
    a[i].y = a[i - 1].y + l * sin(ang);
    l *= 1.01;
  }
  for (i = 1; i <= n; i++) printf("%.6lf %.6lf\n", a[i].x, a[i].y);
  return 0;
}
