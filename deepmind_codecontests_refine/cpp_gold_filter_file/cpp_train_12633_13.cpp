#include <bits/stdc++.h>
int n;
const double ang = 36.0 / 180.0 * acos(-1);
double t = 10.0 * cos(ang) * 2;
struct Coord {
  Coord(double x, double y) : x(x), y(y) {}
  double x, y;
};
Coord get_coord(const Coord &start, int idx) {
  double x = start.x;
  double y = start.y;
  double tx = x + t, ty = y;
  if (idx == 1) return Coord(x, y);
  if (idx == 2) return Coord(x + 10.0 * cos(ang), y + 10.0 * sin(ang));
  if (idx == 3) return Coord(tx, ty);
  if (idx == 4) return Coord(x + t * cos(ang), y - t * sin(ang));
  if (idx == 5) return Coord(tx - t * cos(ang), ty - t * sin(ang));
  return Coord(-1, -1);
}
int main() {
  scanf("%d", &n);
  int m = 4 * n + 1;
  printf("%d\n", m);
  for (int idx = 1; idx <= 5; ++idx) {
    Coord c = get_coord(Coord(0, 0), idx);
    printf("%0.15lf %0.15lf\n", c.x, c.y);
  }
  for (int i = 2; i <= n; ++i) {
    for (int j = 4 * i - 2; j <= 4 * i + 1; ++j) {
      Coord c = get_coord(Coord(i * t - t, 0), j - (4 * i - 2) + 2);
      printf("%0.15lf %0.15lf\n", c.x, c.y);
    }
  }
  for (int i = 1; i <= n; ++i) {
    if (i == 1)
      for (int j = 1; j <= 5; ++j) printf("%d ", j);
    else {
      printf("%d ", 4 * i - 5);
      for (int j = 1; j <= 4; ++j) printf("%d ", 4 * i - 3 + j);
    }
    printf("\n");
  }
  printf("1 ");
  for (int i = 2; i <= n; ++i) printf("%d ", i * 4 - 5);
  for (int i = n; i >= 1; --i)
    printf("%d %d %d %d ", i * 4 - 1, i * 4 + 1, i * 4 - 2, i * 4);
  printf("1\n");
}
