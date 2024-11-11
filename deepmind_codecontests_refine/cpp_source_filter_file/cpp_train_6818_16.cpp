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
int a[100005], b[100005], c[100005], w[100005], las[100005];
int out[100005];
int t;
int mx[100005], pmx[100005], f[100005], xlas[100005];
int fm[100005];
void add(int first, int second) {
  for (; first <= t; first += first & -first) chkmax(mx[first], second);
}
int query(int first) {
  int second = 0;
  for (; first; first ^= first & -first) chkmax(second, mx[first]);
  return second;
}
signed main() {
  int n, m;
  read(n);
  for (int i = 1; i <= n; ++i) {
    read(a[i]);
    out[i] = a[i];
  }
  read(m);
  for (int i = 1; i <= m; ++i) {
    read(w[i]);
  }
  sort(w + 1, w + m + 1);
  t = 0;
  for (int i = 1; i <= m; ++i) {
    if (b[t] != w[i]) b[++t] = w[i];
    ++c[t];
  }
  m = t;
  int cnt = 0;
  for (int i = 1; i <= n; ++i)
    if (~a[i]) {
      w[++cnt] = a[i];
    }
  sort(w + 1, w + cnt + 1);
  t = unique(w + 1, w + n + 1) - w - 1;
  w[++t] = inf;
  for (int i = 1, j = 0; i <= t; ++i) {
    while (j < m && b[j + 1] < w[i]) ++j;
    las[i] = j;
  }
  for (int i = 1; i <= n; ++i)
    if (~a[i]) a[i] = lower_bound(w + 1, w + t + 1, a[i]) - w;
  a[++n] = t;
  for (int i = 1; i <= n; ++i) {
    if (~a[i]) {
      if (chkmax(f[i], query(a[i] - 1) + 1)) xlas[i] = 0;
      if (chkmax(pmx[a[i]], f[i])) add(a[i], f[i]);
    } else {
      for (int j = 1, k = 1, mx = 0; j <= m; ++j) {
        while (k <= t && w[k] < b[j]) {
          chkmax(mx, pmx[k]);
          ++k;
        }
        fm[j] = mx;
      }
      for (int j = i + 1, w = 0; j <= n; ++j)
        if (~a[j]) {
          if (las[a[j]] > w && chkmax(f[j], fm[las[a[j]] - w] + w + 2))
            xlas[j] = i;
        } else
          ++w;
    }
  }
  int at = n;
  while (f[at] > 1) {
    if (!xlas[at]) {
      int i = at - 1;
      while (i) {
        if (~a[i] && a[i] < a[at] && f[i] + 1 == f[at]) {
          at = i;
          break;
        }
        --i;
      }
    } else {
      int xf = f[at];
      int s = las[a[at]], i = at;
      while (i >= xlas[at]) {
        if (!~a[i]) {
          out[i] = b[s];
          --c[s];
          --s;
          --xf;
        }
        --i;
      }
      while (i) {
        if (~a[i] && a[i] < b[s + 1] && f[i] + 1 == xf) {
          at = i;
          break;
        }
        --i;
      }
      if (!i) at = 0;
    }
  }
  --n;
  for (int i = 1, j = 1; i <= n; ++i)
    if (!~out[i]) {
      while (!c[j]) ++j;
      --c[j];
      out[i] = b[j];
    }
  for (int i = 1; i <= n; ++i) write(out[i], i == n ? '\n' : ' ');
  return 0;
}
