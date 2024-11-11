#include <bits/stdc++.h>
int ans, cnt[100005], head[100005], s[100005], mark, to[600005], next[600005],
    d[100005], tail, id[100005];
bool ins[100005], dfn[100005];
void dfs(int u, int f) {
  if (dfn[u]) {
    if (ins[u]) {
      mark++;
      while (s[tail] != u) id[s[tail]] = mark, ins[s[tail--]] = false;
      id[u] = mark;
      ins[u] = false;
      tail--;
    }
    return;
  }
  dfn[u] = true;
  s[++tail] = u;
  ins[u] = true;
  for (int i = head[u]; i; i = next[i])
    if (to[i] != f) dfs(to[i], u);
  if (!id[u]) ins[u] = false, tail--;
}
int main() {
  int n, m, i, u, v;
  scanf("%d%d", &n, &m);
  for (i = 1; i <= m; i++) {
    scanf("%d%d", &u, &v);
    to[i] = v;
    next[i] = head[u];
    head[u] = i;
    to[i + m] = u;
    next[i + m] = head[v];
    head[v] = i + m;
    d[u]++;
    d[v]++;
  }
  for (u = 1; u <= n; u++)
    if (d[u] % 2) ans++;
  ans /= 2;
  for (u = 1; u <= n; u++)
    if (!dfn[u]) dfs(u, -1);
  for (u = 1; u <= n; u++)
    if (id[u] && d[u] > 2) cnt[id[u]]++;
  for (i = 1; i <= mark; i++)
    if (cnt[i] < 2) ans++;
  printf("%d %d\n", ans, m);
}
