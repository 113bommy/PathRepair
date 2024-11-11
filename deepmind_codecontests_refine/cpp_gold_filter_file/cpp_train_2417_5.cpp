#include <bits/stdc++.h>
using namespace std;
long long inf;
const long double eps = 1e-8;
const long double pi = acos(-1.0);
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
struct __INIT__ {
  __INIT__() { memset(&inf, 0x3f, sizeof(inf)); }
} __INIT___;
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
template <typename A>
inline bool read(A &first) {
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
  while ((first = (iS == iT ? (iT = (iS = ibuf) + fread(ibuf, 1, SIZE, stdin),
                               (iS == iT ? EOF : *iS++))
                            : *iS++)) == ' ' ||
         first == '\n' || first == '\r')
    ;
  return first != EOF;
}
inline bool read(char *first) {
  while ((*first = (iS == iT ? (iT = (iS = ibuf) + fread(ibuf, 1, SIZE, stdin),
                                (iS == iT ? EOF : *iS++))
                             : *iS++)) == '\n' ||
         *first == ' ' || *first == '\r')
    ;
  if (*first == EOF) return 0;
  while (!(*first == '\n' || *first == '\r'))
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
template <typename A>
inline bool write(A first) {
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
pair<long long, long long> a[2505];
pair<long long, long long> b[5005];
long long c[2505];
long long cross(pair<long long, long long> a, pair<long long, long long> b) {
  return a.first * b.second - a.second * b.first;
}
long long fx(pair<long long, long long> a) {
  if (a.first >= 0 && a.second >= 0) return 0;
  if (a.first <= 0 && a.second >= 0) return 1;
  if (a.first <= 0 && a.second <= 0) return 2;
  return 3;
}
bool cmp(pair<long long, long long> a, pair<long long, long long> b) {
  if (fx(a) != fx(b)) return fx(a) < fx(b);
  return cross(a, b) > 0;
}
signed main() {
  long long n, m;
  read(n);
  for (long long i = 1; i <= n; ++i) {
    read(a[i].first, a[i].second);
  }
  long long ans = 0;
  for (long long i = 1; i <= n; ++i) {
    c[i] = (long long)i * (i - 1) * (i - 2) / 6;
  }
  for (long long i = 1; i <= n; ++i) {
    m = 0;
    for (long long j = 1; j <= n; ++j) {
      if (j != i)
        b[++m] = make_pair(a[j].first - a[i].first, a[j].second - a[i].second);
    }
    sort(b + 1, b + m + 1, cmp);
    for (long long i = 1; i <= m; ++i) b[i + m] = b[i];
    ans += (long long)m * (m - 1) * (m - 2) * (m - 3) / 24;
    for (long long i = 1, j = 1; i <= m + m; ++i) {
      if (j == i - m) ++j;
      while (j < i && cross(b[i], b[j]) > 0) ++j;
      if (i > m) ans -= c[i - j];
    }
  }
  write(ans, '\n');
  return 0;
}
