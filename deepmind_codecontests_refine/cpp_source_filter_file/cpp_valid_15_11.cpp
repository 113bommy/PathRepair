#include <bits/stdc++.h>
using namespace std;
template <typename _T>
inline void read(_T &x) {
  x = 0;
  char s = getchar();
  long long f = 1;
  while (s < '0' || s > '9') {
    f = 1;
    if (s == '-') f = -1;
    s = getchar();
  }
  while ('0' <= s && s <= '9') {
    x = (x << 3) + (x << 1) + s - '0';
    s = getchar();
  }
  x *= f;
}
const long long np = 105;
const long long mod = 1e9 + 7;
long long fac[np], inv[np];
inline long long power(long long a, long long b) {
  long long res(1);
  while (b) {
    if (b & 1) res = res * a, res %= mod;
    a = a * a;
    a %= mod;
    b >>= 1;
  }
  return res;
}
inline long long c(long long n_, long long m_) {
  return ((fac[n_] * inv[n_ - m_] % mod) * inv[m_]) % mod;
}
long long head[np], nxt[np * 2], ver[np * 2], tit;
inline void add(long long x, long long y) {
  ver[++tit] = y;
  nxt[tit] = head[x];
  head[x] = tit;
}
long long dep[np], maxn;
long long sub[np][np];
long long dp[np][np];
long long n, k;
inline void dfs(long long x, long long ff, long long id) {
  dep[x] = dep[ff] + 1;
  maxn = max(dep[x], maxn);
  sub[id][dep[x]]++;
  for (long long i = head[x], v; i; i = nxt[i]) {
    v = ver[i];
    if (v == ff) continue;
    dfs(v, x, id);
  }
}
signed main() {
  fac[0] = 1;
  for (long long i = 1; i <= 100; i++) fac[i] = fac[i - 1] * i, fac[i] %= mod;
  for (long long i = 0; i <= 100; i++) inv[i] = power(fac[i], mod - 2);
  long long T;
  read(T);
  while (T--) {
    read(n);
    read(k);
    for (long long i = 1, a, b; i < n; i++) {
      read(a);
      read(b);
      add(a, b);
      add(b, a);
    }
    if (k == 2) {
      long long ans = c(n, 2);
      printf("%lld\n", ans);
      memset(head, 0, sizeof(head));
      tit = 0;
      continue;
    }
    long long Ans = 0;
    for (long long i = 1; i <= n; i++) {
      dep[i] = 1;
      long long ql = 0;
      maxn = 0;
      for (long long q = head[i]; q; q = nxt[q]) dfs(ver[q], i, ++ql);
      if (ql >= k) {
        for (long long h = 2; h <= maxn; h++) {
          dp[0][0] = 1;
          for (long long a = 1; a <= ql; a++)
            for (long long b = 1; b <= k; b++)
              dp[a][b] =
                  (dp[a - 1][b] + (dp[a - 1][b - 1] * sub[a][h]) % mod) % mod;
          Ans += dp[ql][k];
          Ans %= mod;
        }
      }
      memset(sub, 0, sizeof(sub));
      memset(dp, 0, sizeof(dp));
      memset(dep, 0, sizeof(dep));
    }
    printf("%lld\n", Ans);
    for (long long i = 1; i <= n; i++) head[i] = 0;
    tit = 0;
  }
}
