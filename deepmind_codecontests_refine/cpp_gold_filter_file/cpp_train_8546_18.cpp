#include <bits/stdc++.h>
const int N = 15e3 + 7, inf = 1 << 29;
using namespace std;
int n, p[N], ti, cp[N], vis[N], cnt, head[N], S, T, cur[N];
vector<int> md[N];
long long ans;
struct edge {
  int nxt, to, val;
} E[1000006];
bool dfs(int x) {
  if (vis[x] == ti) return false;
  vis[x] = ti;
  for (int i = 0, m = md[x].size(); i < m; ++i) {
    int v = md[x][i];
    if (vis[v] == ti) continue;
    if (!cp[v] || dfs(cp[v])) {
      cp[v] = x;
      return true;
    }
  }
  return false;
}
void add(int u, int v, int val) {
  E[++cnt] = (edge){head[u], v, val};
  head[u] = cnt;
  E[++cnt] = (edge){head[v], u, 0};
  head[v] = cnt;
}
int dis[N];
queue<int> Q;
bool bfs() {
  for (int i = S; i <= T; ++i) dis[i] = -1;
  dis[S] = 0;
  Q.push(S);
  while (!Q.empty()) {
    int u = Q.front();
    Q.pop();
    for (int i = head[u]; i; i = E[i].nxt) {
      int v = E[i].to;
      if (dis[v] < 0 && E[i].val > 0) {
        dis[v] = dis[u] + 1;
        Q.push(v);
      }
    }
  }
  return dis[T] > 0;
}
int dfs(int u, int f) {
  if (u == T) return f;
  int cost, ret = 0;
  for (int i = cur[u]; i; i = E[i].nxt) {
    int v = E[i].to;
    if (dis[v] != dis[u] + 1) continue;
    cost = dfs(v, min(E[i].val, f - ret));
    E[i].val -= cost, ret += cost, E[i ^ 1].val += cost;
    if (E[i].val) cur[u] = i;
    if (ret == f) return f;
  }
  if (!ret) dis[u] = -1;
  return ret;
}
void Init() {
  scanf("%d", &n);
  S = 0, T = n + 1;
  cnt = 1;
  for (int i = 1, m, ai; i <= n; ++i) {
    scanf("%d", &m);
    while (m--) {
      scanf("%d", &ai);
      md[i].push_back(ai + n);
    }
  }
  for (int i = 1; i <= n; ++i) ++ti, dfs(i);
  for (int i = 1; i <= n; ++i) scanf("%d", p + i);
  for (int i = 1; i <= n; ++i)
    for (int j = 0, m = md[i].size(); j < m; ++j) add(i, cp[md[i][j]], inf);
  for (int i = 1; i <= n; ++i) {
    p[i] = -p[i];
    if (p[i] > 0)
      add(S, i, p[i]), ans += p[i];
    else
      add(i, T, -p[i]);
  }
}
void Solve() {
  while (bfs()) {
    for (int i = S; i <= T; ++i) cur[i] = head[i];
    ans -= dfs(S, inf);
  }
  printf("%I64d\n", -ans);
}
int main() {
  Init();
  Solve();
  return 0;
}
