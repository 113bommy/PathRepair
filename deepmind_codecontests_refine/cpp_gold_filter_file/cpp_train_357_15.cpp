#include <bits/stdc++.h>
using namespace std;
int main() {
  int i, j, x, n, flg = 0, s, att, tat, b, y, mx, cnt;
  int a[3], h[3], d[3], p[3];
  cin >> h[1] >> a[1] >> d[1] >> h[2] >> a[2] >> d[2] >> p[1] >> p[2] >> p[3];
  mx = a[2] - d[1];
  mx++;
  if (mx < 0) mx = 0;
  mx *= p[3];
  att = a[1] - d[2];
  if (att <= 0) {
    att = 1;
    mx += (d[2] - a[1] + 1) * p[2];
  }
  while (h[2] / att > 0 || !flg) {
    s = h[2] / att;
    if (h[2] % att != 0 && flg) {
      att++;
      continue;
    }
    if (h[2] % att != 0) s++;
    if (h[2] / att == 0) {
      s++;
      flg = 1;
    }
    cnt = (att - a[1] + d[2]) * p[2];
    tat = a[2] - d[1];
    tat *= s;
    tat -= h[1];
    tat++;
    if (tat < 0) tat = 0;
    y = tat / s;
    if (tat % s != 0) y++;
    tat *= p[1];
    y *= p[3];
    cnt += min(tat, y);
    if (mx > cnt) {
      mx = cnt;
    }
    att++;
  }
  printf("%d", mx);
}
