#include <bits/stdc++.h>
using namespace std;
const int N = 1000010;
int n, m, tot, te;
int val[N], head[N], vis[N];
struct edge {
  int u, v, next;
} e[2000010];
int cnt;
inline void add(int u, int v) {
  e[++te].u = u;
  e[te].v = v;
  e[te].next = head[u];
  head[u] = te;
}
inline void dfs(int x) {
  vis[x] = 1;
  for (int i = head[x]; i; i = e[i].next) {
    int v = e[i].v;
    if (!vis[v]) dfs(v);
  }
}
int main() {
  memset(val, 0, sizeof(val));
  long long ans = 0;
  tot = 0;
  int u, v;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; ++i) {
    scanf("%d%d", &u, &v);
    if (u == v)
      tot++;
    else
      val[u]++, ++val[v], add(u, v), add(v, u);
  }
  for (int i = 1; i <= n; ++i) {
    if (!vis[i] && head[i] != 0) dfs(i), cnt++;
  }
  if (cnt > 1) {
    cout << '0';
    return 0;
  }
  for (int i = 1; i <= n; ++i) {
    if (val[i] >= 2) ans += (long long)val[i] * (val[i] - 1) / 2;
  }
  if (tot >= 2) ans += (long long)tot * (tot - 1) / 2;
  ans += (long long)tot * (m - tot);
  printf("%I64d", ans);
}
