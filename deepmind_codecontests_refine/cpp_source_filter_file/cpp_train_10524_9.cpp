#include <bits/stdc++.h>
#pragma optimize("no-stack-protector")
using namespace std;
namespace io {
const int L = (1 << 21) + 1;
char ibuf[L], *iS, *iT, obuf[L], *oS = obuf, *oT = obuf + L - 1, c, qu[55];
int f, qr;
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
  for (f = 1, c = (iS == iT ? (iT = (iS = ibuf) + fread(ibuf, 1, L, stdin),
                              (iS == iT ? EOF : *iS++))
                            : *iS++);
       c < '0' || c > '9';
       c = (iS == iT ? (iT = (iS = ibuf) + fread(ibuf, 1, L, stdin),
                       (iS == iT ? EOF : *iS++))
                     : *iS++))
    if (c == '-') f = -1;
  for (x = 0; c <= '9' && c >= '0';
       c = (iS == iT ? (iT = (iS = ibuf) + fread(ibuf, 1, L, stdin),
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
inline char read() {
  for (c = (iS == iT ? (iT = (iS = ibuf) + fread(ibuf, 1, L, stdin),
                       (iS == iT ? EOF : *iS++))
                     : *iS++);
       c < 'a' || c > 'z';
       c = (iS == iT ? (iT = (iS = ibuf) + fread(ibuf, 1, L, stdin),
                       (iS == iT ? EOF : *iS++))
                     : *iS++))
    ;
  return c;
}
inline void gs(char *s) {
  int l;
  for (c = (iS == iT ? (iT = (iS = ibuf) + fread(ibuf, 1, L, stdin),
                       (iS == iT ? EOF : *iS++))
                     : *iS++);
       c < 'a' || c > 'z';
       c = (iS == iT ? (iT = (iS = ibuf) + fread(ibuf, 1, L, stdin),
                       (iS == iT ? EOF : *iS++))
                     : *iS++))
    ;
  for (l = 0; c <= 'z' && c >= 'a';
       c = (iS == iT ? (iT = (iS = ibuf) + fread(ibuf, 1, L, stdin),
                       (iS == iT ? EOF : *iS++))
                     : *iS++))
    s[l] = c, ++l;
  s[l] = 0;
}
inline void ps(const char *s) {
  int l = strlen(s), i;
  for (i = 0; i < l; i++) putc(s[i]);
}
struct IOC {
  ~IOC() { flush(); }
} _ioc_;
inline double readld() {
  double x = 0, y = 1;
  for (c = (iS == iT ? (iT = (iS = ibuf) + fread(ibuf, 1, L, stdin),
                       (iS == iT ? EOF : *iS++))
                     : *iS++);
       c < '0' || c > '9';
       c = (iS == iT ? (iT = (iS = ibuf) + fread(ibuf, 1, L, stdin),
                       (iS == iT ? EOF : *iS++))
                     : *iS++))
    if (c == '-') y = -1;
  assert(c != '.');
  for (c = (iS == iT ? (iT = (iS = ibuf) + fread(ibuf, 1, L, stdin),
                       (iS == iT ? EOF : *iS++))
                     : *iS++);
       c <= '9' && c >= '0';
       c = (iS == iT ? (iT = (iS = ibuf) + fread(ibuf, 1, L, stdin),
                       (iS == iT ? EOF : *iS++))
                     : *iS++))
    x = x * 10 + (c & 15);
  x *= y;
  assert(c != 'e');
  if (c == '.')
    for (c = (iS == iT ? (iT = (iS = ibuf) + fread(ibuf, 1, L, stdin),
                         (iS == iT ? EOF : *iS++))
                       : *iS++);
         c <= '9' && c >= '0';
         c = (iS == iT ? (iT = (iS = ibuf) + fread(ibuf, 1, L, stdin),
                         (iS == iT ? EOF : *iS++))
                       : *iS++))
      y *= 0.1, x += y * (c & 15);
  return x;
}
inline void printld(double x, int digit) {
  print((long long)x), putc('.');
  for (x -= (long long)x; digit; --digit)
    x = x * 10, putc((int)x + '0'), x -= (int)x;
}
};  // namespace io
using io::gi;
using io::gs;
using io::print;
using io::ps;
using io::putc;
using io::read;
inline int ctz(int a) { return __builtin_ctz(a); }
inline int ctz(unsigned int a) { return __builtin_ctz(a); }
inline int ctz(long long a) { return __builtin_ctzll(a); }
inline int ctz(unsigned long long a) { return __builtin_ctzll(a); }
template <class T>
inline T gcd(T a, T b) {
  int shift = ctz(a | b);
  for (b >>= ctz(b), a >>= ctz(a); a; a -= b, a >>= ctz(a))
    if (a < b) swap(a, b);
  return b << shift;
}
template <class T>
void exgcd(T a, T b, T &x, T &y) {
  if (!b) return (void)(x = 1, y = 0);
  exgcd(b, a % b, y, x), y -= a / b * x;
}
int inv(int a, int p) {
  int x, y;
  exgcd(a, p, x, y);
  return (x % p + p) % p;
}
int fpow(int a, int t, int p) {
  static int r;
  for (r = 1; t; a = (long long)a * a % p, t >>= 1)
    if (t & 1) r = (long long)r * a % p;
  return r;
}
string to_string(string s) { return '"' + s + '"'; }
string to_string(const char *s) { return to_string((string)s); }
string to_string(bool b) { return (b ? "true" : "false"); }
template <class A, class B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
template <class A>
string to_string(A v) {
  bool first = true;
  string res = "{";
  for (const auto &x : v) {
    if (!first) res += ", ";
    first = false, res += to_string(x);
  }
  res += "}";
  return res;
}
void debug_out() { cerr << endl; }
template <class A, class... B>
void debug_out(A H, B... T) {
  cerr << " " << to_string(H), debug_out(T...);
}
void scan() {}
template <class A, class... B>
void scan(A &a, B &...b) {
  gi(a), scan(b...);
}
template <class T>
inline bool chkmin(T &a, T b) {
  return b < a ? a = b, true : false;
}
template <class T>
inline bool chkmax(T &a, T b) {
  return a < b ? a = b, true : false;
}
const int N = 1005;
int n, sum[N], m;
int main() {
  scan(n);
  for (int i = 1; i <= n; i++) {
    int a, b, c, d;
    scan(a, b, c, d);
    sum[i] = a + b + c + d;
  }
  for (int i = 1; i <= n; i++)
    if (sum[i] < sum[1]) m++;
  cout << m << endl;
}
