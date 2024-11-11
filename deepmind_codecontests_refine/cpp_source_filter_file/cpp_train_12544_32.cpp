#include <bits/stdc++.h>
using namespace std;
struct Point {
  int x, y, i;
  Point(){};
  Point(int xx, int yy, int ii) {
    x = xx;
    y = yy;
    i = ii;
  }
} p[1000005];
bool cmp(Point a, Point b) {
  if (a.x / 1000 == b.x / 1000) {
    if (a.x / 1000 % 2 == 0) {
      if (a.y < b.y) return true;
      return false;
    } else {
      if (a.y > b.y) return true;
      return false;
    }
  } else {
    if (a.x < b.x) return true;
    return false;
  }
}
int main() {
  int n;
  while (scanf("%d", &n) != EOF) {
    for (int i = 0; i < n; i++) {
      scanf("%d%d", &p[i].x, &p[i].y);
      p[i].i = i + 1;
    }
    sort(p, p + n, cmp);
    printf("%d", p[0]);
    for (int i = 1; i < n; i++) printf(" %d", p[i]);
    puts("");
  }
  return 0;
}
