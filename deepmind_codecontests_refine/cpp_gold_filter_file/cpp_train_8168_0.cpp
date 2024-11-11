#include <bits/stdc++.h>
using namespace std;
char a[2000][2001];
int q, w, t = 0, s[2000][2000], d[4000000], f[4000000];
void add(int e, int r) {
  if ((0 <= e) && (0 <= r)) s[e][r]++;
}
void del(int e, int r) {
  if ((0 <= e) && (0 <= r)) {
    s[e][r]--;
    if (s[e][r] == 1) {
      d[t] = e;
      f[t] = r;
      t++;
    }
  }
}
void ch(int e, int r) {
  if ((e < q) && ((r < w) && (a[e][r] == '*'))) {
    a[e][r] = '.';
    del(e, r);
    del(e - 1, r);
    del(e, r - 1);
    del(e - 1, r - 1);
  }
}
int main() {
  int e, r, c, v;
  scanf("%d%d", &q, &w);
  for (e = 0; e < q; e++) {
    scanf("%s", a[e]);
    for (r = 0; r < w; r++) {
      s[e][r] = 0;
      if ((e == q - 1) || (r == w - 1)) s[e][r] = 9;
    }
  }
  for (e = 0; e < q; e++)
    for (r = 0; r < w; r++)
      if (a[e][r] == '*') {
        add(e, r);
        add(e - 1, r);
        add(e, r - 1);
        add(e - 1, r - 1);
      }
  for (e = 0; e < q; e++)
    for (r = 0; r < w; r++)
      if (s[e][r] == 1) {
        d[t] = e;
        f[t] = r;
        t++;
      }
  for (e = 0, r = t; e < r; r = t)
    for (; e < r; e++) {
      c = d[e];
      v = f[e];
      ch(c, v);
      ch(c + 1, v);
      ch(c, v + 1);
      ch(c + 1, v + 1);
    }
  for (e = 0; e < q; e++) printf("%s\n", a[e]);
  return 0;
}
