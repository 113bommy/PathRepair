#include <bits/stdc++.h>
using namespace std;
struct Dot {
  int x, y;
  Dot(int _x, int _y) : x(_x), y(_y) {}
  Dot() : x(0), y(0) {}
} a[4], b[4];
int l, r, u, d, l1, r1, u1, d1;
int main() {
  for (int i = 0; i < 4; ++i) scanf("%d%d", &a[i].x, &a[i].y);
  for (int i = 0; i < 4; ++i) scanf("%d%d", &b[i].x, &b[i].y);
  l1 = l = 100;
  r1 = r = -100;
  d1 = d = 100;
  u1 = u = -100;
  for (int i = 0; i < 4; ++i) {
    l = min(l, b[i].x);
    r = max(r, b[i].x);
    d = min(d, b[i].y);
    u = max(u, b[i].y);
  }
  int m = (l + r) >> 1;
  for (int i = 0; i < 4; ++i) {
    l1 = min(l1, a[i].x);
    r1 = max(r1, a[i].x);
    d1 = min(d1, a[i].y);
    u1 = max(u1, a[i].y);
  }
  int m1 = (l1 + r1) >> 1;
  for (int i = d, j = 1; i <= (u + d) >> 1; ++i, ++j) {
    for (int k = m - j + 1; k <= m + j - 1; ++k) {
      if (l1 <= k && k <= r1 && d1 <= i && i <= u1) {
        printf("YES\n");
        return 0;
      }
    }
  }
  for (int i = u, j = 1; i > (u + 1) / 2; --i, ++j) {
    for (int k = m1 - j + 1; k <= m1 + j - 1; ++k) {
      if (l1 <= k && k <= r1 && d1 <= i && i <= u1) {
        printf("YES\n");
        return 0;
      }
    }
  }
  printf("NO\n");
  return 0;
}
