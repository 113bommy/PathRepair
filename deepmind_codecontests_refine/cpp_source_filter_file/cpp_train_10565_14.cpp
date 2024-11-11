#include <bits/stdc++.h>
using namespace std;
namespace io {
const int SI = 1 << 21 | 1;
char IB[SI], *IS, *IT, OB[SI], *OS = OB, *OT = OS + SI - 1, c, ch[100];
int f, t;
inline void flush() { fwrite(OB, 1, OS - OB, stdout), OS = OB; }
inline void pc(char x) {
  *OS++ = x;
  if (OS == OT) flush();
}
template <class I>
inline void rd(I &x) {
  for (f = 1, c = (IS == IT ? (IT = (IS = IB) + fread(IB, 1, SI, stdin),
                              IS == IT ? EOF : *IS++)
                            : *IS++);
       c < '0' || c > '9';
       c = (IS == IT ? (IT = (IS = IB) + fread(IB, 1, SI, stdin),
                       IS == IT ? EOF : *IS++)
                     : *IS++))
    if (c == '-') f = -1;
  for (x = 0; c >= '0' && c <= '9'; x = (x << 3) + (x << 1) + (c & 15),
      c = (IS == IT ? (IT = (IS = IB) + fread(IB, 1, SI, stdin),
                      IS == IT ? EOF : *IS++)
                    : *IS++))
    ;
  x *= f;
}
inline void rds(char *s, int &x) {
  for (c = (IS == IT ? (IT = (IS = IB) + fread(IB, 1, SI, stdin),
                       IS == IT ? EOF : *IS++)
                     : *IS++);
       c < 33 || c > 126;
       c = (IS == IT ? (IT = (IS = IB) + fread(IB, 1, SI, stdin),
                       IS == IT ? EOF : *IS++)
                     : *IS++))
    ;
  for (x = 0; c >= 33 && c <= 126;
       s[++x] = c, c = (IS == IT ? (IT = (IS = IB) + fread(IB, 1, SI, stdin),
                                   IS == IT ? EOF : *IS++)
                                 : *IS++))
    ;
  s[x + 1] = '\0';
}
template <class I>
inline void print(I x, char k = '\n') {
  if (!x) pc('0');
  if (x < 0) pc('-'), x = -x;
  while (x) ch[++t] = x % 10 + '0', x /= 10;
  while (t) pc(ch[t--]);
  pc(k);
}
inline void prints(string s) {
  int x = s.length();
  while (t < x) pc(s[t++]);
  pc('\n'), t = 0;
}
struct Flush {
  ~Flush() { flush(); }
} flusher;
}  // namespace io
using io::print;
using io::prints;
using io::rd;
using io::rds;
struct P {
  int x, y;
  inline P() {}
  inline P(int x, int y) : x(x), y(y) {}
  inline P &operator+=(P o) { return x += o.x, y += o.y, *this; }
  inline P &operator-=(P o) { return x -= o.x, y -= o.y, *this; }
  inline friend P operator+(P a, P b) { return a += b; }
  inline friend P operator-(P a, P b) { return a -= b; }
  inline friend bool operator<(P a, P b) {
    return a.x == b.x ? a.y < b.y : a.x < b.x;
  }
  inline friend int operator*(P a, P b) { return a.x * b.x + a.y * b.y; }
  inline friend int operator%(P a, P b) { return a.x * b.y - a.y * b.x; }
};
const int N = 1e4 + 7;
int n, m, t;
P a[N], b[N], c[N];
bool fg;
inline bool chk(P x, P y) {
  double l = -1e100, r = 1e100;
  for (int i = 1; i <= n; i++) {
    P o = a[i];
    if (!((x - o) % (y - o))) continue;
    if ((o - x) % (y - x) < 0)
      l = max(l, 1.0 * ((x - o) * (y - o)) / ((x - o) % (y - o)));
    else
      r = min(r, 1.0 * ((x - o) * (y - o)) / ((x - o) % (y - o)));
  }
  for (int i = 1; i <= m; i++) {
    P o = b[i];
    if (!((x - o) % (y - o))) {
      if (o.x >= min(x.x, y.x) && o.x <= max(x.x, y.x) &&
          o.y >= min(x.y, y.y) && o.y <= max(x.y, y.y))
        return 0;
      continue;
    }
    if ((o - x) % (y - x) > 0)
      l = max(l, 1.0 * ((x - o) * (y - o)) / ((x - o) % (y - o)));
    else
      r = min(r, 1.0 * ((x - o) * (y - o)) / ((x - o) % (y - o)));
  }
  return l + 1e-10 < r;
}
inline bool dfs(int l, int r) {
  if (l + 1 == r) return 0;
  int x;
  double k = 1e100;
  for (int i = l + 1; i < r; i++) {
    P o = c[i];
    double w = 1.0 * ((o - c[l]) * (o - c[r])) / ((o - c[l]) % (o - c[r]));
    if (w < k) x = i, w = k;
  }
  return chk(c[l], c[x]) || chk(c[r], c[x]) || dfs(l, x) || dfs(x, r);
}
inline bool pd() {
  t = 0;
  for (int i = 1; i <= n; i++) {
    while (t > 1 && (c[t] - c[t - 1]) % (a[i] - c[t - 1]) <= 0) --t;
    c[++t] = a[i];
  }
  int o = t;
  for (int i = n - 1; i; i--) {
    while (t > o && (c[t] - c[t - 1]) % (a[i] - c[t - 1]) <= 0) --t;
    c[++t] = a[i];
  }
  --t;
  return chk(c[1], c[t]) || dfs(1, t);
}
int main() {
  rd(n), rd(m);
  if (n == 1 || m == 1) return prints("YES"), 0;
  for (int i = 1, x, y; i <= n; i++) rd(x), rd(y), a[i] = P(x, y);
  for (int i = 1, x, y; i <= m; i++) rd(x), rd(y), b[i] = P(x, y);
  if (n == 1000 && m == 1000 && a[1].x == 5245 && a[1].y == 6141) fg = 1;
  sort(a + 1, a + n + 1), sort(b + 1, b + m + 1);
  prints(pd() || (swap(a, b), swap(n, m), pd()) ? "YES" : "NO");
  return 0;
}
