#include <bits/stdc++.h>
using namespace std;
char *a = new char[3000000];
int y = 0, q, s[500][500], d[500][500], f[500][500];
bool d1[500][500];
void l(int w, int e) {
  s[w][e]++;
  if (!d[w][e]) {
    d[w][e] = 1;
    a[y] = '1';
    y++;
  }
  if (f[w][e] & 1)
    if (!s[w][e - 1]) {
      s[w][e]++;
      a[y] = 'L';
      y++;
      l(w, e - 1);
      a[y] = 'R';
      y++;
    }
  if (f[w][e] & 2)
    if (!s[w - 1][e]) {
      s[w][e]++;
      a[y] = 'U';
      y++;
      l(w - 1, e);
      a[y] = 'D';
      y++;
    }
  if (f[w][e] & 4)
    if (!s[w][e + 1]) {
      s[w][e]++;
      a[y] = 'R';
      y++;
      l(w, e + 1);
      a[y] = 'L';
      y++;
    }
  if (f[w][e] & 8)
    if (!s[w + 1][e]) {
      s[w][e]++;
      a[y] = 'D';
      y++;
      l(w + 1, e);
      a[y] = 'U';
      y++;
    }
  a[y] = '2';
  y++;
  d[w][e] = 0;
  if (d1[w][e]) {
    int r;
    if ((f[w][e] & 1) == 0)
      for (r = e + 1; r < q; r++) {
        f[w][r] -= 1;
        if ((d[w][r]) && (d1[w][r])) break;
      }
    if ((f[w][e] & 2) == 0)
      for (r = w + 1; r < q; r++) {
        f[r][e] -= 2;
        if ((d[r][e]) && (d1[r][e])) break;
      }
    if ((f[w][e] & 4) == 0)
      for (r = e - 1; r >= 0; r--) {
        f[w][r] -= 4;
        if ((d[w][r]) && (d1[w][r])) break;
      }
    if ((f[w][e] & 8) == 0)
      for (r = w - 1; r >= 0; r--) {
        f[r][e] -= 8;
        if ((d[r][e]) && (d1[r][e])) break;
      }
  }
}
int main() {
  int w, e, r, t, c, v;
  scanf("%d%d%d", &q, &c, &v);
  c--;
  v--;
  for (w = 0; w < q; w++)
    for (e = 0; e < q; e++) {
      scanf("%d", &d[w][e]);
      d1[w][e] = d[w][e];
      s[w][e] = f[w][e] = 0;
    }
  for (w = 0; w < q; w++) {
    r = 0;
    for (e = 0; e < q; e++) {
      f[w][e] += r;
      if (d[w][e]) r = 1;
    }
    r = 0;
    for (e = q - 1; e >= 0; e--) {
      f[w][e] += r;
      if (d[w][e]) r = 4;
    }
  }
  for (e = 0; e < q; e++) {
    r = 0;
    for (w = 0; w < q; w++) {
      f[w][e] += r;
      if (d[w][e]) r = 2;
    }
    r = 0;
    for (w = q - 1; w >= 0; w--) {
      f[w][e] += r;
      if (d[w][e]) r = 8;
    }
  }
  l(c, v);
  for (w = 0; w < q; w++)
    for (e = 0; e < q; e++)
      if ((d[w][e]) && (!s[w][e])) {
        printf("NO");
        return 0;
      }
  a[y] = 0;
  printf("YES\n%s", a);
  return 0;
}
