#include <bits/stdc++.h>
const long long N = 216333, e7 = 1e7 + 7, inf = 1e17;
typedef long long aN[N];
long long readll() {
  long long x = 0, w = 1;
  int c = getchar();
  for (; c < '0' || c > '9'; c - '-' || (w = -w), c = getchar())
    ;
  for (; c >= '0' && c <= '9'; x = x * 10 + (c ^ 48), c = getchar())
    ;
  return x * w;
}
int readchar(int l = '0', int r = 'z') {
  int c = getchar();
  for (; c < l || c > r; c = getchar())
    ;
  return c;
}
struct qj {
  long long l, r;
};
qj operator&(const qj& a, const qj& b) {
  return (qj){std::max(a.l, b.l), std::min(a.r, b.r)};
}
struct bit {
  aN f;
  long long sum, n;
  void clear(long long x) { n = x, sum = 0, memset(f, 0, sizeof f); }
  void update(long long u, long long c) {
    sum += c;
    while (u <= n) f[u] += c, u += u & -u;
  }
  long long query(long long u) const {
    long long res = 0;
    while (u) res += f[u], u &= ~-u;
    return res;
  }
  long long query(qj b) const {
    b = b & (qj){1, n};
    return b.l <= b.r ? query(b.r) - query(b.l - 1) : 0;
  }
  long long min() const {
    long long u = 0;
    for (register long long i = 1 << 20; i; i >>= 1)
      if (i + u <= n && !f[i + u]) u += i;
    return u + 1;
  }
  long long max() const {
    long long u = 0, s = sum;
    for (register long long i = 1 << 20; i; i >>= 1)
      if (i + u <= n && f[i + u] < s) s -= f[u += i];
    return u + !!sum;
  }
} s[3];
long long t[1145], a[1145141], n, m;
void solve() {
  long long sum = 0;
  qj q, h;
  for (register long long i = 0; i <= 2; i++)
    sum +=
        s[i].query(q = (qj){s[(i + 1) % 3].min(), s[(i + 2) % 3].min() - 1}) +
        s[i].query(h = (qj){s[(i + 2) % 3].max() + 1, s[(i + 1) % 3].max()}),
        sum -= s[i].query(q & h);
  printf("%lld\n", n - sum);
};
int main() {
  t['P'] = 1, t['R'] = 0, t['S'] = 2, n = readll(), m = readll();
  s[0].clear(n), s[1].clear(n), s[2].clear(n);
  long long x, c;
  for (register long long i = 1; i <= n; i++)
    s[a[i] = t[readchar()]].update(i, 1);
  solve();
  for (register long long i = 1; i <= m; i++)
    x = readll(), c = readchar(), s[a[x]].update(x, -1),
    s[a[x] = t[c]].update(x, 1), solve();
  return 0;
}
