#include <bits/stdc++.h>
using namespace std;
int ch[220][220], a[4], b[4], c[4], d[4];
int main() {
  scanf("%d %d %d %d %d %d %d %d", &a[0], &b[0], &a[1], &b[1], &a[2], &b[2],
        &a[3], &b[3]);
  scanf("%d %d %d %d %d %d %d %d", &c[0], &d[0], &c[1], &d[1], &c[2], &d[2],
        &c[3], &d[3]);
  int xx = 210, xx1 = 0, yy = 210, yy1 = 0;
  for (int i = 0; i < 4; i++) {
    a[i] += 100;
    b[i] += 100;
    c[i] += 100;
    d[i] += 100;
  }
  for (int i = 0; i < 4; i++) {
    xx = min(xx, a[i]);
    xx1 = max(xx1, a[i]);
    yy = min(yy, b[i]);
    yy1 = max(yy1, b[i]);
  }
  int z = 0, hi = 210, lo = -1;
  for (int i = 0; i < 4; i++) {
    if (lo < c[i]) {
      lo = c[i];
      z = d[i];
    }
    hi = min(hi, c[i]);
  }
  int pp = (lo - hi) / 2;
  for (int i = xx; i <= xx1; i++) {
    for (int y = yy; y <= yy1; y++) {
      ch[i][y] = 1;
    }
  }
  for (int i = 0; i <= pp; i++) {
    for (int y = z - i; y <= z + i; y++) {
      if (ch[hi + i][y]) {
        puts("YES");
        return 0;
      }
    }
  }
  for (int i = 0; i <= pp; i++) {
    for (int y = z - i; y <= z + i; y++) {
      if (ch[lo - i][y]) {
        puts("YES");
        return 0;
      }
    }
  }
  puts("NO");
}
