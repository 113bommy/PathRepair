#include <bits/stdc++.h>
using namespace std;
const int mo = 1000000007;
long long d[100005][64], ans, c[400005], w[100005];
int g[100005], fa[100005], a[400005], b[400005], nex[400005], n, m;
vector<int> D[100005];
int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }
void dfs(int x, int y) {
  D[fa[x]].push_back(x);
  for (int i = g[x]; i; i = nex[i])
    if (b[i] != y) {
      w[b[i]] = w[x] ^ c[i];
      dfs(b[i], x);
    }
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i) fa[i] = i;
  for (int i = 1; i <= m; ++i) {
    scanf("%d%d%lld", &a[i], &b[i], &c[i]);
    if (find(a[i]) != find(b[i])) {
      a[i + m] = b[i];
      b[i + m] = a[i];
      c[i + m] = c[i];
      nex[i] = g[a[i]];
      g[a[i]] = i;
      nex[i + m] = g[b[i]];
      g[b[i]] = i + m;
      fa[find(a[i])] = find(b[i]);
    }
  }
  for (int i = 1; i <= n; ++i) find(i);
  for (int i = 1; i <= n; ++i)
    if (fa[i] == i) dfs(i, 0);
  for (int i = 1; i <= m; ++i)
    if (!a[i + m]) {
      long long x = c[i] ^ w[a[i]] ^ w[b[i]];
      int fl = 0, o = fa[a[i]];
      for (int j = 59; ~j; --j)
        if (x & (1ll << j)) {
          if (d[o][j])
            x ^= d[o][j];
          else if (!fl)
            d[o][j] = x, fl = 1;
        }
    }
  for (int o = 1; o <= n; ++o)
    if (fa[o] == o) {
      int K = 0;
      long long xx = 0;
      for (int j = 0; j < 60; ++j)
        if (d[o][j]) ++K, xx ^= d[o][j];
      for (int i = 0; i < 60; ++i) {
        int X = 0, s = D[o].size();
        for (int j = 0; j < D[o].size(); ++j)
          if (w[D[o][j]] & (1ll << i)) ++X;
        if (xx & (1ll << i))
          (ans += 1ll * s * (s - 1) / 2 % mo * ((1ll << K - 1) % mo) % mo *
                  ((1ll << i) % mo)) %= mo;
        else
          (ans += 1ll * X * (s - X) % mo * ((1ll << K) % mo) % mo *
                  ((1ll << i) % mo)) %= mo;
      }
    }
  printf("%lld\n", ans);
  return 0;
}
