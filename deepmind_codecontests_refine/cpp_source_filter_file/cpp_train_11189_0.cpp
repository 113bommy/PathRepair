#include <bits/stdc++.h>
const int N = 100005, W = 18;
int to[N << 1], last[N], Next[N << 1], w[N << 1], edge, n, q, x, y, z, ans, s;
int f[N][20], d[N][20], dis[N], son[N], cnt, sum[N], a[N], tp[N];
void add(int x, int y, int z) {
  to[++edge] = y;
  Next[edge] = last[x];
  last[x] = edge;
  w[edge] = z;
}
struct note {
  int x, tp;
};
inline bool operator<(note x, note y) { return x.x < y.x; }
std::priority_queue<note> Q;
void dfs2(int x, int fa, int dis) {
  if (dis > ans) s = x, ans = dis;
  for (int i = last[x]; i; i = Next[i])
    if (to[i] != fa) dfs2(to[i], x, dis + w[i]);
}
void dfs(int x, int fa) {
  f[x][0] = fa;
  for (int i = last[x]; i; i = Next[i]) {
    int u = to[i];
    if (u == fa) continue;
    dfs(u, x);
    d[u][0] = w[i];
    if (dis[u] + w[i] > dis[x]) son[x] = u, dis[x] = dis[u] + w[i];
  }
}
int main() {
  scanf("%d%d", &n, &q);
  for (int i = 1; i < n; i++) {
    scanf("%d%d%d", &x, &y, &z);
    add(x, y, z), add(y, x, z);
  }
  ans = 0;
  dfs2(1, 0, 0);
  dfs(s, 0);
  Q.push({dis[s], s});
  while (!Q.empty()) {
    note t = Q.top();
    Q.pop();
    cnt++;
    for (int i = t.tp; i; i = son[i]) {
      a[i] = cnt;
      for (int j = last[i]; j; j = Next[j])
        if (to[j] != son[i] && to[j] != f[i][0])
          Q.push({dis[to[j]] + w[j], to[j]});
      tp[i] = t.tp;
    }
    sum[cnt] = sum[cnt - 1] + t.x;
  }
  for (int i = 1; i <= W; i++)
    for (int j = 1; j <= n; j++) {
      f[j][i] = f[f[j][i - 1]][i - 1];
      if (f[j][i]) d[j][i] = d[j][i - 1] + d[f[j][i - 1]][i - 1];
    }
  ans = 0;
  while (q--) {
    scanf("%d%d", &x, &y);
    x = (x + ans - 1) % n + 1, y = (y + ans - 1) % n + 1;
    y = y * 2 - 1;
    ans = 0;
    if (y >= cnt)
      ans = sum[cnt];
    else if (a[x] <= y)
      ans = sum[y];
    else {
      int t = x;
      ans = dis[x];
      for (int i = W; i >= 0; i--)
        if (a[f[t][i]] > y) ans = ans + d[t][i], t = f[t][i];
      int fa = f[t][0], tt = t;
      for (int i = W; i >= 0; i--)
        if (a[tt] > 1) tt = f[tt][i];
      tt = f[tt][0];
      ans =
          std::max(ans + sum[y] - std::min(dis[fa], dis[s] - dis[tt]) + d[t][0],
                   ans + d[t][0] + sum[y - 1]);
    }
    printf("%d\n", ans);
  }
}
