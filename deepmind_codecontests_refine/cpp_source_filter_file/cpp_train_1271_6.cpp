#include <bits/stdc++.h>
const long long maxn = 3e3 + 9, mod = 998244353, inf = 1e18;
long long Read() {
  long long x(0), f(1);
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = (x << 3ll) + (x << 1ll) + c - '0';
    c = getchar();
  }
  return x * f;
}
void Chkmin(long long &x, long long y) {
  if (y < x) x = y;
}
void Chkmax(long long &x, long long y) {
  if (y > x) x = y;
}
long long add(long long x, long long y) {
  return x += y, x >= mod ? x - mod : x;
}
long long dec(long long x, long long y) { return x -= y, x < 0 ? x + mod : x; }
long long mul(long long x, long long y) { return 1ll * x * y % mod; }
long long Pow(long long base, long long b) {
  long long ret(1);
  while (b) {
    if (b & 1) ret = mul(ret, base);
    base = mul(base, base);
    b >>= 1;
  }
  return ret;
}
long long n, m;
long long a[maxn], size[maxn];
std::pair<long long, long long> dp[maxn][maxn];
std::vector<long long> V[maxn];
void Init() {
  n = Read();
  m = Read();
  for (long long i = 1; i <= n; ++i) a[i] = -Read();
  for (long long i = 1; i <= n; ++i) a[i] += Read();
  for (long long i = 1; i < n; ++i) {
    long long x(Read()), y(Read());
    V[x].push_back(y);
    V[y].push_back(x);
  }
}
std::pair<long long, long long> operator+(
    const std::pair<long long, long long> A,
    const std::pair<long long, long long> B) {
  return std::pair<long long, long long>(A.first + B.first,
                                         A.second + B.second);
}
void Dfs(long long u, long long f) {
  size[u] = 1;
  dp[u][0] = std::pair<long long, long long>(0, a[u]);
  for (long long i = 0; i < V[u].size(); ++i) {
    long long v(V[u][i]);
    if (v == f) continue;
    Dfs(v, u);
    std::pair<long long, long long> g[maxn];
    for (long long j = 0; j < size[u] + size[v]; ++j)
      g[u] = std::pair<long long, long long>(0, -inf);
    for (long long j = 0; j < size[u]; ++j) {
      for (long long k = 0; k < size[v]; ++k) {
        g[j + k] = std::max(g[j + k], dp[u][j] + dp[v][k]);
        g[j + k + 1] =
            std::max(g[j + k + 1],
                     dp[u][j] + std::pair<long long, long long>(
                                    dp[v][k].first + (dp[v][k].second > 0), 0));
      }
    }
    size[u] += size[v];
    for (long long k = 0; k < size[u]; ++k) dp[u][k] = g[k];
  }
}
void Solve() {
  Dfs(1, 0);
  long long ret(dp[1][m - 1].first + (dp[1][m - 1].second > 0));
  printf("%lld\n", ret);
}
void Clear() {
  for (long long i = 1; i <= n; ++i) std::vector<long long>().swap(V[i]);
}
int main() {
  long long T = Read();
  while (T--) {
    Init();
    Solve();
    Clear();
  }
  return 0;
}
