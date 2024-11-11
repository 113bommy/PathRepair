#include <bits/stdc++.h>
const long long maxn = 1e6 + 61;
struct BIT {
  std::vector<long long> c, cnt;
  long long n;
  BIT(long long _n) {
    n = _n + 1;
    c.resize(n + 1), cnt.resize(n + 1);
  }
  long long l(long long x) { return x & -x; }
  void u(long long x, long long y) {
    for (; x <= n; x += l(x)) c[x] += y, cnt[x] += (y > 0) ? 1 : -1;
  }
  std::pair<long long, long long> q(long long x) {
    std::pair<long long, long long> a = {0, 0};
    for (; x; x ^= l(x)) a.first += c[x], a.second += cnt[x];
    return a;
  }
};
signed main() {
  auto getZ = [&](char* s, long long len) {
    std::vector<long long> Z(len + 1, 0);
    Z[1] = len;
    for (long long i = 2, l = 0, r = 0; i <= len; i++) {
      if (i < r) Z[i] = std::min(Z[i - l + 1], r - i + 1);
      while (i + Z[i] <= len && s[i + Z[i]] == s[1 + Z[i]]) ++Z[i];
      if (i + Z[i] - 1 > r) l = i, r = i + Z[i] - 1;
    }
    return Z;
  };
  auto getP = [&](char* s, char* t, long long n, long long m) {
    std::vector<long long> Z = getZ(t, m), P(n + 1, 0);
    for (long long i = 1, l = 0, r = 0; i <= n; i++) {
      if (i < r) P[i] = std::min(Z[i - l + 1], r - i + 1);
      while (i + P[i] <= n && s[i + P[i]] == t[1 + P[i]]) ++P[i];
      if (i + P[i] - 1 > r) l = i, r = i + P[i] - 1;
    }
    return P;
  };
  long long n, m;
  static char a[maxn], b[maxn], s[maxn];
  scanf("%lld %lld", &n, &m);
  scanf("%s", a + 1), scanf("%s", b + 1), scanf("%s", s + 1);
  std::vector<long long> P = getP(a, s, n, m);
  std::reverse(b + 1, b + n + 1);
  std::reverse(s + 1, s + m + 1);
  std::vector<long long> Q = getP(b, s, n, m);
  reverse(Q.begin() + 1, Q.end());
  BIT bit(m + 1);
  for (long long i = 1; i <= n; i++) {
    if (P[i] == m) --P[i];
    if (Q[i] == m) --Q[i];
  }
  long long ans = 0;
  for (long long i = 1, j = 0; i <= n; i++) {
    while (j < n && j + 1 < i + m - 1) {
      ++j;
      if (Q[j]) bit.u(Q[j], Q[j]);
    }
    std::pair<long long, long long> x = bit.q(m), y = bit.q(m - P[i] - 1);
    ans += x.first - y.first - 1ll * (x.second - y.second) * (m - P[i] - 1);
    if (Q[i]) bit.u(Q[i], -Q[i]);
  }
  printf("%lld\n", ans);
}
