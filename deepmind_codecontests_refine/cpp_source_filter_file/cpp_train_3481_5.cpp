#include <bits/stdc++.h>
using namespace std;
struct Point {
  int x, y;
  bool operator<(const Point& other) const {
    return x < other.x || (x == other.x && y < other.y);
  }
} p[10];
Point read() {
  char st[10];
  scanf("%s", st);
  Point p;
  p.x = st[0] - 'a' + 1;
  p.y = st[1] - '0';
  return p;
}
int mid(int a, int b, int c) {
  int s[] = {a, b, c};
  sort(s, s + 3);
  return s[1];
}
bool check() {
  for (int i = -1; i <= 1; ++i)
    for (int j = -1; j <= 1; ++j) {
      int x = p[3].x + i, y = p[3].y + j;
      if (x > 8 || x < 1 || y > 8 || y < 1) continue;
      if (x == p[1].x && y != p[1].y &&
          (p[2].x != x || mid(p[2].y, p[1].y, y) != p[2].y))
        continue;
      if (x == p[0].x && y != p[0].y &&
          (p[2].x != x || mid(p[2].y, p[0].y, y) != p[2].y))
        continue;
      if (y == p[0].y && x != p[0].x &&
          (p[2].y != y || mid(p[2].x, p[0].x, x) != p[2].x))
        continue;
      if (y == p[1].y && y != p[1].y &&
          (p[2].y != y || mid(p[2].x, p[1].x, x) != p[2].x))
        continue;
      if (abs(x - p[2].x) <= 1 && abs(y - p[2].y) <= 1 &&
          (x != p[2].x || y != p[2].y))
        continue;
      return false;
    }
  return true;
}
int main() {
  int i, j;
  for (i = 0; i < 4; ++i) p[i] = read();
  if (check())
    puts("CHECKMATE");
  else
    puts("OTHER");
  return 0;
}
