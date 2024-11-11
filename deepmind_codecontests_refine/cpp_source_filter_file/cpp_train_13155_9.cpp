#include <bits/stdc++.h>
using namespace std;
const int maxint = -1u >> 1;
struct point {
  int a, b;
} x[100010], y[100010];
int n, a, b, l1, l2, la;
bool cmp(point p1, point p2) { return p1.a < p2.a; }
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d%d", &a, &b);
    if (a) {
      l1++;
      x[l1].a = b;
      x[l1].b = i;
    } else {
      l2++;
      y[l2].a = b;
      y[l2].b = i;
    }
  }
  sort(x + 1, x + l1 + 1, cmp);
  sort(y + 1, y + l2 + 1, cmp);
  la = l1;
  l1 = 1, l2 = 1;
  for (int i = 1; i < n; i++) {
    if (x[l1].a <= y[l2].a && l1 <= la) {
      printf("%d %d %d\n", x[l1].b, y[l2].b, x[l1].a);
      y[l2].a -= x[l1].a;
      l1++;
    } else {
      printf("%d %d %d\n", x[l1].b, y[l2].b, y[l2].a);
      x[l1].a -= y[l2].a;
      l2++;
    }
  }
  return 0;
}
