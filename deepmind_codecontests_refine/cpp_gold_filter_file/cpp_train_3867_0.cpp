#include <bits/stdc++.h>
inline int getint() {
  register char ch;
  while (!isdigit(ch = getchar()))
    ;
  register int x = ch ^ '0';
  while (isdigit(ch = getchar())) x = (((x << 2) + x) << 1) + (ch ^ '0');
  return x;
}
inline char getalpha() {
  register char ch;
  while (!isalpha(ch = getchar()))
    ;
  return ch;
}
const int N = 4e5 + 1, Q = 2e5, A = 301, P = 63, mod = 1e9 + 7;
bool vis[A];
int p[P], pinv[P];
inline void sieve() {
  for (register int i = 2; i < A; i++) {
    if (!vis[i]) p[++p[0]] = i;
    for (register int j = 1; j <= p[0] && p[j] * i < A; j++) {
      vis[p[j] * i] = true;
      if (i % p[j] == 0) break;
    }
  }
}
void exgcd(const int &a, const int &b, int &x, int &y) {
  if (!b) {
    x = 1, y = 0;
    return;
  }
  exgcd(b, a % b, y, x);
  y -= a / b * x;
}
inline int inv(const int &x) {
  int ret, tmp;
  exgcd(x, mod, ret, tmp);
  return (ret % mod + mod) % mod;
}
inline void init() {
  sieve();
  for (register int i = 1; i < P; i++) {
    pinv[i] = inv(p[i]);
  }
}
inline long long get_bitmask(const int &x) {
  long long ret = 0;
  for (register int i = 1; i < P; i++) {
    if (x % p[i] == 0) ret |= 1ll << i;
  }
  return ret;
}
inline int calc(const long long &s) {
  int ret = 1;
  for (register int i = 1; i < P; i++) {
    if (s >> i & 1) {
      ret = 1ll * ret * (mod + 1 - pinv[i]) % mod;
    }
  }
  return ret;
}
inline int power(int a, int k) {
  int ret = 1;
  for (; k; k >>= 1) {
    if (k & 1) ret = 1ll * ret * a % mod;
    a = 1ll * a * a % mod;
  }
  return ret;
}
class SegmentTree1 {
 private:
  long long val[N << 2], tag[N << 2];
  void push_down(const int &p) {
    if (!tag[p]) return;
    tag[p << 1] |= tag[p];
    tag[p << 1 | 1] |= tag[p];
    val[p << 1] |= tag[p];
    val[p << 1 | 1] |= tag[p];
    tag[p] = 0;
  }

 public:
  void modify(const int &p, const int &b, const int &e, const int &l,
              const int &r, const long long &x) {
    val[p] |= x;
    if (b == l && e == r) {
      tag[p] |= x;
      return;
    }
    push_down(p);
    if (l <= ((b + e) >> 1))
      modify(p << 1, b, ((b + e) >> 1), l, std::min(((b + e) >> 1), r), x);
    if (r > ((b + e) >> 1))
      modify(p << 1 | 1, ((b + e) >> 1) + 1, e, std::max(((b + e) >> 1) + 1, l),
             r, x);
  }
  long long query(const int &p, const int &b, const int &e, const int &l,
                  const int &r) {
    if (b == l && e == r) return val[p];
    long long ret = 0;
    push_down(p);
    if (l <= ((b + e) >> 1))
      ret |= query(p << 1, b, ((b + e) >> 1), l, std::min(((b + e) >> 1), r));
    if (r > ((b + e) >> 1))
      ret |= query(p << 1 | 1, ((b + e) >> 1) + 1, e,
                   std::max(((b + e) >> 1) + 1, l), r);
    return ret;
  }
};
SegmentTree1 t1;
class SegmentTree2 {
 private:
  int val[N << 2], tag[N << 2];
  int len(const int &b, const int &e) const { return e - b + 1; }
  void push_down(const int &p, const int &b, const int &e) {
    if (tag[p] == 1) return;
    tag[p << 1] = 1ll * tag[p << 1] * tag[p] % mod;
    tag[p << 1 | 1] = 1ll * tag[p << 1 | 1] * tag[p] % mod;
    val[p << 1] =
        1ll * val[p << 1] * power(tag[p], len(b, ((b + e) >> 1))) % mod;
    val[p << 1 | 1] =
        1ll * val[p << 1 | 1] * power(tag[p], len(((b + e) >> 1) + 1, e)) % mod;
    tag[p] = 1;
  }
  void push_up(const int &p) {
    val[p] = 1ll * val[p << 1] * val[p << 1 | 1] % mod;
  }

 public:
  void build(const int &p, const int &b, const int &e) {
    val[p] = tag[p] = 1;
    if (b == e) return;
    build(p << 1, b, ((b + e) >> 1));
    build(p << 1 | 1, ((b + e) >> 1) + 1, e);
  }
  void modify(const int &p, const int &b, const int &e, const int &l,
              const int &r, const int &x) {
    if (b == l && e == r) {
      val[p] = 1ll * val[p] * power(x, len(b, e)) % mod;
      tag[p] = 1ll * tag[p] * x % mod;
      return;
    }
    push_down(p, b, e);
    if (l <= ((b + e) >> 1))
      modify(p << 1, b, ((b + e) >> 1), l, std::min(((b + e) >> 1), r), x);
    if (r > ((b + e) >> 1))
      modify(p << 1 | 1, ((b + e) >> 1) + 1, e, std::max(((b + e) >> 1) + 1, l),
             r, x);
    push_up(p);
  }
  int query(const int &p, const int &b, const int &e, const int &l,
            const int &r) {
    if (b == l && e == r) return val[p];
    int ret = 1;
    push_down(p, b, e);
    if (l <= ((b + e) >> 1))
      ret = 1ll * ret *
            query(p << 1, b, ((b + e) >> 1), l, std::min(((b + e) >> 1), r)) %
            mod;
    if (r > ((b + e) >> 1))
      ret = 1ll * ret *
            query(p << 1 | 1, ((b + e) >> 1) + 1, e,
                  std::max(((b + e) >> 1) + 1, l), r) %
            mod;
    return ret;
  }
};
SegmentTree2 t2;
int main() {
  init();
  const int n = getint(), m = getint();
  t2.build(1, 1, n);
  for (register int i = 1; i <= n; i++) {
    const int a = getint();
    t1.modify(1, 1, n, i, i, get_bitmask(a));
    t2.modify(1, 1, n, i, i, a);
  }
  for (register int i = 0; i < m; i++) {
    const char ch = getalpha();
    const int l = getint(), r = getint();
    if (ch == 'M') {
      const int x = getint();
      t1.modify(1, 1, n, l, r, get_bitmask(x));
      t2.modify(1, 1, n, l, r, x);
    }
    if (ch == 'T') {
      printf("%lld\n", 1ll * calc(t1.query(1, 1, n, l, r)) *
                           t2.query(1, 1, n, l, r) % mod);
    }
  }
  return 0;
}
