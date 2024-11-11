#include <bits/stdc++.h>
using namespace std;
const int RLEN = 1 << 18 | 1;
inline char nc() {
  static char ibuf[RLEN], *ib, *ob;
  (ib == ob) && (ob = (ib = ibuf) + fread(ibuf, 1, RLEN, stdin));
  return (ib == ob) ? -1 : *ib++;
}
inline int rd() {
  char ch = nc();
  int i = 0, f = 1;
  while (!isdigit(ch)) {
    if (ch == '-') f = -1;
    ch = nc();
  }
  while (isdigit(ch)) {
    i = (i << 1) + (i << 3) + ch - '0';
    ch = nc();
  }
  return i * f;
}
const int N = 2e5 + 50;
int n, m, vis[N];
struct P {
  long long x, y;
  int id;
  P(long long x = 0, long long y = 0, int id = 0) : x(x), y(y), id(id) {}
  friend inline P operator-(const P &a, const P &b) {
    return P(a.x - b.x, a.y - b.y);
  }
  friend inline long long operator*(const P &a, const P &b) {
    return a.x * b.y - a.y * b.x;
  }
  inline long long norm() { return x * x + y * y; }
} p[N], q[N];
inline void build_conv(int nn) {
  m = 1;
  sort(q + 1, q + nn + 1, [&](const P &a, const P &b) {
    return (a.x < b.x) || (a.x == b.x && a.y < b.y) ||
           (a.x == b.x && a.y == b.y && a.id < b.id);
  });
  sort(q + 2, q + nn + 1, [&](const P &a, const P &b) {
    int det = (a - q[1]) * (b - q[1]);
    if (det != 0) return det > 0;
    return (a - q[1]).norm() < (b - q[1]).norm();
  });
  for (int i = 2; i <= nn; i++) {
    while (m >= 2 && (q[i] - q[m - 1]) * (q[m] - q[m - 1]) >= 0) --m;
    q[++m] = q[i];
  }
  for (int i = 1; i <= m; i++)
    if (q[i].x & 1 || q[i].y & 1) {
      puts("Ani");
      exit(0);
    }
}
int main() {
  n = rd() + 1;
  p[1].id = 1;
  for (int i = 2; i <= n; i++) p[i].x = rd(), p[i].y = rd(), p[i].id = i;
  memcpy(q + 1, p + 1, sizeof(P) * (n));
  build_conv(n);
  for (int i = 2; i <= m; i += 2) vis[q[i].id] = 1, vis[q[i + 1].id] = 2;
  m = 0;
  for (int i = 1; i <= n; i++)
    if (vis[i] != 2) q[++m] = p[i];
  build_conv(m);
  m = 0;
  for (int i = 1; i <= n; i++)
    if (vis[i] != 1) q[++m] = p[i];
  build_conv(m);
  puts("Borna");
}
