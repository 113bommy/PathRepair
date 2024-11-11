#include <bits/stdc++.h>
using namespace std;
int ans[10009];
struct xx {
  int x, r, id;
} cir[10009];
bool by_x(xx c, xx d) { return c.x < d.x; }
int n;
int binary(int x) {
  int m, l = 0, h = n;
  while (l + 1 < h) {
    m = (l + h) >> 1;
    if (cir[m].x > x)
      h = m;
    else
      l = m;
  }
  return l;
}
int main() {
  int x, y, tmp, m, num;
  while (~scanf("%d", &n)) {
    num = 0;
    for (int i = 0; i < n; i++) {
      scanf("%d%d", &cir[i].x, &cir[i].r);
      cir[i].r = cir[i].r * cir[i].r;
      cir[i].id = i;
    }
    sort(cir, cir + n, by_x);
    memset(ans, -1, sizeof(ans));
    scanf("%d", &m);
    for (int i = 1; i <= m; i++) {
      scanf("%d%d", &x, &y);
      tmp = binary(x);
      if (ans[cir[tmp].id] == -1 &&
          (cir[tmp].x - x) * (cir[tmp].x - x) + y * y <= cir[tmp].r) {
        num++;
        ans[cir[tmp].id] = i;
      }
      if (tmp + 1 < n && ans[cir[tmp + 1].id] == -1 &&
          (cir[tmp + 1].x - x) * (cir[tmp + 1].x - x) + y * y <=
              cir[tmp + 1].r) {
        num++;
        ans[cir[tmp + 1].id] = i;
      }
    }
    printf("%d\n", num);
    for (int i = 0; i < n - 1; i++) printf("%d ", ans[i]);
    printf("%d\n", ans[n - 1]);
  }
}
