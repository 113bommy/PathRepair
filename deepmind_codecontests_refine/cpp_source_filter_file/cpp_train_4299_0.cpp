#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 10;
const long long mod = 998244353;
const long long Inf = 1e18;
int inv[1 << 20], cnt, f[N], val[N], mini, id[N];
vector<int> g[N];
bool vis[N];
void dfs(int u) {
  vis[u] = 1;
  for (auto v : g[u]) {
    if (!vis[v]) dfs(v);
    val[u] += val[v] * f[v];
  }
  if (cnt < mini) {
    val[u] = 1 << cnt;
    f[u] = 1;
  }
  id[cnt] = u;
  ++cnt;
}
void add(int u, int v, int c) {
  if (c)
    printf("+ %d %d\n", u, v);
  else
    printf("- %d %d\n", u, v);
}
void check(int u, int i) {
  if (val[u] & (1 << i))
    printf("- %d %d\n", u, id[i]);
  else
    printf("+ %d %d\n", u, id[i]);
}
int main() {
  int n, m, T;
  scanf("%d%d%d", &n, &m, &T);
  while (m--) {
    int u, v;
    scanf("%d%d", &u, &v);
    g[u].push_back(v);
  }
  mini = min(n, 20);
  for (int i = (1); i < (n + 1); ++i) {
    if (!vis[i]) dfs(i);
  }
  printf("%d\n", (mini - 1) * mini / 2 + 4 * (n - mini));
  for (int i = (0); i < (n); ++i) {
    if (i < mini) {
      for (int j = (0); j < (i); ++j) add(id[i], id[j], 1);
    } else {
      add(id[i], id[i], 1);
      int u = id[i];
      int ok = 0;
      for (int j = (0); j < (mini); ++j) {
        for (int k = (j + 1); k < (mini); ++k) {
          for (int l = (k + 1); l < (mini); ++l) {
            int mask = val[u] ^ (1 << j) ^ (1 << k) ^ (1 << l);
            if (!ok && !inv[mask]) {
              ok = 1;
              inv[mask] = u;
              check(u, j);
              check(u, k);
              check(u, l);
            }
          }
        }
      }
    }
  }
  char s[10];
  while (T--) {
    int ans = 0, ok = 0;
    for (int i = (0); i < (mini); ++i) {
      printf("? 1 %d\n", id[i]);
      fflush(stdout);
      scanf("%s", s);
      if (s[0] == 'W') ans = 1 << i;
      if (s[0] == 'L') ok = id[i];
    }
    ans = inv[ans];
    if (ok) ans = ok;
    printf("! %d\n", ans);
    fflush(stdout);
    scanf("%s", s);
  }
}
