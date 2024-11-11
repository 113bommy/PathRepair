#include <bits/stdc++.h>
using namespace std;
const int maxn = 200000 + 10;
const int INF = 0x3f3f3f3f;
vector<int> g[maxn], rk[maxn];
int d[maxn], du[maxn], dv[maxn], p[maxn], used[maxn];
void bfs(int s, int n, int* dis) {
  queue<int> q;
  for (int i = 1; i <= n; i++) dis[i] = INF;
  dis[s] = 0;
  q.push(s);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int i = 0; i < g[u].size(); i++) {
      int to = g[u][i];
      if (dis[to] != INF) continue;
      dis[to] = dis[u] + 1;
      p[to] = u;
      q.push(to);
    }
  }
}
int main() {
  int n, a, b;
  scanf("%d", &n);
  for (int i = 0; i < n - 1; i++) {
    scanf("%d%d", &a, &b);
    g[a].push_back(b);
    g[b].push_back(a);
  }
  bfs(1, n, d);
  int u, v, temp = 0;
  for (int i = 1; i <= n; i++)
    if (d[i] > temp) {
      u = i;
      temp = d[i];
    }
  bfs(u, n, du);
  temp = 0;
  for (int i = 1; i <= n; i++)
    if (du[i] > temp) {
      v = i;
      temp = du[i];
    }
  bfs(v, n, dv);
  temp = u;
  memset(used, 0, sizeof used);
  while (temp != v) {
    used[temp] = 1;
    temp = p[temp];
  }
  used[v] = 1;
  long long ans = 0;
  for (int i = 1; i <= n; i++)
    if (!used[i]) {
      rk[dv[i]].push_back(i);
    }
  for (int i = dv[u]; i >= 1; i--) {
    for (int j = 0; j < rk[i].size(); j++)
      if (!used[rk[i][j]]) {
        int tt = rk[i][j];
        ans += max(du[tt], dv[tt]);
      }
  }
  ans += 1ll * dv[u] * (dv[u] + 1) / 2;
  printf("%I64d\n", ans);
  for (int i = dv[u]; i >= 1; i--) {
    for (int j = 0; j < rk[i].size(); j++)
      if (!used[rk[i][j]]) {
        int tt = rk[i][j];
        if (du[tt] > dv[tt])
          printf("%d %d %d\n", u, tt, tt);
        else
          printf("%d %d %d\n", v, tt, tt);
      }
  }
  temp = u;
  while (temp != v) {
    printf("%d %d %d\n", temp, v, temp);
    temp = p[temp];
  }
  return 0;
}
