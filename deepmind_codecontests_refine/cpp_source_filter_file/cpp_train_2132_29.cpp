#include <bits/stdc++.h>
using namespace std;
struct node {
  int v, flow, next;
} edge[100005];
int n, Prime[10005], num[205], Head[205], d[205], e, desk[205][205], vis[205],
    link[205][205];
queue<int> qu;
void add(int u, int v, int f) {
  edge[e].v = v;
  edge[e].flow = f;
  edge[e].next = Head[u];
  Head[u] = e;
  e++;
}
void init() {
  int i, j, k;
  e = 0;
  memset(Head, -1, sizeof(Head));
  for (i = 1; i <= n; i++)
    if (num[i] & 1) {
      add(0, i, 2);
      add(i, 0, 2);
    } else {
      add(i, n + 1, 2);
      add(n + 1, i, 0);
    }
  for (i = 1; i <= n; i++)
    for (j = i + 1; j <= n; j++)
      if (Prime[num[i] + num[j]] == 0) {
        if (num[i] & 1) {
          add(i, j, 1);
          add(j, i, 0);
        } else {
          add(j, i, 1);
          add(i, j, 0);
        }
      }
}
int bfs() {
  int i, j, u, v;
  memset(d, -1, sizeof(d));
  while (!qu.empty()) qu.pop();
  d[0] = 0;
  qu.push(0);
  while (!qu.empty()) {
    u = qu.front();
    qu.pop();
    for (j = Head[u]; j != -1; j = edge[j].next)
      if (edge[j].flow > 0 && d[edge[j].v] == -1) {
        d[edge[j].v] = d[u] + 1;
        if (edge[j].v == n + 1) return 1;
        qu.push(edge[j].v);
      }
  }
  return 0;
}
int dfs(int u, int f) {
  if (u == n + 1 || f == 0) return f;
  int ans = 0, v, i, j, k;
  for (j = Head[u]; j != -1; j = edge[j].next)
    if (edge[j].flow > 0 && d[edge[j].v] == d[u] + 1) {
      k = dfs(edge[j].v, min(edge[j].flow, f));
      edge[j].flow -= k;
      edge[j ^ 1].flow += k;
      ans += k;
      f -= k;
      if (f == 0) break;
    }
  d[u] = -1;
  return ans;
}
int dinic() {
  int ans = 0;
  while (bfs()) ans += dfs(0, 1e9);
  return ans;
}
void dfs2(int p, int u) {
  int i, j, k;
  for (i = 1; i <= n; i++)
    if (vis[i] == 0 && link[u][i] == 1) {
      vis[i] = 1;
      desk[p][0]++;
      desk[p][desk[p][0]] = i;
      dfs2(p, i);
    }
}
int main() {
  int i, j, k, ans, p;
  for (i = 2; i <= 200; i++)
    if (Prime[i] == 0)
      for (j = i * 2; j <= 20000; j += i) Prime[j] = 1;
  cin >> n;
  for (i = 1; i <= n; i++) cin >> num[i];
  init();
  ans = dinic();
  if (ans != n)
    cout << "Impossible" << endl;
  else {
    for (i = 1; i <= n; i++)
      if (num[i] & 1)
        for (j = Head[i]; j != -1; j = edge[j].next)
          if (edge[j].flow == 0) {
            link[i][edge[j].v] = 1;
            link[edge[j].v][i] = 1;
          }
    p = 0;
    for (i = 1; i <= n; i++)
      if (vis[i] == 0) {
        vis[i] = 1;
        p++;
        desk[p][0] = 1;
        desk[p][1] = i;
        dfs2(p, i);
      }
    cout << p << endl;
    for (i = 1; i <= p; i++) {
      cout << desk[i][0];
      for (j = 1; j <= desk[i][0]; j++) cout << " " << desk[i][j];
      cout << endl;
    }
  }
}
