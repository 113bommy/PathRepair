#include <bits/stdc++.h>
using namespace std;
const signed inf = 0x3f3f3f3f;
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
char s[600005], t[600005], mx[600005];
int ans;
int n, m;
char a[10] = "ACGT";
void chk() {
  int cnt = 0;
  for (int i = 0; i < n; ++i) {
    int c0 = 0, c1 = 0;
    for (int j = 0; j < m; ++j) {
      if (a[(i & 1) << 1 | (j & 1)] == s[i * m + j]) ++c0;
      if (a[(i & 1) << 1 | (!(j & 1))] == s[i * m + j]) ++c1;
    }
    for (int j = 0; j < m; ++j)
      t[i * m + j] = a[(i & 1) << 1 | ((j & 1) ^ (c0 < c1))];
  }
  for (int i = 0; i < n * m; ++i)
    if (s[i] != t[i]) ++cnt;
  if (cnt < ans) {
    for (int i = 0; i < n * m; ++i) mx[i] = t[i];
    ans = cnt;
  }
  cnt = 0;
  for (int j = 0; j < m; ++j) {
    int c0 = 0, c1 = 0;
    for (int i = 0; i < n; ++i) {
      if (a[(j & 1) << 1 | (i & 1)] == s[i * m + j]) ++c0;
      if (a[(j & 1) << 1 | (!(i & 1))] == s[i * m + j]) ++c1;
    }
    for (int i = 0; i < n; ++i)
      t[i * m + j] = a[(j & 1) << 1 | ((i & 1) ^ (c0 < c1))];
  }
  for (int i = 0; i < n * m; ++i)
    if (s[i] != t[i]) ++cnt;
  if (cnt < ans) {
    for (int i = 0; i < n * m; ++i) mx[i] = t[i];
    ans = cnt;
  }
}
int main() {
  cin >> n >> m;
  ans = n * m;
  for (int i = 0; i < n * m; ++i) read(s[i]);
  for (int i = 1; i <= n; ++i) cin >> s[i];
  do {
    chk();
  } while (next_permutation(a, a + 4));
  for (int i = 0; i < n; ++i, write('\n'))
    for (int j = 0; j < m; ++j) write(mx[i * m + j]);
  return 0;
}
