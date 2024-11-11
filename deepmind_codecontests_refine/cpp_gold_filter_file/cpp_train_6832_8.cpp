#include <bits/stdc++.h>
using namespace std;
inline char gc() {
  static char buf[100000], *p1 = buf, *p2 = buf;
  return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 100000, stdin), p1 == p2)
             ? EOF
             : *p1++;
}
inline int read() {
  char c = getchar();
  int tot = 1;
  while ((c < '0' || c > '9') && c != '-') c = getchar();
  if (c == '-') {
    tot = -1;
    c = getchar();
  }
  int sum = 0;
  while (c >= '0' && c <= '9') {
    sum = sum * 10 + c - '0';
    c = getchar();
  }
  return sum * tot;
}
inline void wr(int x) {
  if (x < 0) {
    putchar('-');
    wr(-x);
    return;
  }
  if (x >= 10) wr(x / 10);
  putchar(x % 10 + '0');
}
inline void wrn(int x) {
  wr(x);
  putchar('\n');
}
inline void wri(int x) {
  wr(x);
  putchar(' ');
}
inline void wrn(int x, int y) {
  wri(x);
  wrn(y);
}
inline void wrn(int a, int b, int c) {
  wri(a);
  wrn(b, c);
}
int n, m, ans, vis[500055], cnt;
double c[500055], q[500055];
struct xx {
  int x, y;
} z[500055];
double sx, sy, a, b;
signed main() {
  n = read();
  if (n == 2) return puts("-1"), 0;
  ;
  for (int i = (1); i <= (n); i++) sx += z[i].x = read(), sy += z[i].y = read();
  sx = sx / n, sy = sy / n;
  for (int i = (1); i <= (n); i++) {
    if (vis[i]) continue;
    if ((fabs(z[i].x - sx) < 1e-7) && (fabs(z[i].y - sy) < 1e-7)) vis[i] = 1;
    for (int j = (i + 1); j <= (n); j++) {
      if (vis[j]) continue;
      if ((fabs(z[i].x + z[j].x - sx * 2) < 1e-7) &&
          (fabs(z[i].y + z[j].y - sy * 2) < 1e-7)) {
        vis[i] = vis[j] = 1;
        break;
      }
    }
  }
  int yk = 0;
  for (int i = (1); i <= (n); i++) yk += vis[i];
  if (yk == n) return puts("-1"), 0;
  ;
  random_shuffle(z + 1, z + n + 1);
  for (int ci = (1); ci <= (11); ci++) {
    swap(z[1], z[ci]);
    for (int i = (1); i <= (n); i++) {
      if (fabs(z[1].y + z[i].y - 2 * sy) < 1e-7)
        b = 0, a = 1;
      else
        b = 1, a = 1.0 * (2 * sx - (z[1].x + z[i].x)) /
                   (1.0 * (z[1].y + z[i].y - 2 * sy));
      for (int j = (1); j <= (n); j++) c[j] = a * z[j].y + b * z[j].x;
      sort(c + 1, c + n + 1);
      double t = c[1] + c[n];
      int pd = 1;
      for (int j = (1); j <= (n); j++) {
        if (fabs(c[j] + c[n - j + 1] - t) > 1e-7) pd = 0;
      }
      if (pd) q[++cnt] = (b == 0) ? -2151.2352 : a;
    }
  }
  q[0] = -1241.23462;
  sort(q + 1, q + cnt + 1);
  for (int i = (1); i <= (cnt); i++) {
    if (fabs(q[i] - q[i - 1]) > 1e-7) ans++;
  }
  wrn(ans);
  return 0;
}
