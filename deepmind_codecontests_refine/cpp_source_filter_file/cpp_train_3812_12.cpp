#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1005;
struct Point {
  int a, b, c, d, e;
  Point() {}
  Point(int a, int b, int c, int d, int e) : a(a), b(b), c(c), d(d), e(e) {}
} points[MAXN];
bool notgood[MAXN];
int main() {
  int n;
  scanf("%d", &n);
  if (n > 10) {
    printf("0");
    return 0;
  } else {
    for (register int i = 1; i <= n; i++) {
      int a, b, c, d, e;
      scanf("%d%d%d%d%d", &a, &b, &c, &d, &e);
      points[i] = Point(a, b, c, d, e);
    }
    int cnt = 0;
    for (register int i = 1; i <= n; i++)
      for (register int j = 1; j <= n; j++) {
        if (i == j) continue;
        for (register int k = 1; k <= n; k++) {
          if (j == k || i == k) continue;
          Point x, y;
          x.a = points[j].a - points[i].a;
          x.b = points[j].b - points[i].b;
          x.c = points[j].c - points[i].c;
          x.d = points[j].d - points[i].d;
          x.e = points[j].e - points[i].e;
          y.a = points[k].a - points[i].a;
          y.b = points[k].b - points[i].b;
          y.c = points[k].c - points[i].c;
          y.d = points[k].d - points[i].d;
          y.e = points[k].e - points[i].e;
          if (x.a * y.a + x.b * y.b + x.c * y.c + x.d * y.d + x.e * y.e > 0) {
            notgood[i] = true, cnt++;
            break;
          }
        }
        if (notgood[i]) break;
      }
    printf("%d\n", n - cnt);
    for (register int i = 1; i <= n; i++)
      if (!notgood[i]) printf("%d\n", i);
  }
  return 0;
}
