#include <bits/stdc++.h>
using namespace std;
long long k;
const int N = 50010;
int n, m, mod, s[N];
pair<long long, int> c[N];
struct mat {
  int a, b, c, d;
  mat(int a = 0, int b = 0, int c = 0, int d = 0) : a(a), b(b), c(c), d(d) {}
  mat operator*(const mat &h) const {
    mat r;
    r.a = ((long long)a * h.a + (long long)b * h.c) % mod;
    r.b = ((long long)a * h.b + (long long)b * h.d) % mod;
    r.c = ((long long)c * h.a + (long long)d * h.c) % mod;
    r.d = ((long long)c * h.b + (long long)d * h.d) % mod;
    return r;
  }
};
mat qpow(mat b, long long p) {
  mat r(1, 0, 0, 1);
  for (; p; p >>= 1) {
    if (p & 1) r = r * b;
    b = b * b;
  }
  return r;
}
mat ss[N << 1];
inline void build(int p, int l, int r) {
  if (l == r) {
    ss[p] = mat(s[l], 1, s[(l + n - 1) % n], 0);
    return;
  }
  build((p << 1), l, ((l + r) >> 1));
  build((p << 1 | 1), ((l + r) >> 1) + 1, r);
  ss[p] = ss[(p << 1)] * ss[(p << 1 | 1)];
}
mat query(int p, int l, int r, int ql, int qr) {
  if (l == ql && r == qr) {
    return ss[p];
  }
  if (qr <= ((l + r) >> 1)) {
    return query((p << 1), l, ((l + r) >> 1), ql, qr);
  } else if (ql > ((l + r) >> 1)) {
    return query((p << 1 | 1), ((l + r) >> 1) + 1, r, ql, qr);
  } else {
    return query((p << 1), l, ((l + r) >> 1), ql, ((l + r) >> 1)) *
           query((p << 1 | 1), ((l + r) >> 1) + 1, r, ((l + r) >> 1) + 1, qr);
  }
}
mat ran(long long l, long long r) {
  if (l / n == r / n) {
    return query(1, 0, n - 1, l % n, r % n);
  } else {
    return query(1, 0, n - 1, l % n, n - 1) * qpow(ss[1], r / n - l / n - 1) *
           query(1, 0, n - 1, 0, r % n);
  }
}
map<long long, int> mp;
int get(long long x) {
  if (mp.count(x)) return mp[x];
  return s[x % n];
}
int main() {
  scanf("%lld%d%d", &k, &mod, &n);
  if (k <= 1) {
    printf("%d\n", (int)(k % mod));
    return 0;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &s[i]);
    s[i] %= mod;
  }
  scanf("%d", &m);
  for (int i = 0; i < m; i++) {
    scanf("%lld%d", &c[i].first, &c[i].second);
    c[i].second %= mod;
    mp[c[i].first] = c[i].second;
  }
  c[++m] = make_pair(k - 2, 0);
  sort(c, c + m);
  build(1, 0, n - 1);
  long long last = 1;
  mat f(1, 0, 0, 0);
  for (int i = 0; i < m && last < k; i++) {
    long long x = c[i].first;
    if (last < x) {
      f = f * ran(last, x - 1);
      last = x;
    }
    if (last == x) {
      f = f * mat(get(x), 1, get(x - 1), 0);
      last = x + 1;
    }
    if (last == x + 1) {
      f = f * mat(get(x + 1), 1, get(x), 0);
      last = x + 2;
    }
  }
  printf("%d\n", f.a);
}
