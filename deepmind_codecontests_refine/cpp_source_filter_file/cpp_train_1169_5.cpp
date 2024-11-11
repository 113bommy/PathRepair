#include <bits/stdc++.h>
const int MAXN = 53 + 5;
const int ha = 998244353;
const int inv2 = 499122177;
int n, m;
long long b[MAXN];
inline void insert(long long x) {
  for (int i = m - 1; i >= 0; --i) {
    if ((x >> i) & 1) {
      if (b[i])
        x ^= b[i];
      else {
        b[i] = x;
        break;
      }
    }
  }
}
int sz;
inline void add(int &x, int y) {
  x += y;
  if (x >= ha) x -= ha;
}
namespace Subtask1 {
std::vector<long long> v;
int ans[233];
inline void dfs(int step, long long now) {
  if (step == sz) {
    add(ans[__builtin_popcount(now)], 1);
    return;
  }
  dfs(step + 1, now);
  dfs(step + 1, now ^ v[step]);
}
inline void Solve() {
  for (int i = 0; i <= m - 1; ++i)
    if (b[i]) v.push_back(b[i]);
  dfs(0, 0);
  int pw = 1;
  for (int i = 1; i <= n - sz; ++i) pw = 2ll * pw % ha;
  for (int i = 0; i <= m; ++i) printf("%lld ", 1ll * ans[i] * pw % ha);
  puts("");
  exit(0);
}
}  // namespace Subtask1
inline int qpow(int a, int n = ha - 2) {
  int res = 1;
  while (n) {
    if (n & 1) res = 1ll * res * a % ha;
    a = 1ll * a * a % ha;
    n >>= 1;
  }
  return res;
}
int fac[MAXN], inv[MAXN];
inline void prework() {
  fac[0] = 1;
  for (int i = 1; i <= MAXN - 1; ++i) fac[i] = 1ll * fac[i - 1] * i % ha;
  inv[MAXN - 1] = qpow(fac[MAXN - 1]);
  for (int i = MAXN - 2; i >= 0; --i) inv[i] = 1ll * inv[i + 1] * (i + 1) % ha;
}
inline int C(int n, int m) {
  if (n < m) return 0;
  if (n < 0 || m < 0) return 0;
  return 1ll * fac[n] * inv[m] % ha * inv[n - m] % ha;
}
namespace Subtask2 {
long long B[MAXN];
int f[666], ans[233];
std::vector<long long> v;
inline void dfs(int step, long long now) {
  if (step == m - sz) {
    f[__builtin_popcount(now)]++;
    return;
  }
  dfs(step + 1, now);
  dfs(step + 1, now ^ v[step]);
}
inline void Solve() {
  for (int i = 0; i <= m - 1; ++i) {
    for (int j = 0; j <= m - 1; ++j) {
      B[j] |= ((b[i] >> j) & 1) << i;
    }
  }
  for (int i = 0; i <= m - 1; ++i) {
    B[i] ^= (1ll << i);
    if ((B[i] >> i) & 1) v.push_back(B[i]);
  }
  dfs(0, 0);
  for (int c = 0; c <= m; ++c) {
    for (int d = 0; d <= m; ++d) {
      int sm = 0;
      for (int i = 0; i <= d; ++i) {
        int gx = 1ll * C(d, i) * C(m - d, c - i) % ha;
        if (i & 1) gx = ha - gx;
        add(sm, gx);
      }
      sm = 1ll * sm * f[d] % ha;
      add(ans[c], sm);
    }
    ans[c] = 1ll * ans[c] * qpow(inv2, m - sz) % ha;
    ans[c] = 1ll * ans[c] * qpow(2, n - sz) % ha;
    printf("%d ", ans[c]);
  }
  puts("");
  exit(0);
}
}  // namespace Subtask2
int main() {
  prework();
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i) {
    long long x;
    scanf("%lld", &x);
    insert(x);
  }
  for (int i = m - 1; i >= 0; --i) {
    if (b[i]) {
      for (int j = i + 1; j <= m - 1; ++j) {
        if ((b[j] >> i) & 1) b[j] ^= b[i];
      }
    }
  }
  for (int i = 0; i <= m - 1; ++i)
    if (b[i]) ++sz;
  if (sz <= 26)
    Subtask1::Solve();
  else
    Subtask2::Solve();
  return 0;
}
