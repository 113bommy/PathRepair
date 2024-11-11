#include <bits/stdc++.h>
using namespace std;
const int LEN = 1 << 20 | 1;
static char buf[LEN], *_s, *_t;
static char obuf[LEN], *O = obuf;
struct ios {
  inline bool Isdigit(char c) { return (c >= '0' && c <= '9') ? 1 : 0; }
  inline char gc() {
    return (_s == _t) && (_t = (_s = buf) + fread(buf, 1, LEN, stdin)),
           _s == _t ? -1 : *_s++;
    return getchar();
  }
  template <class T>
  inline ios& operator>>(T& x) {
    static char ch, sgn;
    ch = gc(), sgn = 0;
    for (; !isdigit(ch); ch = gc()) {
      if (ch == -1) return *this;
      sgn |= ch == '-';
    }
    for (x = 0; isdigit(ch); ch = gc()) x = x * 10 + (ch ^ '0');
    sgn && (x = -x);
    return *this;
  }
  inline void flush() {
    fwrite(obuf, 1, O - obuf, stdout);
    O = obuf;
    fflush(stdout);
  }
  ~ios() { flush(); }
  inline void pr(const char c) {
    if (O - obuf > LEN - 2) flush();
    *O++ = c;
    return;
    return (void)putchar(c);
  }
  template <class T>
  inline ios& operator<<(T x) {
    static char a[25] = {0}, *p = a;
    if (x < 0) pr('-'), x = -x;
    if (x == 0) pr('0');
    while (x) *(++p) = x % 10, x /= 10;
    while (p != a) pr(char(*(p--)) + '0');
    return *this;
  }
  inline ios& operator<<(const char c) {
    pr(c);
    return *this;
  }
} io;
template <class T>
inline bool Chkmax(T& x, const T& y) {
  return x < y ? x = y, true : false;
}
template <class T>
inline bool Chkmin(T& x, const T& y) {
  return x > y ? x = y, true : false;
}
const int maxn = 2020;
int n;
int ans[maxn][maxn];
struct node {
  int x, id;
} a[maxn];
int cmp(node a, node b) { return a.x > b.x; }
int main() {
  io >> n;
  for (int i = 1; i <= n; i++) {
    io >> a[i].x;
    a[i].id = i;
  }
  sort(a + 1, a + 1 + n, cmp);
  for (int i = 1; i <= n; i++) {
    int be = i;
    for (int j = 1; j <= a[i].x; j++) {
      ans[be][a[i].id] = 1;
      be = (be + 1);
      if (be == n + 2) be = 1;
    }
  }
  printf("%d\n", n + 1);
  for (int i = 1; i <= n + 1; i++) {
    for (int j = 1; j <= n; j++) {
      printf("%d", ans[i][j]);
    }
    puts("");
  }
  return 0;
}
