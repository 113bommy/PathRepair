#include <bits/stdc++.h>
using namespace std;
namespace io {
const int SIZE = (1 << 21) + 1;
char ibuf[SIZE], *iS, *iT, obuf[SIZE], *oS = obuf, *oT = oS + SIZE - 1, c,
                                       qu[55];
int f, qr;
char getc() {
  return (iS == iT ? (iT = (iS = ibuf) + fread(ibuf, 1, SIZE, stdin),
                      (iS == iT ? EOF : *iS++))
                   : *iS++);
}
inline void flush() {
  fwrite(obuf, 1, oS - obuf, stdout);
  oS = obuf;
}
inline void putc(char x) {
  *oS++ = x;
  if (oS == oT) flush();
}
template <class I>
inline void gi(I &x) {
  for (f = 1, c = (iS == iT ? (iT = (iS = ibuf) + fread(ibuf, 1, SIZE, stdin),
                              (iS == iT ? EOF : *iS++))
                            : *iS++);
       c < '0' || c > '9';
       c = (iS == iT ? (iT = (iS = ibuf) + fread(ibuf, 1, SIZE, stdin),
                       (iS == iT ? EOF : *iS++))
                     : *iS++))
    if (c == '-') f = -1;
  for (x = 0; c <= '9' && c >= '0';
       c = (iS == iT ? (iT = (iS = ibuf) + fread(ibuf, 1, SIZE, stdin),
                       (iS == iT ? EOF : *iS++))
                     : *iS++))
    x = x * 10 + (c & 15);
  x *= f;
}
template <class I>
inline void print(I x) {
  if (!x) putc('0');
  if (x < 0) putc('-'), x = -x;
  while (x) qu[++qr] = x % 10 + '0', x /= 10;
  while (qr) putc(qu[qr--]);
}
struct Flusher_ {
  ~Flusher_() { flush(); }
} io_flusher_;
}  // namespace io
using io ::getc;
using io ::gi;
using io ::print;
using io ::putc;
template <class T>
void upmax(T &x, T y) {
  x = x > y ? x : y;
}
template <class T>
void upmin(T &x, T y) {
  x = x < y ? x : y;
}
const int mod = 998244353;
inline int add(int x, int y) { return x + y >= mod ? x + y - mod : x + y; }
inline int sub(int x, int y) { return x - y < 0 ? x - y + mod : x - y; }
inline int mul(int x, int y) { return 1LL * x * y % mod; }
inline void inc(int &x, int y = 1) { x = x + y >= mod ? x + y - mod : x + y; }
inline void dec(int &x, int y = 1) { x = x - y < 0 ? x - y + mod : x - y; }
inline int power(int x, int y) {
  int res = 1;
  for (; y; y >>= 1, x = mul(x, x))
    if (y & 1) res = mul(res, x);
  return res;
}
inline int inv(int x) { return power(x, mod - 2); }
const int N = 300005;
int a[N], g[N];
int main() {
  int n, S = 0;
  gi(n);
  for (int i = 1; i <= n; i++) gi(a[i]), S += a[i];
  g[0] = n - 1;
  const int invS = inv(S), invSN1 = mul(invS, inv(n - 1));
  for (int i = 1; i < S; i++) {
    int coef = sub(1, add(mul(i, invS), mul(mul(S - i, n - 2), invSN1)));
    int rtval = add(mul(mul(i, invS), g[i - 1]), 1);
    g[i] = mul(rtval, inv(coef));
  }
  for (int i = S - 2; i >= 0; i--) inc(g[i], g[i + 1]);
  int sum = 0;
  for (int i = 1; i <= n; i++) inc(sum, g[a[i]]);
  printf("%d\n", mul(sub(sum, mul(n - 1, g[0])), inv(n)));
  return 0;
}
