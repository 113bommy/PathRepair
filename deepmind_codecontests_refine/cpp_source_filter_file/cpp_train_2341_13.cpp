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
const int N = 2e5 + 7;
const long long inf = 4e18;
int n, l;
long long lx = -inf, rx = inf, ly = -inf, ry = inf;
struct P {
  long long t, x, y, k;
  int w;
  inline void in() {
    int p, q;
    rd(t), rd(p), rd(q);
    if ((t ^ p ^ q) & 1) prints("NO"), exit(0);
    k = t / l, w = t % l;
    x = (p + q + t) / 2, y = (q - p + t) / 2;
  }
  inline bool operator<(const P &o) const { return w < o.w; }
} p[N];
int main() {
  rd(n), rd(l);
  for (int i = 1; i <= n; i++) p[i].in();
  sort(p + 1, p + n + 1);
  p[++n].k = -1, p[n].w = l;
  for (int i = 1; i <= n; i++) {
    long long k = p[i].k - p[i - 1].k;
    int w = p[i].w - p[i - 1].w;
    if (!k) {
      if (p[i].x - p[i - 1].x - w > 0 || p[i].x - p[i - 1].x < 0)
        prints("NO"), exit(0);
      if (p[i].y - p[i - 1].y - w > 0 || p[i].y - p[i - 1].y < 0)
        prints("NO"), exit(0);
    } else if (k > 0) {
      lx = max(lx, (long long)ceil(1.0L * (p[i].x - p[i - 1].x - w) / k));
      rx = min(rx, (long long)floor(1.0L * (p[i].x - p[i - 1].x) / k));
      ly = max(ly, (long long)ceil(1.0L * (p[i].y - p[i - 1].y - w) / k));
      ry = min(ry, (long long)floor(1.0L * (p[i].y - p[i - 1].y) / k));
    } else {
      k *= -1;
      lx = max(lx, (long long)ceil(1.0L * (p[i - 1].x - p[i].x) / k));
      rx = min(rx, (long long)floor(1.0L * (p[i - 1].x - p[i].x + w) / k));
      ly = max(ly, (long long)ceil(1.0L * (p[i - 1].y - p[i].y) / k));
      ry = min(ry, (long long)floor(1.0L * (p[i - 1].y - p[i].y + w) / k));
    }
  }
  if (lx > rx || ly > ry) prints("NO"), exit(0);
  for (int i = 1; i <= n; i++) {
    int dx = (p[i].x - p[i].k * lx) - (p[i - 1].x - p[i - 1].k * lx);
    int dy = (p[i].y - p[i].k * ly) - (p[i - 1].y - p[i - 1].k * ly);
    int t = p[i].w - p[i - 1].w, x = 0, y = 0;
    while (t--)
      if (x < dx) {
        ++x;
        if (y < dy)
          putchar('U'), ++y;
        else
          putchar('R');
      } else {
        if (y < dy)
          putchar('L'), ++y;
        else
          putchar('D');
      }
  }
  return 0;
}
