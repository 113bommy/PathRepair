#include <bits/stdc++.h>
using namespace std;
inline char nc() {
  static char buf[100000], *p1 = buf, *p2 = buf;
  return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 100000, stdin), p1 == p2)
             ? EOF
             : *p1++;
}
inline int read() {
  register int x = 0, f = 1;
  register char ch = nc();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = nc();
  }
  while (ch >= '0' && ch <= '9') x = (x << 3) + (x << 1) + ch - '0', ch = nc();
  return x * f;
}
inline void write(register int x) {
  if (!x) putchar('0');
  if (x < 0) x = -x, putchar('-');
  static int sta[20];
  register int tot = 0;
  while (x) sta[tot++] = x % 10, x /= 10;
  while (tot) putchar(sta[--tot] + 48);
}
int n, mx, tp[20], x[20], y[20], f[65537][121], s1, s2, ans = 192608170;
int main() {
  n = read();
  mx = (1 << n) - 1;
  for (register int i = 0; i < n; ++i) {
    char ch = nc();
    while (ch != 'R' && ch != 'B') ch = nc();
    tp[i] = (ch == 'R') ? 1 : 2, x[i] = read(), y[i] = read();
    s1 += x[i], s2 += y[i];
  }
  for (register int i = 0; i <= mx; ++i)
    for (register int j = 0; j <= 120; ++j) f[i][j] = -1;
  f[0][0] = 0;
  for (register int i = 1; i <= mx; ++i) {
    int cnt1 = 0, cnt2 = 0;
    for (register int j = 0; j < n; ++j)
      if (i & (1 << j)) {
        if (tp[j] == 1)
          ++cnt1;
        else
          ++cnt2;
      }
    for (register int kk = 0, j; kk < n; ++kk) {
      if (!(i & (1 << kk)))
        continue;
      else
        j = i ^ (1 << kk);
      int cntx = 0, cnty = 0;
      cntx = cnt1 - (tp[kk] == 1);
      cnty = cnt2 - (tp[kk] == 2);
      cntx = min(cntx, x[kk]), cnty = min(cnty, y[kk]);
      for (register int v = cntx; v <= 120; ++v)
        if (f[j][v - cntx] != -1) f[i][v] = max(f[i][v], f[j][v - cntx] + cnty);
    }
  }
  for (register int i = 0; i <= 120; ++i)
    if (f[mx][i] != -1) ans = min(ans, max(s1 - i, s2 - f[mx][i]) + n);
  write(ans), puts("");
  return 0;
}
