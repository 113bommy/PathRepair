#include <bits/stdc++.h>
inline int read() {
  int data = 0, w = 1;
  char ch = getchar();
  while (ch != '-' && (ch < '0' || ch > '9')) ch = getchar();
  if (ch == '-') w = -1, ch = getchar();
  while (ch >= '0' && ch <= '9') data = data * 10 + (ch ^ 48), ch = getchar();
  return data * w;
}
const int maxn(2e5 + 10), Mod(998244353);
std::vector<int> G[maxn];
int deg[maxn], n, fac[maxn], f[maxn];
inline void add_edge(int from, int to) { G[from].push_back(to), ++deg[from]; }
void dfs(int x, int fa) {
  f[x] = fac[deg[x]];
  for (auto i : G[x])
    if (i != fa) dfs(i, x), f[x] = 1ll * f[x] * f[i] % Mod;
}
int main() {
  n = read(), fac[0] = 1;
  for (int i = 1; i <= n; i++) fac[i] = 1ll * fac[i - 1] * i % Mod;
  for (int i = 1, a, b; i < n; i++)
    a = read(), b = read(), add_edge(a, b), add_edge(b, a);
  dfs(1, 0);
  printf("%d\n", 1ll * f[1] * n % Mod);
  return 0;
}
