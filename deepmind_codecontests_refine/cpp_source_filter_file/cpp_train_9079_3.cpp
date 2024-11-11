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
const int N = 1e6 + 7;
int n, m, p[N], q[N], d[N], z[N];
long long c[N], ans;
char a[N], b[N], s[N];
inline void Z(char *s, int n) {
  for (int i = 1; i <= n; i++) z[i] = 0;
  z[1] = n;
  for (int i = 2, l = 0, r = 0; i <= n; i++) {
    if (i <= r) z[i] = min(z[i - l + 1], r - i + 1);
    while (i + z[i] <= n && s[i + z[i]] == s[z[i] + 1]) ++z[i];
    if (i + z[i] - 1 > r) l = i, r = i + z[i] - 1;
  }
}
inline void exkmp(char *s, int n, char *t, int m, int *p) {
  Z(t, m);
  for (int i = 1; i <= n; i++) p[i] = 0;
  for (int i = 1, l = 0, r = 0; i <= n; i++) {
    if (i <= r) p[i] = min(z[i - l + 1], r - i + 1);
    while (i + p[i] <= n && s[i + p[i]] == t[p[i] + 1]) ++p[i];
    if (i + p[i] - 1 > r) l = i, r = i + p[i] - 1;
  }
}
inline void add(int x, int k) {
  if (!x) return;
  while (x <= m) c[x] += k, d[x] += k > 0 ? 1 : -1, x += x & -x;
}
inline pair<long long, int> ask(int x) {
  long long k = 0;
  int p = 0;
  while (x) k += c[x], p += d[x], x -= x & -x;
  return make_pair(k, p);
}
int main() {
  rd(n), rd(m);
  rds(a, n), rds(b, n), rds(s, m);
  exkmp(a, n, s, m, p);
  reverse(b + 1, b + n + 1);
  reverse(s + 1, s + m + 1);
  exkmp(b, n, s, m, q);
  reverse(q + 1, q + n + 1);
  for (int i = 1, j = 0; i <= n; i++) {
    while (j + 1 <= n && j + 1 < i + m - 1) {
      if (q[++j] == m) --q[j];
      add(q[j], q[j]);
    }
    if (p[i] == m) --p[i];
    pair<long long, int> x = ask(m), y = ask(m - p[i] - 1);
    ans += x.first - y.first - (x.second - y.second) * (m - p[i] - 1);
    add(q[i], -q[i]);
  }
  print(ans);
  return 0;
}
