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
const int maxn = 3010;
int p[maxn][maxn];
vector<int> ans;
int cs(int x, int y) {
  if (p[x][y] != -1) return p[x][y];
  cout << "?"
       << " " << x << " " << y << '\n';
  cout.flush();
  cin >> p[x][y];
  p[y][x] = p[x][y];
  return p[x][y];
}
int p1, p2, now;
int n;
int main() {
  memset(p, -1, sizeof p);
  srand(time(0));
  cin >> n;
  p1 = 1, p2 = 2;
  now = cs(p1, p2);
  for (int i = 3; i <= n; i++) {
    int tmp1 = p1, tmp2 = p2;
    int k = cs(i, p1);
    if (k > now) continue;
    int k2 = cs(i, p2);
    if (k < now) {
      now = k;
      p1 = i, p2 = tmp1;
    }
    if (k2 < now) {
      now = k2, p1 = tmp2, p2 = i;
    }
  }
  int pos0;
  while (1) {
    int x = rand() % n + 1;
    if (x == p1 || x == p2) continue;
    if (cs(x, p1) < cs(x, p2)) {
      pos0 = p1;
      break;
    }
    if (cs(x, p1) > cs(x, p2)) {
      pos0 = p2;
      break;
    }
  }
  for (int i = 1; i <= n; i++) {
    if (pos0 == i) {
      ans.push_back(0);
    } else
      ans.push_back(cs(pos0, i));
  }
  cout << "! ";
  for (int i = 0; i < n; i++) {
    cout << ans[i] << " ";
  }
  cout.flush();
  return 0;
}
