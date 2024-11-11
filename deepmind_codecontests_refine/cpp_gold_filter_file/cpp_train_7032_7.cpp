#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-6;
const int INF = 2e9;
const long long LNF = 9e18;
const int mod = 1e9 + 7;
const int maxn = 2e5 + 10;
int n, a[maxn];
int vis[maxn], group[maxn];
long long ans;
long long qpow(long long x, long long y) {
  long long s = 1;
  while (y) {
    if (y & 1) s = (s * x) % mod;
    x = (x * x) % mod;
    y >>= 1;
  }
  return s;
}
void dfs(int k, int id, int cnt) {
  vis[k] = cnt;
  group[k] = id;
  if (vis[a[k]]) {
    if (group[a[k]] == id) {
      ans *= qpow(2, cnt - vis[a[k]] + 1) - 2, ans %= mod;
      ans *= qpow(2, vis[a[k]] - 1), ans %= mod;
    } else
      ans *= qpow(2, cnt), ans %= mod;
  } else
    dfs(a[k], id, cnt + 1);
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  ans = 1;
  memset((vis), (0), sizeof(vis));
  memset((group), (0), sizeof(group));
  for (int i = 1; i <= n; i++)
    if (!vis[i]) dfs(i, i, 1);
  printf("%lld\n", ans);
}
