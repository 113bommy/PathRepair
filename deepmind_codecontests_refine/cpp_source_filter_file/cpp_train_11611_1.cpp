#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
int n, S, T, a[maxn], b[maxn], cir[maxn], cnt;
int fa[maxn], dep[maxn], head[maxn], to[maxn << 1], nxt[maxn << 1], tot;
bool inc[maxn], vis[maxn];
inline bool judge(int x) { return a[x] == b[x]; }
inline void add_edge(int x, int y) {
  to[++tot] = y, nxt[tot] = head[x], head[x] = tot;
}
void dfs(int x, int ff) {
  dep[x] = dep[ff] + 1, fa[x] = ff;
  for (int i = head[x]; i; i = nxt[i])
    if (to[i] != ff) dfs(to[i], x);
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    if (!a[i]) S = i;
  }
  for (int i = 1; i <= n; i++) {
    scanf("%d", &b[i]);
    if (!b[i]) T = i;
  }
  int x, y, u, v, sz, d, cov;
  bool fl;
  for (int i = 1; i < n; i++) {
    scanf("%d%d", &x, &y);
    add_edge(x, y), add_edge(y, x);
  }
  dfs(T, 0), x = S;
  while (fa[x]) swap(a[x], a[fa[x]]), vis[x] = 1, x = fa[x];
  vis[T] = 1, fl = 1;
  for (int i = 1; i <= n; i++)
    if (!judge(i)) {
      fl = 0;
      break;
    }
  if (fl) return printf("0 %d\n", dep[S] - 1), 0;
  u = v = 0;
  for (int i = 1; i <= n; i++)
    if (!judge(i) && dep[i] > dep[u]) u = i;
  for (x = u; !judge(x); x = fa[x]) inc[x] = 1, cir[cnt++] = x;
  for (int i = 1; i <= n; i++)
    if (!judge(i) && !inc[i] && dep[i] > dep[v]) v = i;
  sz = cnt;
  if (v) {
    for (y = v; !judge(y); y = fa[y]) {
      if (inc[y]) return puts("-1"), 0;
      inc[y] = 1, cir[cnt++] = y;
    }
    if (x != y) return puts("-1"), 0;
    reverse(cir + sz, cir + cnt);
  } else
    y = v = x;
  for (int i = 1; i <= n; i++)
    if (!judge(i) && !inc[i]) return puts("-1"), 0;
  for (d = 1; d < cnt; d++)
    if (a[cir[d]] == b[cir[0]]) break;
  for (int i = 0; i < cnt; i++)
    if (a[cir[(i + d) % cnt]] != b[cir[i]]) return puts("-1"), 0;
  if (u > v) swap(u, v);
  printf("%d %d ", u, v);
  for (int i = S; i; i = fa[i]) vis[i] = 1;
  cov = 0;
  for (int i = 0; i < cnt; i++) cov += vis[cir[i]];
  fl = 0;
  for (int i = 0; i < sz; i++)
    if (vis[cir[i]]) {
      fl = 1;
      break;
    }
  long long ans = dep[S] - 1;
  if (tot) {
    if (!fl) d = cnt - d;
    ans += min((long long)d * (cnt + 1),
               (long long)(cnt - d) * (cnt + 1) - 2 * cov);
  } else {
    ans += (long long)min(d, cnt - d) * (cnt + 1);
    while (!vis[x]) ans += 2, x = fa[x];
  }
  printf("%lld\n", ans);
  return 0;
}
