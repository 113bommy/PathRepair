#include <bits/stdc++.h>
using namespace std;
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
  while (!(*first == '\n' || *first == ' ' || *first == '\r' || *first == EOF))
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
long long inf;
struct _init_ {
  _init_() { memset(&inf, 0x3f, sizeof(inf)); }
};
_init_ ___INIT__;
long long s[1000005], a[1000005];
long long n, first, m, w[500005];
bool chk(long long first, long long second, long long a, long long b) {
  if (b < 2) return 0;
  if (a < second) return 0;
  a -= second;
  if (a < (second / first) * 2) return 0;
  a -= ((second - 1) / first) * 2;
  if (a >= 2) return 1;
  long long mo = second % first;
  for (long long i = (second / first) * first; i <= n; i += first) {
    a += s[i + first - 1] - s[i + mo - 1];
    if (a >= 2) return 1;
  }
  return 0;
}
bool chk2(long long first, long long second, long long a, long long b) {
  if (!b) return 0;
  if (a < second) return 0;
  if (w[m] < second * 2) return 0;
  a -= second;
  if (a < (second * 2 / first)) return 0;
  a -= (second * 2 - 1) / first;
  if (a >= 1) return 1;
  long long mo = (second * 2) % first;
  for (long long i = (second << 1) / first * first; i <= first; i += first) {
    if (s[i + first - 1] - s[i + mo - 1]) return 1;
  }
  return 0;
}
signed main() {
  read(m);
  for (long long i = 1; i <= m; ++i) {
    read(w[i]);
    ++a[w[i]];
  }
  sort(w + 1, w + m + 1);
  n = 500000;
  for (long long i = 1; i <= n + n; ++i) s[i] = s[i - 1] + a[i];
  first = a[n];
  long long ans = 0;
  for (long long i = 2, k = n; i <= n; ++i) {
    long long j = i, w = 0;
    while (j <= n) {
      w += (s[n] - s[j - 1]);
      j += i;
    }
    while (k > 1 && !chk(i, k, w, first) && !chk2(i, k, w, first)) {
      --k;
      first += a[k];
    }
    if (k > 1) chkmax(ans, i * k);
  }
  write(ans, '\n');
  return 0;
}
