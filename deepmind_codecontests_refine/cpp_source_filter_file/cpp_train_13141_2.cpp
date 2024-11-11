#include <bits/stdc++.h>
using namespace std;
long long inf;
const double eps = 1e-8;
const double pi = acos(-1.0);
template <class T, class T2>
long long chkmin(T &a, T2 b) {
  return a > b ? a = b, 1 : 0;
}
template <class T, class T2>
long long chkmax(T &a, T2 b) {
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
long long a[500005], p[500005], b[500005];
struct smt {
  long long tag;
  long long ls, rs;
  smt *l, *r;
  smt(long long la, long long ra) {
    ls = la;
    rs = ra;
    if (ls == rs) {
      l = r = 0;
      tag = inf;
    } else {
      tag = 0;
      long long mid = (ls + rs) >> 1;
      l = new smt(ls, mid);
      r = new smt(mid + 1, rs);
    }
  }
  void push_down() {
    l->tag += tag;
    r->tag += tag;
    tag = 0;
  }
  void add(long long la, long long ra, long long w) {
    if (la <= ls && rs <= ra) {
      tag += w;
      return;
    }
    push_down();
    if (la <= l->rs) l->add(la, ra, w);
    if (r->ls <= ra) r->add(la, ra, w);
  }
  void ckmn(long long first, long long second) {
    if (ls == rs) {
      chkmin(tag, second);
      return;
    }
    push_down();
    if (first <= l->rs)
      l->ckmn(first, second);
    else
      r->ckmn(first, second);
  }
  long long query(long long first) {
    if (ls == rs) return tag;
    push_down();
    return first <= l->rs ? l->query(first) : r->query(first);
  }
};
smt *rt;
signed main() {
  long long n, m;
  read(n);
  for (long long i = 1; i <= n; ++i) read(a[i]);
  long long s = 0;
  for (long long i = 1; i <= n; ++i) {
    read(p[i]);
    s += p[i];
  }
  read(m);
  for (long long i = 1; i <= m; ++i) read(b[i]);
  rt = new smt(0, m);
  rt->ckmn(0, 0);
  for (long long i = 1; i <= n; ++i) {
    long long at = lower_bound(b + 1, b + m + 1, a[i]) - b;
    if (b[at] == a[i]) {
      if (p[i] >= 0) {
        rt->ckmn(at, rt->query(at - 1));
        rt->add(0, at - 1, p[i]);
      } else {
        rt->tag += p[i];
        rt->ckmn(at, rt->query(at - 1) - p[i]);
      }
    } else {
      if (p[i] < 0)
        rt->tag += p[i];
      else
        rt->add(0, at - 1, p[i]);
    }
  }
  long long w = rt->query(m);
  if (w > s) {
    write("NO\n");
    return 0;
  } else
    write("YES\n", w, '\n');
  return 0;
}
