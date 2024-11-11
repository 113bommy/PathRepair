#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
long long powmod(long long a, long long b) {
  long long res = 1;
  a %= mod;
  assert(b >= 0);
  for (; b; b >>= 1) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
  }
  return res;
}
const int N = 201000, M = 2010;
int n, m, k, s, e[M];
long long fac[N], fnv[N], dp[M][30], ret[30];
pair<int, int> p[M];
long long way(int x, int y) { return fac[x + y] * fnv[x] % mod * fnv[y] % mod; }
int main() {
  scanf("%d%d%d%d", &n, &m, &k, &s);
  fac[0] = fnv[0] = 1;
  for (int i = 1; i < n + m + 1; i++)
    fac[i] = fac[i - 1] * i % mod, fnv[i] = powmod(fac[i], mod - 2);
  for (int i = 0; i < k; i++) {
    scanf("%d%d", &p[i].first, &p[i].second);
  }
  p[k] = make_pair(1, 1);
  sort(p, p + k + 1);
  int c = unique(p, p + k + 1) - p;
  dp[0][0] = 1;
  if (c <= k) s = (s + 1) / 2;
  for (int v = 0; v < 24; v++) {
    e[v] = s;
    s = (s + 1) / 2;
  }
  for (int i = 1; i < c; i++) {
    for (int j = 0; j < i; j++)
      if (p[i].first >= p[j].first && p[i].second >= p[j].second) {
        for (int v = 0; v < 23; v++)
          dp[i][v + 1] =
              (dp[i][v + 1] + dp[j][v] * way(p[i].first - p[j].first,
                                             p[i].second - p[j].second)) %
              mod;
      }
    for (int v = 1; v < 23; v++) dp[i][v] = (dp[i][v] - dp[i][v + 1]) % mod;
  }
  long long r = 0;
  for (int i = 0; i < c; i++) {
    for (int v = 0; v < 24; v++)
      ret[v] = (ret[v] + dp[i][v] * way(n - p[i].first, m - p[i].second)) % mod;
  }
  for (int v = 0; v < 23; v++) ret[v] = (ret[v] - ret[v + 1]) % mod;
  for (int v = 0; v < 24; v++) r = (r + ret[v] * e[v]) % mod;
  if (r < 0) r += mod;
  r = r * powmod(way(n - 1, m - 1), mod - 2) % mod;
  printf("%lld\n", r);
}
