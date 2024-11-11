#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> vec[150000];
int vis[150000];
int head[300000];
int cnt = 0;
int Min = 1000000;
int deep;
struct Edge {
  int next;
  int to;
  int w;
} edge[300000];
void add(int u, int v, int w) {
  Min = min(Min, u);
  edge[cnt].w = w;
  edge[cnt].to = v;
  edge[cnt].next = head[u];
  head[u] = cnt++;
}
bool dfs(int pre, int x) {
  int mark = 0;
  for (int i = 0; i < vec[x].size(); i++) {
    if (vec[x][i] != pre && dfs(x, vec[x][i])) {
      add(x, vec[x][i], 1);
      add(vec[x][i], x, 1);
      mark = 1;
    }
  }
  if (vis[x] || mark) return 1;
  return 0;
}
void bfs(int u) {
  queue<int> que;
  Min = 1000000;
  deep = 0;
  memset(vis, -1, sizeof(vis));
  vis[u] = 0;
  for (int i = head[u]; i != -1; i = edge[i].next) {
    int v = edge[i].to;
    if (vis[v] != -1) continue;
    que.push(v);
    vis[v] = vis[u] + 1;
    if (vis[v] > deep) {
      deep = vis[v];
      Min = v;
    } else if (vis[v] == deep)
      Min = min(Min, v);
  }
  while (!que.empty()) {
    u = que.front();
    que.pop();
    for (int i = head[u]; i != -1; i = edge[i].next) {
      int v = edge[i].to;
      if (vis[v] != -1) continue;
      que.push(v);
      vis[v] = vis[u] + 1;
      if (vis[v] > deep) {
        deep = vis[v];
        Min = v;
      } else if (vis[v] == deep)
        Min = min(Min, v);
    }
  }
}
int main() {
  memset(head, -1, sizeof(head));
  scanf("%d%d", &n, &m);
  for (int i = 1, x, y; i < n; i++) {
    scanf("%d%d", &x, &y);
    vec[x].push_back(y);
    vec[y].push_back(x);
  }
  int x;
  for (int i = 0; i < m; i++) {
    scanf("%d", &x);
    vis[x]++;
  }
  if (m == 1)
    printf("%d\n0", vis[x]);
  else {
    dfs(0, x);
    bfs(Min);
    int finmin = Min;
    bfs(Min);
    finmin = min(finmin, Min);
    cout << finmin << endl;
    cout << cnt - deep << endl;
  }
}
