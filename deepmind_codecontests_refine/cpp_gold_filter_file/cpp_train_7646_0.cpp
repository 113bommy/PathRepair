#include <bits/stdc++.h>
const int N = 2005;
const int M = N * N;
int n, m, dfn[N], low[N], sz[N], l[M], r[M], tot, size[N], head[N], bel[N],
    stack[N], top, idx, bcc, vis[N];
struct edge {
  int to, nxt;
} e[M << 1];
void addedge(int x, int y) {
  e[++tot] = (edge){y, head[x]};
  head[x] = tot;
  e[++tot] = (edge){x, head[y]};
  head[y] = tot;
}
void tarjan(int x, int f) {
  dfn[x] = low[x] = ++idx;
  stack[++top] = x;
  for (int i = head[x]; i; i = e[i].nxt)
    if (e[i].to != f)
      if (!dfn[e[i].to])
        tarjan(e[i].to, x), low[x] = std::min(low[x], low[e[i].to]);
      else
        low[x] = std::min(low[x], dfn[e[i].to]);
  if (low[x] == dfn[x]) {
    int v;
    ++bcc;
    do v = stack[top--], bel[v] = bcc, sz[bcc]++;
    while (x != v);
  }
}
std::bitset<N / 2> backpack;
int ans = 0;
int dfs(int x, int f = 0) {
  size[x] = sz[x];
  for (int i = head[x]; i; i = e[i].nxt)
    if (e[i].to != f) size[x] += dfs(e[i].to, x);
  ans += size[x] * sz[x];
  return size[x];
}
int solve1(int x, int sztot) {
  backpack.reset();
  backpack.set(0);
  ans = 0;
  dfs(x);
  for (int i = head[x]; i; i = e[i].nxt) backpack |= backpack << size[e[i].to];
  for (int i = sztot - sz[x] >> 1; i; i--)
    if (backpack[i]) {
      ans += i * (sztot - sz[x] - i);
      break;
    }
  return ans;
}
int sumans = 0;
void solve0(int x) {
  static int q[N];
  int h = 1, t = 1;
  int ans = 0, sztot = 0;
  vis[q[1] = x] = 1;
  while (h <= t) {
    int tmp = q[h++];
    sztot += sz[tmp];
    for (int i = head[tmp]; i; i = e[i].nxt)
      if (!vis[e[i].to]) vis[q[++t] = e[i].to] = 1;
  }
  for (int i = 1; i <= t; i++) ans = std::max(ans, solve1(q[i], sztot));
  sumans += ans;
}
int main() {
  std::scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; i++)
    std::scanf("%d%d", &l[i], &r[i]), addedge(l[i], r[i]);
  for (int i = 1; i <= n; i++)
    if (!dfn[i]) tarjan(i, 0);
  tot = 0;
  for (int i = 1; i <= n; i++) head[i] = 0;
  for (int i = 1; i <= m; i++)
    if (bel[l[i]] != bel[r[i]]) addedge(bel[l[i]], bel[r[i]]);
  for (int i = 1; i <= bcc; i++)
    if (!vis[i]) solve0(i);
  std::printf("%d\n", sumans);
}
