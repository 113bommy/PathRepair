#include <bits/stdc++.h>
using namespace std;
int inf;
const double eps = 1e-8;
const double pi = acos(-1.0);
template <class T, class T2>
int chkmin(T &a, T2 b) {
  return a > b ? a = b, 1 : 0;
}
template <class T, class T2>
int chkmax(T &a, T2 b) {
  return a < b ? a = b, 1 : 0;
}
template <class T>
T sqr(T a) {
  return a * a;
}
template <class T, class T2>
T mmin(T a, T2 b) {
  return a < b ? a : b;
}
template <class T, class T2>
T mmax(T a, T2 b) {
  return a > b ? a : b;
}
template <class T>
T aabs(T a) {
  return a < 0 ? -a : a;
}
template <class T>
int dcmp(T a, T b) {
  return a > b;
}
template <int *a>
int cmp_a(int first, int second) {
  return a[first] < a[second];
}
template <class T>
bool sort2(T &a, T &b) {
  return a > b ? swap(a, b), 1 : 0;
}
struct __INIT__ {
  __INIT__() {
    fill((unsigned char *)&inf, (unsigned char *)&inf + sizeof(inf), 0x3f);
  }
} __INIT___;
namespace io {
const int SIZE = (1 << 21) + 1;
char ibuf[SIZE], *iS, *iT, obuf[SIZE], *oS = obuf, *oT = oS + SIZE - 1, c,
                                       qu[55];
int f, qr;
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
const int N = 100000;
pair<int, int> a[1000005];
int n;
void make() {
  int first, second, r;
  read(first, second, r);
  if (first >= r) {
    a[++n] = {first - r, second};
  } else {
    a[++n] = {0, mmin(second + r - first, N)};
    a[++n] = {0, mmax(second - r + first, 0)};
  }
  if (second >= r) {
    a[++n] = {first, second - r};
  } else {
    a[++n] = {mmax(first - (r - second), 0), 0};
    a[++n] = {mmin(first + (r - second), N), 0};
  }
  if (first + r <= N) {
    a[++n] = {first + r, second};
  } else {
    a[++n] = {N, mmin(second + (r - (N - first)), N)};
    a[++n] = {N, mmax(second + (r - (N - first)), 0)};
  }
  if (second + r <= N) {
    a[++n] = {first, second + r};
  } else {
    a[++n] = {mmin(first + (r - (N - second)), N), N};
    a[++n] = {mmax(first + (r - (N - second)), 0), N};
  }
}
pair<int, int> b[1000005];
int t;
int c;
pair<int, int> stk[1000005];
void build() {
  t = 0;
  for (int i = 1; i <= n; ++i) {
    while (t > 1 && (long long)(a[i].second - stk[t].second) *
                            (a[i].first - stk[t - 1].first) <=
                        (long long)(a[i].second - stk[t - 1].second) *
                            (a[i].first - stk[t].first))
      --t;
    stk[++t] = a[i];
  }
  for (int i = 1; i <= t; ++i) b[++c] = stk[i];
  t = 0;
  for (int i = 1; i <= n; ++i) {
    while (t > 1 && (long long)(a[i].second - stk[t].second) *
                            (a[i].first - stk[t - 1].first) >=
                        (long long)(a[i].second - stk[t - 1].second) *
                            (a[i].first - stk[t].first))
      --t;
    stk[++t] = a[i];
  }
  while (t && stk[t] == b[c]) --t;
  while (t > 1) {
    b[++c] = stk[t];
    --t;
  }
  t = c;
}
double calc(pair<int, int> a, pair<int, int> b, pair<int, int> c) {
  double A, B, C, D, E, F;
  A = 2 * (a.first - b.first);
  B = 2 * (a.second - b.second);
  C = (sqr(double(a.first)) + sqr(double(a.second))) -
      (sqr(double(b.first)) + sqr(double(b.second)));
  D = 2 * (a.first - c.first);
  E = 2 * (a.second - c.second);
  F = (sqr(double(a.first)) + sqr(double(a.second))) -
      (sqr(double(c.first)) + sqr(double(c.second)));
  double first, second;
  second = (C * D - A * F) / (B * D - A * E);
  first = (C * E - B * F) / (A * E - B * D);
  return sqr(first - a.first) + sqr(second - a.second);
}
signed main() {
  int m;
  read(m);
  for (int i = 1; i <= m; ++i) {
    make();
  }
  sort(a + 1, a + n + 1);
  build();
  b[t + 1] = b[1];
  b[t + 2] = b[2];
  double ans = 0;
  pair<int, int> first, second, z;
  for (int i = 1; i <= t; ++i) {
    if (chkmax(ans, calc(b[i], b[i + 1], b[i + 2]))) {
      first = b[i];
      second = b[i + 1];
      z = b[i + 2];
    }
  }
  write(first.first, ' ', first.second, '\n');
  write(second.first, ' ', second.second, '\n');
  write(z.first, ' ', z.second, '\n');
  return 0;
}
