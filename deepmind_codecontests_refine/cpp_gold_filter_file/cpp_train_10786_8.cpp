#include <bits/stdc++.h>
using namespace std;
const int N = 100000 + 10;
const int mod = 1e9 + 7;
vector<int> g[N];
int n;
long long d[N], f[N];
bool ye[N];
void dfs1(int u, int fa) {
  int sz = g[u].size();
  d[u] = 1;
  for (int i = 0; i <= sz - 1; ++i)
    if (g[u][i] != fa) {
      int v = g[u][i];
      dfs1(v, u);
      d[u] = d[u] * d[v] % mod;
    }
  if (sz != 1 || u == 1)
    d[u] = d[u] * 2 % mod;
  else
    ye[u] = 1;
}
void dfs2(int u, int fa) {
  int sz = g[u].size();
  long long sum = 1;
  for (int i = 0; i <= sz - 1; ++i)
    if (g[u][i] != fa) {
      int v = g[u][i];
      f[v] = f[u] * sum % mod;
      sum = sum * d[v] % mod;
    }
  sum = 1;
  for (int i = sz - 1; i >= 0; --i)
    if (g[u][i] != fa) {
      int v = g[u][i];
      f[v] = f[v] * sum % mod;
      if (sz != 1) f[v] = f[v] * 2 % mod;
      sum = sum * d[v] % mod;
      dfs2(v, u);
    }
}
int main() {
  scanf("%d", &n);
  if (n == 1) {
    puts("1");
    return 0;
  }
  for (int i = 1; i <= n - 1; ++i) {
    int u, v;
    scanf("%d%d", &u, &v);
    g[u].push_back(v);
    g[v].push_back(u);
  }
  dfs1(1, -1);
  f[1] = 1;
  dfs2(1, -1);
  long long ans = 0;
  for (int i = 1; i <= n; ++i) {
    long long cur = d[i] * f[i] % mod;
    if (ye[i]) cur = cur * 2 % mod;
    ans = (ans + cur) % mod;
  }
  printf("%I64d\n", ans);
  return 0;
}
