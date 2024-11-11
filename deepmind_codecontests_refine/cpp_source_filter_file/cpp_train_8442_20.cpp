#include <bits/stdc++.h>
using namespace std;
const signed inf = 0x3f3f3f3f;
const double eps = 1e-8;
const double pi = acos(-1.0);
template <class T>
long long chkmin(T &a, T b) {
  return a > b ? a = b, 1 : 0;
}
template <class T>
long long chkmax(T &a, T b) {
  return a < b ? a = b, 1 : 0;
}
template <class T>
T sqr(T a) {
  return a * a;
}
template <class T>
T mmin(T a, T b) {
  return a < b ? a : b;
}
template <class T>
T mmax(T a, T b) {
  return a > b ? a : b;
}
template <class T>
T aabs(T a) {
  return a < 0 ? -a : a;
}
template <class T>
long long dcmp(T a, T b) {
  return a > b;
}
template <long long *a>
long long cmp_a(long long first, long long second) {
  return a[first] < a[second];
}
namespace io {
const long long SIZE = (1 << 21) + 1;
char ibuf[SIZE], *iS, *iT, obuf[SIZE], *oS = obuf, *oT = oS + SIZE - 1, c,
                                       qu[55];
long long f, qr;
inline void flush() {
  fwrite(obuf, 1, oS - obuf, stdout);
  oS = obuf;
}
inline void putc(char first) {
  *oS++ = first;
  if (oS == oT) flush();
}
inline bool read(signed &first) {
  for (f = 1, c = (iS == iT ? (iT = (iS = ibuf) + fread(ibuf, 1, SIZE, stdin),
                              (iS == iT ? EOF : *iS++))
                            : *iS++);
       c < '0' || c > '9';
       c = (iS == iT ? (iT = (iS = ibuf) + fread(ibuf, 1, SIZE, stdin),
                       (iS == iT ? EOF : *iS++))
                     : *iS++))
    if (c == '-')
      f = -1;
    else if (c == EOF)
      return 0;
  for (first = 0; c <= '9' && c >= '0';
       c = (iS == iT ? (iT = (iS = ibuf) + fread(ibuf, 1, SIZE, stdin),
                       (iS == iT ? EOF : *iS++))
                     : *iS++))
    first = first * 10 + (c & 15);
  first *= f;
  return 1;
}
inline bool read(long long &first) {
  for (f = 1, c = (iS == iT ? (iT = (iS = ibuf) + fread(ibuf, 1, SIZE, stdin),
                              (iS == iT ? EOF : *iS++))
                            : *iS++);
       c < '0' || c > '9';
       c = (iS == iT ? (iT = (iS = ibuf) + fread(ibuf, 1, SIZE, stdin),
                       (iS == iT ? EOF : *iS++))
                     : *iS++))
    if (c == '-')
      f = -1;
    else if (c == EOF)
      return 0;
  for (first = 0; c <= '9' && c >= '0';
       c = (iS == iT ? (iT = (iS = ibuf) + fread(ibuf, 1, SIZE, stdin),
                       (iS == iT ? EOF : *iS++))
                     : *iS++))
    first = first * 10 + (c & 15);
  first *= f;
  return 1;
}
inline bool read(char &first) {
  first = (iS == iT ? (iT = (iS = ibuf) + fread(ibuf, 1, SIZE, stdin),
                       (iS == iT ? EOF : *iS++))
                    : *iS++);
  return first != EOF;
}
inline bool read(char *first) {
  while ((*first = (iS == iT ? (iT = (iS = ibuf) + fread(ibuf, 1, SIZE, stdin),
                                (iS == iT ? EOF : *iS++))
                             : *iS++)) == '\n' ||
         *first == ' ' || *first == '\r')
    if (*first == EOF) return 0;
  while (!(*first == '\n' || *first == ' ' || *first == '\r'))
    *(++first) = (iS == iT ? (iT = (iS = ibuf) + fread(ibuf, 1, SIZE, stdin),
                              (iS == iT ? EOF : *iS++))
                           : *iS++);
  *first = 0;
  return 1;
}
template <typename A, typename... B>
inline bool read(A &first, B &...second) {
  return read(first) && read(second...);
}
inline bool write(signed first) {
  if (!first) putc('0');
  if (first < 0) putc('-'), first = -first;
  while (first) qu[++qr] = first % 10 + '0', first /= 10;
  while (qr) putc(qu[qr--]);
  return 0;
}
inline bool write(long long first) {
  if (!first) putc('0');
  if (first < 0) putc('-'), first = -first;
  while (first) qu[++qr] = first % 10 + '0', first /= 10;
  while (qr) putc(qu[qr--]);
  return 0;
}
inline bool write(char first) {
  putc(first);
  return 0;
}
inline bool write(const char *first) {
  while (*first) {
    putc(*first);
    ++first;
  }
  return 0;
}
inline bool write(char *first) {
  while (*first) {
    putc(*first);
    ++first;
  }
  return 0;
}
template <typename A, typename... B>
inline bool write(A first, B... second) {
  return write(first) || write(second...);
}
struct Flusher_ {
  ~Flusher_() { flush(); }
} io_flusher_;
}  // namespace io
using io ::putc;
using io ::read;
using io ::write;
const long long p = 1000000007;
char a[100005], b[100005];
long long A, B, C, D;
long long fac[200005], inv[200005], invf[200005];
long long fC(long long a, long long b) {
  return a < 0 || b < 0 || a < b ? 0 : fac[a] * invf[b] % p * invf[a - b] % p;
}
long long f1(long long n, long long a, long long b, long long c, long long d) {
  if (a + b + c + d + 1 != n) return 0;
  if (c < b || c - b > 1) return 0;
  return fC(b + d, b) * (c ? fC(c + a - 1, c - 1) : !a) % p;
}
long long ff(long long n) {
  long long ans = 0;
  for (long long i = 1; i < n; ++i) ans += f1(i, A, B, C, D);
  return ans;
}
long long f(char *s) {
  while (*s == '0') ++s;
  long long n = strlen(s), ans = ff(n);
  if (!n)
    return 0;
  else if (n == 1)
    return !(A || B || C || D);
  long long xA = A, xB = B, xC = C, xD = D;
  for (long long i = 1; i < n; ++i) {
    if (s[i] == '1')
      ans += f1(n - i, xD, xC - (s[i - 1] == '1'), xB, xA - (s[i - 1] == '0'));
    --(s[i - 1] == '0' ? (s[i] == '0' ? xA : xB) : (s[i] == '0' ? xC : xD));
  }
  if (!(xA && xB && xC && xD)) ++ans;
  return ans % p;
}
int main() {
  read(a, b, A, B, C, D);
  fac[0] = fac[1] = inv[1] = invf[0] = invf[1] = 1;
  for (long long i = 2; i <= 200001; ++i) {
    fac[i] = fac[i - 1] * i % p;
    inv[i] = (p - p / i) * inv[p % i] % p;
    invf[i] = inv[i] * invf[i - 1] % p;
  }
  long long n = strlen(a) - 1;
  for (long long i = n; ~i; --i) {
    a[i] ^= 1;
    if (a[i] == '0') break;
  }
  write((f(b) - f(a) + p) % p, '\n');
  return 0;
}
