#include <bits/stdc++.h>
using namespace std;
const int N = 13;
struct A {
  int x, y;
} a[N], b[N];
int bz[10], bj[10], num, n, m, t;
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) {
    scanf("%d%d", &a[i].x, &a[i].y);
    if (a[i].x > a[i].y) swap(a[i].x, a[i].y);
  }
  for (int i = 1; i <= m; i++) {
    scanf("%d%d", &b[i].x, &b[i].y);
    if (b[i].x > b[i].y) swap(b[i].x, b[i].y);
  }
  for (int i = 1; i <= n; i++) {
    int o = 0;
    memset(bz, 0, sizeof(bz));
    for (int j = 1; j <= m; j++) {
      int x = 0, p = 0;
      if (a[i].x == b[j].x) x++, p = 1;
      if (a[i].x == b[j].y) x++, p = 2;
      if (a[i].y == b[j].x) x++, p = 3;
      if (a[i].y == b[j].y) x++, p = 4;
      if (x != 1) continue;
      int xx = 0;
      if (p == 1 || p == 2)
        xx = a[i].x;
      else
        xx = a[i].y;
      if (o && !bz[xx]) {
        printf("-1");
        return 0;
      }
      bz[xx] = true;
      o = 1;
      if (!bj[xx]) num++, t = xx;
      bj[xx] = true;
    }
  }
  for (int j = 1; j <= m; j++) {
    int o = 0;
    memset(bz, 0, sizeof(bz));
    for (int i = 1; i <= n; i++) {
      int x = 0, p = 0;
      if (a[i].x == b[j].x) x++, p = 1;
      if (a[i].y == b[j].x) x++, p = 2;
      if (a[i].x == b[j].y) x++, p = 3;
      if (a[i].y == b[j].y) x++, p = 4;
      if (x != 1) continue;
      int xx = 0;
      if (p == 1 || p == 2)
        xx = b[j].x;
      else
        xx = b[j].y;
      if (o && !bz[xx]) {
        printf("-1");
        return 0;
      }
      bz[xx] = true;
      o = 1;
      if (!bj[xx]) num++, t = xx;
      bj[xx] = true;
    }
  }
  if (num > 1)
    printf("0");
  else
    printf("%d", t);
  return 0;
}
