#include <bits/stdc++.h>
using namespace std;
int main() {
  int q, q1, w, e, r, t, c, v, c1, o, a[100][100], s[100], d[100];
  scanf("%d%d", &o, &q);
  q1 = (q + 1) / 2;
  for (e = 1; e <= q; e++) {
    a[e][0] = d[e] = 0;
    s[e] = 100;
    for (r = 1; r <= q; r++) a[e][r] = a[e][r - 1] + abs(q1 - e) + abs(q1 - r);
  }
  for (; o; o--) {
    scanf("%d", &w);
    c1 = c = v = -1;
    t = 1 << 30;
    for (e = 1; e <= q; e++)
      if (s[e] == 100) {
        r = a[e][q1 + ((w - 1) >> 1)] - a[e][q1 - (w >> 1) - 1];
        if (t > r) {
          t = r;
          c1 = e;
          c = q1 - (w >> 1);
          v = q1 + ((w - 1) >> 1);
        }
      } else {
        if (s[e] > w)
          if (t > a[e][s[e] - 1] - a[e][s[e] - w - 1]) {
            t = a[e][s[e] - 1] - a[e][s[e] - w - 1];
            c1 = e;
            c = s[e] - w;
            v = s[e] - 1;
          }
        if (q - d[e] >= w)
          if (t > a[e][d[e] + w] - a[e][d[e]]) {
            t = a[e][d[e] + w] - a[e][d[e]];
            c1 = e;
            c = d[e] + 1;
            v = d[e] + w;
          }
      }
    if (t == 1 << 30) {
      printf("-1\n");
      continue;
    }
    printf("%d %d %d\n", c1, c, v);
    s[c1] = min(s[c1], c);
    d[c1] = max(d[c1], v);
  }
  return 0;
}
