#include <bits/stdc++.h>
struct IO {
  static const int L = 1000000;
  char a[L], b[L], r[30], *s, *t, *z;
  IO() : z(b) {}
  ~IO() {
    if (z != b) fwrite(b, 1, z - b, stdout);
  }
  char gc() {
    if (s == t) t = (s = a) + fread(a, 1, L, stdin);
    return s == t ? EOF : *s++;
  }
  template <class T>
  IO &operator>>(T &x) {
    char c = gc();
    for (; c != '-' && !isdigit(c); c = gc())
      ;
    bool f = c == '-';
    if (f) c = gc();
    x = c - '0';
    for (c = gc(); isdigit(c); c = gc()) x = x * 10 + (c - '0');
    if (f) x = -x;
    return *this;
  }
  IO &operator>>(char *x) {
    char c = gc();
    for (; !isgraph(c); c = gc())
      ;
    *x++ = c;
    for (c = gc(); isgraph(c); *x++ = c, c = gc())
      ;
    *x++ = 0;
    return *this;
  }
  IO &operator>>(char &x) {
    for (x = gc(); !isgraph(x); x = gc())
      ;
    return *this;
  }
  template <class T>
  operator T() {
    T x;
    *this >> x;
    return x;
  }
  void pc(const char x) {
    if (z == b + L) fwrite(z = b, 1, L, stdout);
    *z++ = x;
  }
  void fl() {
    fwrite(b, 1, z - b, stdout);
    z = b;
  }
  template <class T>
  struct d {
    T x;
    int l;
    d(const T x_, const int l_) : x(x_), l(l_) {}
  };
  template <class T>
  static d<T> dio(const T x, const int l) {
    return d<T>(x, l);
  }
  template <class T>
  IO &operator<<(T x) {
    if (x == 0)
      pc('0');
    else {
      if (x < 0) pc('-'), x = -x;
      T y;
      char *j;
      for (j = r; x; x = y) y = x / 10, *j++ = x - y * 10 + '0';
      while (j != r) pc(*--j);
    }
    return *this;
  }
  template <class T>
  IO &operator<<(d<T> x) {
    if (x.x == 0)
      while (x.l--) pc('0');
    else {
      if (x.x < 0) pc('-'), x.x = -x.x;
      T y;
      char *j;
      for (j = r; x.x; x.x = y, --x.l) y = x.x / 10, *j++ = x.x - y * 10 + '0';
      for (; x.l > 0; pc('0'), --x.l)
        ;
      while (j != r) pc(*--j);
    }
    return *this;
  }
  IO &operator<<(d<double> x) {
    if (x.x < 0) pc('-'), x.x = -x.x;
    int w = floor(x.x);
    *this << w;
    pc('.');
    int e = (x.x - w) * pow(10, x.l + 1);
    if (e % 10 >= 5)
      e /= 10, ++e;
    else
      e /= 10;
    return *this << d<int>(e, x.l);
  }
  IO &operator<<(const char *x) {
    while (*x) pc(*x++);
    return *this;
  }
  IO &operator<<(const char x) {
    pc(x);
    return *this;
  }
} io;
const int N = 0;
int n, a[300];
int main() {
  int s = 0;
  n = io;
  for (int i = (0); i < (n); ++i) a[i] = io, s += a[i];
  std::sort(a, a + n);
  int cnt = 0;
  for (int i = (0); i < (n); ++i) {
    if (2 * s >= 9 * n) {
      io << cnt << '\n';
      return 0;
    }
    s -= a[i];
    s += 5;
    ++cnt;
  }
  return 0;
}
