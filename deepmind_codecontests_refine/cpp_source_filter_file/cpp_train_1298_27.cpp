#include <bits/stdc++.h>
#pragma GCC optimize(2, 3, "Ofast", "unroll-loops")
using namespace std;
namespace fast_io {
char buf[1 << 12], *p1 = buf, *p2 = buf, sr[1 << 23], z[23], nc;
int C = -1, Z = 0, Bi = 0, ny;
inline char gc() {
  return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 12, stdin), p1 == p2)
             ? EOF
             : *p1++;
}
inline int read() {
  int x = 0;
  ny = 1;
  while (nc = gc(), (nc < 48 || nc > 57) && nc != EOF)
    if (nc == 45) ny = -1;
  Bi = 1;
  if (nc < 0) return nc;
  x = nc - 48;
  while (nc = gc(), 47 < nc && nc < 58 && nc != EOF)
    x = (x << 3) + (x << 1) + (nc ^ 48), Bi++;
  return x * ny;
}
inline double gf() {
  int a = read(), y = ny, b = (nc != '.') ? 0 : read();
  return (b ? a + (double)b / pow(10, Bi) * y : a);
}
inline int gs(char *s) {
  char c, *t = s;
  while (c = gc(), c <= 32)
    ;
  *s++ = c;
  while (c = gc(), c > 32) *s++ = c;
  return s - t;
}
inline void ot() {
  fwrite(sr, 1, C + 1, stdout);
  C = -1;
}
inline void flush() {
  if (C > 1 << 22) ot();
}
template <typename T>
inline void write(T x, char t) {
  int y = 0;
  if (x < 0) y = 1, x = -x;
  while (z[++Z] = x % 10 + 48, x /= 10)
    ;
  if (y) z[++Z] = '-';
  while (sr[++C] = z[Z], --Z)
    ;
  sr[++C] = t;
  flush();
}
inline void write(char *s) {
  int l = strlen(s);
  for (int i = 0; i < l; i++) sr[++C] = *s++;
  sr[++C] = '\n';
  flush();
}
};  // namespace fast_io
using namespace fast_io;
const int N = 1e5 + 5;
int n, m, k, p, c[N];
long long l, r, mid, a[N], h[N];
struct pii {
  long long a, b;
  inline bool operator<(pii x) const { return a ^ x.a ? a < x.a : b < x.b; }
};
inline int check(long long H) {
  priority_queue<pii> q;
  for (int i = 1; i <= n; i++)
    if (h[i] + m * a[i] > H) q.push({-H / a[i], i}), c[i] = 0;
  int cnt = 0;
  for (int i = 1; q.size() && i <= m; i++)
    for (int j = 1; q.size() && j <= k; j++) {
      if (-q.top().a < i) return 0;
      int x = q.top().b;
      q.pop();
      long long w = (H + (++c[x]) * p) / a[x];
      if (w < m) q.push({-w, x});
      cnt++;
    }
  for (int i = 1; i <= n; i++) {
    long long w = H + c[i] * p - m * a[i];
    if (h[i] <= w) continue;
    w = (h[i] - w - 1) / p + 1;
    if (cnt + w > m * k) return 0;
    cnt += w;
  }
  return 1;
}
int main() {
  n = read(), m = read(), k = read(), p = read();
  for (int i = 1; i <= n; i++)
    h[i] = read(), a[i] = read(), l = max(l, a[i]), r = max(r, h[i] + m * a[i]);
  while (l < r) mid = (l + r) >> 1, check(mid) ? r = mid : l = mid + 1;
  write(l, '\n');
  return ot(), 0;
}
