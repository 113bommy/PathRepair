#include <bits/stdc++.h>
using namespace std;
long long mod = 1e9 + 7;
int n, m, k;
long long b[500005];
long long ans;
map<long long, int> a;
map<long long, int> g[500005];
long long fast(long long x, int v) {
  long long an = 1;
  while (v) {
    if (v % 2) an = (an * x) % mod;
    x = (x * x) % mod;
    v /= 2;
  }
  return an;
}
int findfa(int x, long long key) {
  if (g[x][key] == x) return x;
  return g[x][key] = findfa(g[x][key], key);
}
int main() {
  scanf("%d%d%d", &n, &m, &k);
  ans = (fast(2, k) * fast(2, n)) % mod;
  for (int i = 1; i <= n; i++) scanf("%lld", &b[i]);
  for (int i = 1; i <= m; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    long long key = b[x] ^ b[y];
    if (g[x][key] == 0) g[x][key] = x;
    if (g[y][key] == 0) g[y][key] = y;
    if (findfa(x, key) == findfa(y, key))
      continue;
    else
      g[findfa(x, key)][key] = g[findfa(y, key)][key];
    a[key]++;
    ans = (ans - fast(2, n - a[key]) + mod) % mod;
  }
  printf("%lld", ans % mod);
  return 0;
}
