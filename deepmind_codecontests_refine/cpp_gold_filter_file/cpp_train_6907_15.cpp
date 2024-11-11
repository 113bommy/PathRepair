#include <bits/stdc++.h>
using namespace std;
bool visit[100005];
long long d[100005];
int parent[100005], head[100005], len;
typedef struct Node {
  int next, to, w;
} Node;
Node edge[100005 * 2];
void addEdge(int u, int v, int w) {
  edge[++len].next = head[u];
  edge[len].to = v;
  edge[len].w = w;
  head[u] = len;
}
void dfs(int x) {
  if (parent[x]) dfs(parent[x]);
  printf("%d ", x);
}
void SPFA(int src, int dst) {
  for (int i = 0; i <= dst; i++) {
    d[i] = 1e18;
  }
  queue<int> q;
  memset(visit, 0, sizeof(visit));
  memset(parent, 0, sizeof(parent));
  d[src] = 0;
  q.push(src);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    visit[u] = false;
    for (int i = head[u]; i; i = edge[i].next) {
      int v = edge[i].to;
      int w = edge[i].w;
      if (d[v] > d[u] + w) {
        d[v] = d[u] + w;
        parent[v] = u;
        if (!visit[v]) {
          visit[v] = true;
          q.push(v);
        }
      }
    }
  }
}
int main(int argc, char const *argv[]) {
  int n, m, u, v, w;
  while (scanf("%d%d", &n, &m) != EOF) {
    memset(head, 0, sizeof(head));
    len = 0;
    for (int i = 0; i < m; i++) {
      scanf("%d%d%d", &u, &v, &w);
      addEdge(u, v, w);
      addEdge(v, u, w);
    }
    SPFA(1, n);
    if (d[n] == 1e18) {
      puts("-1");
    } else {
      dfs(n);
    }
  }
  return 0;
}
