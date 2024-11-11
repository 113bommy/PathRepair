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
int n, m, fa[1000055], f[1000055], g[1000055], dis[1000055];
signed main() {
  n = read() + 1;
  for (int i = (2); i <= (n); i++) fa[i] = read();
  dis[1] = 1;
  f[1] = 0;
  g[1] = 0;
  for (int j = (2); j <= (n); j++) {
    dis[j] = 1;
    int i = j;
    while (i != 1) {
      if (dis[i] >= f[fa[i]]) {
        g[fa[i]] = f[fa[i]];
        f[fa[i]] = dis[i];
      } else {
        if (dis[i] > g[fa[i]]) g[fa[i]] = dis[i];
      }
      int t = max(f[fa[i]], g[fa[i]] + 1);
      if (t > dis[fa[i]]) {
        dis[fa[i]] = t;
        i = fa[i];
      } else
        break;
    }
    wri(f[1]);
  }
  return 0;
}
