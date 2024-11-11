#include <bits/stdc++.h>
using namespace std;
int inf;
const double eps = 1e-8;
const double pi = acos(-1.0);
template <class T>
int chkmin(T &a, T b) {
  return a > b ? a = b, 1 : 0;
}
template <class T>
int chkmax(T &a, T b) {
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
int dcmp(T a, T b) {
  return a > b;
}
template <int *a>
int cmp_a(int first, int second) {
  return a[first] < a[second];
}
struct __INIT__ {
  __INIT__() { memset(&inf, 0x3f, sizeof(inf)); }
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
int h[3605], l[3605];
int c[3605][3605];
int C[3605][3605];
int a[3605][3605];
int b[3605][3605];
int fac[3605];
const int p = 998244353;
signed main() {
  int n, m, k, wxwakioi, cfakioi, cyakioi, sysakioi;
  read(n, m, k);
  for (int i = 1; i <= k; ++i) {
    read(wxwakioi, cyakioi, cfakioi, sysakioi);
    if (h[wxwakioi]) return write("0\n");
    if (h[cfakioi]) return write("0\n");
    if (l[cyakioi]) return write("0\n");
    if (l[sysakioi]) return write("0\n");
    h[wxwakioi] = h[cfakioi] = 1;
    l[cyakioi] = l[sysakioi] = 1;
  }
  fac[0] = 1;
  for (int i = 1; i <= 3600; ++i) fac[i] = (long long)fac[i - 1] * i % p;
  for (int i = 0; i <= 3600; ++i) {
    C[i][0] = C[i][i] = 1;
    for (int j = 1; j < i; ++j) C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % p;
  }
  c[0][0] = 1;
  int ch = 0;
  for (int i = 1; i <= n; ++i) {
    ch += !h[i];
    c[i][0] = 1;
    for (int j = 1; j <= n; ++j) {
      c[i][j] = c[i - 1][j];
      if (i > 1 && !h[i] && !h[i - 1])
        c[i][j] = (c[i][j] + c[i - 2][j - 1]) % p;
    }
  }
  for (int i = 0; i <= n && i + i <= ch; ++i)
    for (int j = 0; j <= n; ++j)
      a[i][j] = (long long)c[n][i] * C[ch - i * 2][j] % p;
  int cl = 0;
  for (int i = 1; i <= m; ++i) {
    cl += !l[i];
    c[i][0] = 1;
    for (int j = 1; j <= m; ++j) {
      c[i][j] = c[i - 1][j];
      if (i > 1 && !l[i] && !l[i - 1])
        c[i][j] = (c[i][j] + c[i - 2][j - 1]) % p;
    }
  }
  for (int i = 0; i <= m && i + i <= cl; ++i)
    for (int j = 0; j <= m; ++j)
      b[i][j] = (long long)c[m][i] * C[cl - i * 2][j] % p;
  int ans = 0;
  for (int i = 0; i <= n; ++i)
    for (int j = 0; j <= n; ++j)
      ans = (ans + (long long)a[i][j] * b[j][i] % p * fac[i] % p * fac[j] % p) %
            p;
  write(ans, '\n');
  return 0;
}
