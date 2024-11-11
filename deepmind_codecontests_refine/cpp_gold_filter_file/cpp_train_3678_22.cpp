#include <bits/stdc++.h>
const long long M = 2e5 + 5;
const long long INF = 0x3f3f3f3f;
long long n, m, k, mod, ans, tot, s[M], vis[M], siz[M];
std ::vector<long long> P[M];
inline long long ksm(long long n, long long k = mod - 2) {
  long long s = 1, bas = n;
  while (k) {
    if (k & 1) s = s * bas % mod;
    bas *= bas, bas %= mod;
    k >>= 1;
  }
  return s;
}
inline long long read() {
  long long f = 1, s = 0;
  char ch = getchar();
  while (!isdigit(ch)) (ch == '-') && (f = -1), ch = getchar();
  while (isdigit(ch)) s = (s << 1) + (s << 3) + (ch ^ 48), ch = getchar();
  return f * s;
}
inline void print(long long x) {
  if (x < 0) putchar('-'), x = -x;
  if (x > 9) print(x / 10);
  putchar(x % 10 + '0');
}
inline long long dfs(long long x, long long fa) {
  vis[x] = 1, siz[x] = 1;
  for (long long i = 0; i < P[x].size(); ++i) {
    long long y = P[x][i];
    if (y == fa || vis[y]) continue;
    dfs(y, x);
    siz[x] += siz[y];
  }
  return siz[x];
}
signed main() {
  n = read(), m = read(), mod = read();
  for (long long i = 1; i <= m; ++i) {
    long long u = read(), v = read();
    P[u].push_back(v), P[v].push_back(u);
  }
  for (long long i = 1; i <= n; ++i)
    if (!vis[i]) {
      ++tot;
      s[tot] = dfs(i, i);
    }
  if (tot == 1) {
    std ::cout << 1 % mod;
    return 0;
  }
  ans = ksm(n, tot - 2);
  for (long long i = 1; i <= tot; ++i) ans = ans * s[i] % mod;
  std ::cout << ans;
  return 0;
}
