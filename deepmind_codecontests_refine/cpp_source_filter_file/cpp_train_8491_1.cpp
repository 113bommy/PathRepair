#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 3;
int i, u, v, n, a[N], b[N], c[N], x[N], g[N], pos[N];
int t, en[N], nxt[N], fa[N], f[N], siz[N];
void dfs(int u) {
  pos[u] = ++t, siz[u] = 1;
  for (int i = fa[u], v; i; i = nxt[i])
    if ((v = en[i]) != f[u]) f[v] = u, dfs(v), siz[u] += siz[v];
}
int main() {
  scanf("%d", &n);
  for (i = 1; i < n; ++i) {
    scanf("%d%d", a + i, b + i);
    en[++t] = b[i], nxt[t] = fa[a[i]], fa[a[i]] = t;
    en[++t] = a[i], nxt[t] = fa[b[i]], fa[b[i]] = t;
  }
  for (i = 1; i <= n; ++i) scanf("%d", c + i);
  t = 0, dfs(1);
  for (i = 1; i <= n; ++i) x[pos[i]] = c[i];
  for (i = 1; i <= n; ++i)
    if (x[i] == x[i - 1])
      g[i] = g[i - 1];
    else
      g[i] = i;
  for (u = 1; u <= n; ++u) {
    for (i = fa[u]; i; i = nxt[i]) {
      v = en[i];
      if (f[u] == v) {
        if (g[pos[v]] > 1) break;
        if (g[n] > pos[u] + siz[u]) break;
        if (pos[u] + siz[u] <= n && x[1] != x[n]) break;
      } else if (g[pos[v] + siz[v] - 1] > pos[v])
        break;
    }
    if (!i) return printf("YES\n%d", u), 0;
  }
  puts("NO");
}
