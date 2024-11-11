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
inline void read(signed &first) {
  for (f = 1, c = (iS == iT ? (iT = (iS = ibuf) + fread(ibuf, 1, SIZE, stdin),
                              (iS == iT ? EOF : *iS++))
                            : *iS++);
       c < '0' || c > '9';
       c = (iS == iT ? (iT = (iS = ibuf) + fread(ibuf, 1, SIZE, stdin),
                       (iS == iT ? EOF : *iS++))
                     : *iS++))
    if (c == '-') f = -1;
  for (first = 0; c <= '9' && c >= '0';
       c = (iS == iT ? (iT = (iS = ibuf) + fread(ibuf, 1, SIZE, stdin),
                       (iS == iT ? EOF : *iS++))
                     : *iS++))
    first = first * 10 + (c & 15);
  first *= f;
}
inline void read(long long &first) {
  for (f = 1, c = (iS == iT ? (iT = (iS = ibuf) + fread(ibuf, 1, SIZE, stdin),
                              (iS == iT ? EOF : *iS++))
                            : *iS++);
       c < '0' || c > '9';
       c = (iS == iT ? (iT = (iS = ibuf) + fread(ibuf, 1, SIZE, stdin),
                       (iS == iT ? EOF : *iS++))
                     : *iS++))
    if (c == '-') f = -1;
  for (first = 0; c <= '9' && c >= '0';
       c = (iS == iT ? (iT = (iS = ibuf) + fread(ibuf, 1, SIZE, stdin),
                       (iS == iT ? EOF : *iS++))
                     : *iS++))
    first = first * 10 + (c & 15);
  first *= f;
}
inline void read(char &first) {
  first = (iS == iT ? (iT = (iS = ibuf) + fread(ibuf, 1, SIZE, stdin),
                       (iS == iT ? EOF : *iS++))
                    : *iS++);
}
inline void read(char *first) {
  while ((*first = (iS == iT ? (iT = (iS = ibuf) + fread(ibuf, 1, SIZE, stdin),
                                (iS == iT ? EOF : *iS++))
                             : *iS++)) == '\n' ||
         *first == ' ' || *first == '\r')
    ;
  while (!(*first == '\n' || *first == ' ' || *first == '\r'))
    *(++first) = (iS == iT ? (iT = (iS = ibuf) + fread(ibuf, 1, SIZE, stdin),
                              (iS == iT ? EOF : *iS++))
                           : *iS++);
}
template <typename A, typename... B>
inline void read(A &first, B &...second) {
  read(first);
  read(second...);
}
inline void write(signed first) {
  if (!first) putc('0');
  if (first < 0) putc('-'), first = -first;
  while (first) qu[++qr] = first % 10 + '0', first /= 10;
  while (qr) putc(qu[qr--]);
}
inline void write(long long first) {
  if (!first) putc('0');
  if (first < 0) putc('-'), first = -first;
  while (first) qu[++qr] = first % 10 + '0', first /= 10;
  while (qr) putc(qu[qr--]);
}
inline void write(char first) { putc(first); }
inline void write(const char *first) {
  while (*first) {
    putc(*first);
    ++first;
  }
}
inline void write(char *first) {
  while (*first) {
    putc(*first);
    ++first;
  }
}
template <typename A, typename... B>
inline void write(A first, B... second) {
  write(first);
  write(second...);
}
struct Flusher_ {
  ~Flusher_() { flush(); }
} io_flusher_;
}  // namespace io
using io ::putc;
using io ::read;
using io ::write;
const long long p = 1000000007;
long long fpm(long long a, long long b) {
  long long c = 1;
  for (; b; b >>= 1, a = a * a % p)
    if (b & 1) c = c * a % p;
  return c;
}
struct xll {
  long long a, b;
  xll() { a = b = 0; }
  xll(long long first) {
    a = first;
    b = 0;
  }
  xll(long long first, long long second) {
    a = first;
    b = second;
  }
  xll operator+(xll other) { return xll((a + other.a) % p, (b + other.b) % p); }
  xll operator-(xll other) {
    return xll((a - other.a + p) % p, (b - other.b + p) % p);
  }
  xll operator*(xll other) {
    return xll((a * other.a + 5 * b * other.b) % p,
               (a * other.b + b * other.a) % p);
  }
  xll operator/(xll other) {
    long long inv =
        fpm((5 * other.b * other.b % p + p - other.a * other.a % p) % p, p - 2);
    return xll((5 * b * other.b % p + p - a * other.a % p) * inv % p,
               (a * other.b % p + p - b * other.a % p) * inv % p);
  }
};
xll fpm(xll a, long long b) {
  xll c = 1;
  for (; b; b >>= 1, a = a * a)
    if (b & 1) c = c * a;
  return c;
}
xll a, b;
long long f[205], c[205][205];
int main() {
  long long k, l, r;
  read(k, l, r);
  l += 2;
  r += 3;
  f[0] = 1;
  for (long long i = 0; i < k; ++i) {
    for (long long j = i; ~j; --j) {
      f[j + 1] = (f[j + 1] + f[j]) % p;
      f[j] = f[j] * (p - i) % p;
    }
  }
  long long half = (p + 1) >> 1;
  a = xll(half, half);
  b = xll(half, p - half);
  xll s = 1, ans = 0, first, sum;
  c[0][0] = 1;
  for (long long i = 1; i <= k; ++i) {
    s = s * (a - b);
    c[i][0] = c[i][i] = 1;
    for (long long j = 1; j < i; ++j)
      c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % p;
    first = 1;
    for (long long j = 1; j <= i; ++j) first = first * a;
    sum = 0;
    for (long long j = 0; j <= i; ++j) {
      long long af = c[i][j];
      if (j & 1) af = p - af;
      if (first.a == 1 && first.b == 0) {
        sum = (sum + xll(r - l) * xll(af));
      } else
        sum = sum +
              ((fpm(first, r) - fpm(first, l)) / (first - xll(1)) * xll(af));
      first = first / a * b;
    }
    ans = ans + sum * xll(f[i]) / s;
  }
  long long Ans = ans.a, w = 1;
  for (long long i = 1; i <= k; ++i) {
    w = w * i % p;
  }
  Ans = Ans * fpm(w, p - 2) % p;
  printf("%lld\n", Ans);
  return 0;
}
