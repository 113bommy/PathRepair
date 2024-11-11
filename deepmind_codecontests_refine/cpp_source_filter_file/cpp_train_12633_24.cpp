#include <bits/stdc++.h>
using namespace std;
const int maxn = 110;
long double pi = acosl(-1);
struct point {
  long double x, y;
  point(long double x = 0, long double y = 0) : x(x), y(y) {}
  point operator+(const point& A) const { return point(x + A.x, y + A.y); }
  void display() { printf("%.20Lf %.20Lf\n", x, y); }
} pt[maxn * 5];
int main() {
  long double r = (long double)10 / cosl((long double)54 * pi / 180);
  long double len = (long double)10 * sinl((long double)54 * pi / 180) * 2;
  int n;
  scanf("%d", &n);
  int ind = 0;
  pt[ind++] = point(0, r);
  for (int i = 1; i < 4; i++) {
    long double xx = cosl((long double)72 * pi / 180),
                yy = sinl((long double)72 * pi / 180);
    pt[ind++] = point(pt[i - 1].x * xx - pt[i - 1].y * yy,
                      pt[i - 1].x * yy + pt[i - 1].y * xx);
  }
  for (int i = 1; i < n; i++) {
    for (int j = 0; j < 4; j++, ind++) pt[ind] = pt[ind - 4] + point(len, 0);
  }
  pt[ind] = pt[ind - 3] + point(len, 0);
  ind++;
  printf("%d\n", ind);
  for (int i = 0; i < ind; i++) pt[i].display();
  for (int i = 0; i < n; i++) {
    int st = i * 4;
    for (int j = 0; j < 4; j++) printf("%d ", st + j + 1);
    if (i == n - 1)
      printf("%d\n", ind);
    else
      printf("%d\n", st + 4 + 1 + 1);
  }
  printf("2");
  for (int i = 1; i < n; i++) printf(" %d", i * 4 + 1 + 1);
  printf(" %d", ind);
  for (int i = n - 1; i >= 0; i--) {
    int st = i * 4;
    printf(" %d %d %d %d", st + 2 + 1, st + 1, st + 3 + 1, st + 1 + 1);
  }
  puts("");
  return 0;
}
