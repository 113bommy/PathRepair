#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int max_n = 1e5 + 5;
vector<int> g[max_n];
int x[max_n], n;
int f[max_n][2];
void dfs(int u, int fa) {
  f[u][x[u]] = 1;
  for (int v : g[u]) {
    if (v != fa) {
      dfs(v, u);
      int black = f[u][1], white = f[u][0];
      f[u][1] =
          ((1LL * f[v][0] * black % mod + 1LL * f[v][1] * white % mod) % mod +
           1LL * f[v][1] * black % mod) %
          mod;
      f[u][0] =
          (1LL * f[v][0] * white % mod + 1LL * f[v][1] * white % mod) % mod;
    }
  }
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n - 1; i++) {
    int p;
    scanf("%d", &p);
    g[i + 1].push_back(p);
    g[p].push_back(i + 1);
  }
  for (int i = 0; i < n; i++) scanf("%d", &x[i]);
  memset(f, 0, sizeof f);
  dfs(0, -1);
  printf("%d\n", f[0][1]);
  return 0;
}
