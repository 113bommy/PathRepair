#include <bits/stdc++.h>
using namespace std;
int a[20005], maxflow = 0;
int n, m, g, sex[20005], v[20005], w[2005], k[2005], b[2005], c = 0;
int S, T, vis[20005], sign[20005], head[20005], len = 0, cnt = 0;
struct way {
  int num, next, cap;
} G[20005 * 6 + 5];
void link(int x, int y, int z) {
  G[++len] = (way){y, head[x], z}, head[x] = len;
}
bool bfs() {
  int i, x;
  queue<int> Q;
  vis[S] = ++cnt, sign[S] = 0;
  for (Q.push(S); !Q.empty();) {
    x = Q.front(), Q.pop();
    for (i = head[x]; i; i = G[i].next)
      if (G[i].cap && vis[G[i].num] != cnt) {
        vis[G[i].num] = cnt;
        sign[G[i].num] = sign[x] + 1;
        Q.push(G[i].num);
      }
  }
  return vis[T] == cnt;
}
int dfs(int t, int maxi) {
  int i, ans = 0, res;
  if (t == T || !maxi) return maxi;
  for (i = head[t]; i; i = G[i].next)
    if (G[i].cap && sign[G[i].num] == sign[t] + 1) {
      res = dfs(G[i].num, min(maxi, G[i].cap));
      ans += res, maxi -= res, G[i].cap -= res, G[i ^ 1].cap += res;
      if (!maxi) return ans;
    }
  sign[t] = (1 << 30);
  return ans;
}
int main() {
  int i, j, s;
  scanf("%d %d %d", &n, &m, &g);
  S = n + m + 1, T = n + m + 2;
  for (i = 1; i <= n; i++) scanf("%d", &sex[i]);
  for (i = 1; i <= n; i++) scanf("%d", &v[i]);
  for (i = 1; i <= n; i++)
    if (sex[i])
      link(i, T, v[i]), link(T, 0, i);
    else
      link(S, i, v[i]), link(i, S, 0);
  for (i = 1; i <= m; i++) {
    scanf("%d %d %d", &b[i], &w[i], &k[i]);
    for (j = 1; j <= k[i]; j++) scanf("%d", &a[j]);
    scanf("%d", &s), c += s;
    for (j = 1; j <= k[i]; j++)
      if (b[i])
        link(a[j], i + n, (1 << 30)), link(i + n, a[j], 0);
      else
        link(i + n, a[j], (1 << 30)), link(a[j], i + n, 0);
    if (b[i])
      link(i + n, T, w[i] + s * g), link(T, i + n, 0);
    else
      link(S, i + n, w[i] + s * g), link(i + n, S, 0);
    maxflow += w[i] + s * g;
  }
  while (bfs()) maxflow -= dfs(S, (1 << 30));
  printf("%d", maxflow - c * g);
  return 0;
}
