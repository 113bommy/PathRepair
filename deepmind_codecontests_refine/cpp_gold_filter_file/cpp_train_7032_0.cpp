#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-6;
const int INF = 2e9;
const long long LNF = 9e18;
const int mod = 1e9 + 7;
const int maxn = 2e5 + 10;
int n, a[maxn];
int vis[maxn], g[maxn];
long long ans;
long long fun(long long x, long long n) {
  long long res = 1;
  while (n > 0) {
    if (n & 1) res = (res * x) % mod;
    x = (x * x) % mod;
    n >>= 1;
  }
  return res;
}
void dfs(int k, int t, int cnt) {
  vis[k] = cnt;
  g[k] = t;
  if (g[a[k]]) {
    long long tmp = fun(2, cnt - vis[a[k]] + 1);
    if (g[a[k]] == t)
      ans *= tmp - 2, ans %= mod, ans *= fun(2, vis[a[k]] - 1), ans %= mod;
    else
      ans *= fun(2, cnt), ans %= mod;
  } else
    dfs(a[k], t, cnt + 1);
}
void init() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  memset((vis), (0), sizeof(vis));
  memset((g), (0), sizeof(g));
  ans = 1;
  for (int i = 1; i <= n; i++)
    if (!vis[i]) dfs(i, i, 1);
  printf("%lld\n", ans);
}
void solve() {}
int main() {
  {
    init();
    solve();
  }
}
