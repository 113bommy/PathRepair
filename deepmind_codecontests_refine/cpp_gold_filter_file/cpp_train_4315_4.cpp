#include <bits/stdc++.h>
using namespace std;
namespace FGF {
const int N = 5e5 + 5;
struct edg {
  int to, nxt;
} e[N];
int cnt = 1, l[N], r[N], c[N], n, tot, tp, st[N], vis[N], col[N], head[N],
    du[N];
void add(int u, int v) {
  cnt++;
  e[cnt].to = v;
  e[cnt].nxt = head[u];
  head[u] = cnt;
  du[u]++;
}
void dfs(int u) {
  vis[u] = 1;
  for (int &i = head[u]; i; i = e[i].nxt) {
    if (col[i >> 1]) continue;
    col[i >> 1] = (u > e[i].to) + 1;
    dfs(e[i].to);
  }
}
void work() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++)
    scanf("%d%d", &l[i], &r[i]), r[i]++, c[++tot] = l[i], c[++tot] = r[i];
  sort(c + 1, c + tot + 1);
  tot = unique(c + 1, c + tot + 1) - c - 1;
  for (int i = 1; i <= n; i++) {
    l[i] = lower_bound(c + 1, c + tot + 1, l[i]) - c,
    r[i] = lower_bound(c + 1, c + tot + 1, r[i]) - c;
    add(l[i], r[i]), add(r[i], l[i]);
  }
  for (int i = 1; i <= tot; i++)
    if (du[i] & 1) st[++tp] = i;
  for (int i = 1; i <= tp; i += 2) add(st[i], st[i + 1]), add(st[i + 1], st[i]);
  for (int i = 1; i <= tot; i++)
    if (!vis[i]) dfs(i);
  for (int i = 1; i <= n; i++) printf("%d ", col[i] - 1);
}
}  // namespace FGF
int main() {
  FGF::work();
  return 0;
}
