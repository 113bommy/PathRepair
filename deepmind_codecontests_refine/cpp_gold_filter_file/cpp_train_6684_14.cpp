#include <bits/stdc++.h>
using namespace std;
inline char gc() {
  static const int L = 233333;
  static char sxd[L], *sss = sxd, *ttt = sxd;
  if (sss == ttt) {
    ttt = (sss = sxd) + fread(sxd, 1, L, stdin);
    if (sss == ttt) {
      return EOF;
    }
  }
  return *sss++;
}
inline char readalpha() {
  char c = gc();
  for (; !isalpha(c); c = gc())
    ;
  return c;
}
inline char readchar() {
  char c = gc();
  for (; c == ' '; c = gc())
    ;
  return c;
}
template <class T>
inline bool read(T& x) {
  bool flg = false;
  char c = gc();
  x = 0;
  for (; !isdigit(c); c = gc()) {
    if (c == '-') {
      flg = true;
    } else if (c == EOF) {
      return false;
    }
  }
  for (; isdigit(c); c = gc()) {
    x = (x << 1) + (x << 3) + (c ^ 48);
  }
  if (flg) {
    x = -x;
  }
  return true;
}
template <class T>
inline void write(T x) {
  if (x < 0) {
    putchar('-');
    x = -x;
  }
  if (x < 10) {
    putchar(x | 48);
    return;
  }
  write(x / 10);
  putchar((x % 10) | 48);
}
template <class T>
inline void writesp(T x) {
  write(x);
  putchar(' ');
}
template <class T>
inline void writeln(T x) {
  write(x);
  puts("");
}
const int mod = 998244353;
inline int ksm(int a, int b) {
  int ans = 1;
  for (; b; b >>= 1, a = (long long)a * a % mod) {
    if (b & 1) {
      ans = (long long)ans * a % mod;
    }
  }
  return ans;
}
const int maxn = 200005;
int n, q;
int inv[233];
int p[maxn];
int qzhp[maxn];
int ny[maxn];
int qzhny[maxn];
set<int> gj;
inline void add(int& x, const int y) {
  x += y;
  if (x >= mod) {
    x -= mod;
  }
}
struct Tree {
  struct Node {
    int lzy, sum;
  } no[maxn << 2];
  inline void push_up(int k) {
    no[k].sum = 0;
    add(no[k].sum, no[(k << 1)].sum);
    add(no[k].sum, no[(k << 1 | 1)].sum);
  }
  inline void build_tree(int l, int r, int k) {
    no[k].lzy = 1;
    if (l == r) {
      no[k].sum = (long long)qzhny[n] * qzhp[l - 1] % mod;
      return;
    }
    int mid = (l + r) >> 1;
    build_tree(l, mid, (k << 1));
    build_tree(mid + 1, r, (k << 1 | 1));
    push_up(k);
  }
  inline void push_down(int k) {
    if (no[k].lzy != 1) {
      no[(k << 1)].lzy = (long long)no[(k << 1)].lzy * no[k].lzy % mod;
      no[(k << 1 | 1)].lzy = (long long)no[(k << 1 | 1)].lzy * no[k].lzy % mod;
      no[(k << 1)].sum = (long long)no[(k << 1)].sum * no[k].lzy % mod;
      no[(k << 1 | 1)].sum = (long long)no[(k << 1 | 1)].sum * no[k].lzy % mod;
      no[k].lzy = 1;
    }
  }
  inline void update(int l, int r, int k, int L, int R, int x) {
    if (L <= l && r <= R) {
      no[k].lzy = (long long)no[k].lzy * x % mod;
      no[k].sum = (long long)no[k].sum * x % mod;
      return;
    }
    push_down(k);
    int mid = (l + r) >> 1;
    if (L <= mid) {
      update(l, mid, (k << 1), L, R, x);
    }
    if (R > mid) {
      update(mid + 1, r, (k << 1 | 1), L, R, x);
    }
    push_up(k);
  }
  inline int query() { return no[1].sum; }
  inline void query(int l, int r, int k) {
    if (l == r) {
      printf("%d ", no[k].sum);
      return;
    }
    int mid = (l + r) >> 1;
    push_down(k);
    query(l, mid, (k << 1));
    query(mid + 1, r, (k << 1 | 1));
  }
} tr;
template <typename _EuclideanRingElement>
_EuclideanRingElement gcd(_EuclideanRingElement __m,
                          _EuclideanRingElement __n) {
  while (__n) {
    _EuclideanRingElement __t = __m % __n;
    __m = __n;
    __n = __t;
  }
  return __m;
}
int main() {
  for (int i = 1; i <= 100; ++i) {
    inv[i] = ksm(i, mod - 2);
  }
  read(n), read(q);
  qzhp[0] = qzhny[0] = 1;
  for (int i = 1; i <= n; ++i) {
    read(p[i]);
    int fm = 100;
    int g = gcd(p[i], fm);
    fm /= g, p[i] /= g;
    p[i] = (long long)p[i] * inv[fm] % mod;
    qzhp[i] = (long long)qzhp[i - 1] * p[i] % mod;
    ny[i] = ksm(p[i], mod - 2);
    qzhny[i] = (long long)qzhny[i - 1] * ny[i] % mod;
  }
  gj.insert(1);
  gj.insert(n + 1);
  tr.build_tree(1, n, 1);
  while (q--) {
    int x;
    read(x);
    if (gj.count(x)) {
      auto it = --gj.find(x);
      int l = *it, r = x - 1;
      int xx = *gj.upper_bound(x) - 1;
      tr.update(1, n, 1, l, r, (long long)qzhny[xx] * qzhp[x - 1] % mod);
      gj.erase(x);
    } else {
      auto it = gj.lower_bound(x);
      int hou = *it - 1;
      int qian = *(--it);
      tr.update(1, n, 1, qian, x - 1,
                (long long)qzhp[hou] * qzhny[x - 1] % mod);
      gj.insert(x);
    }
    writeln(tr.query());
  }
  return 0;
}
