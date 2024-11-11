#include <bits/stdc++.h>
struct Point {
  int x, y;
};
struct Poly {
  Point p[4];
  Poly(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4) {
    p[0].x = x1;
    p[0].y = y1;
    p[1].x = x2;
    p[1].y = y2;
    p[2].x = x3;
    p[2].y = y3;
    p[3].x = x4;
    p[3].y = y4;
  }
  void print() const {
    printf("%d %d\n%d %d\n%d %d\n%d %d", p[0].x, p[0].y, p[1].x, p[1].y, p[2].x,
           p[2].y, p[3].x, p[3].y);
  }
  double length() const {
    return sqrt(((double)((p[1].x - p[0].x) * (p[1].x - p[0].x))) +
                ((double)((p[1].y - p[0].y) * (p[1].y - p[0].y)))) +
           sqrt(((double)((p[2].x - p[1].x) * (p[2].x - p[1].x))) +
                ((double)((p[2].y - p[1].y) * (p[2].y - p[1].y)))) +
           sqrt(((double)((p[3].x - p[2].x) * (p[3].x - p[2].x))) +
                ((double)((p[3].y - p[2].y) * (p[3].y - p[2].y))));
  }
};
Poly findMax(Poly* p, int p_len) {
  double maxLen = -1.0, len;
  int i, index = 0;
  for (i = 0; i < p_len; i++) {
    len = p[i].length();
    if (len > maxLen) {
      maxLen = len;
      index = i;
    }
  }
  return p[index];
}
int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  if (n == 0)
    Poly(0, 1, 0, m, 0, 0, 0, m - 1).print();
  else if (m == 0)
    Poly(1, 0, n, 0, 0, 0, n - 1, 0).print();
  else {
    if (n >= 2 && m >= 2) {
      Poly p[6] = {
          Poly(1, 0, n, m, 0, 0, n, m - 1), Poly(1, 0, n, m, 0, 0, n - 1, m),
          Poly(0, 1, n, m, 0, 0, n, m - 1), Poly(0, 1, n, m, 0, 0, n - 1, m),
          Poly(0, 0, n, m, 0, m, n, 0),     Poly(0, 0, n, m, n, 0, 0, m)};
      findMax(p, 6).print();
    } else {
      Poly p[2] = {Poly(0, 0, n, m, 0, m, n, 0), Poly(n, 0, 0, m, 0, 0, n, m)};
      findMax(p, 2).print();
    }
  }
  return 0;
}
