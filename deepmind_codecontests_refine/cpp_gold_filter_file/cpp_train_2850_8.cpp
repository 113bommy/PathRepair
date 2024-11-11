#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200010;
const int MAXM = MAXN * 2;
struct Edge {
  int u, v, w;
  int next;
  int type, id;
} edge[MAXM];
int head[MAXN], tot;
void init() {
  tot = 0;
  memset(head, -1, sizeof(head));
}
void add_edge(int u, int v, int w, int type, int id) {
  edge[tot].u = u;
  edge[tot].v = v;
  edge[tot].w = w;
  edge[tot].type = type;
  edge[tot].id = id;
  edge[tot].next = head[u];
  head[u] = tot++;
}
queue<int> q;
int N, M;
bool vis[MAXN];
int ans[MAXN], val[MAXN];
int main() {
  while (scanf("%d%d", &N, &M) != EOF) {
    init();
    memset(val, 0, sizeof(val));
    for (int i = 0; i < M; i++) {
      int u, v, w;
      scanf("%d%d%d", &u, &v, &w);
      add_edge(u, v, w, 0, i + 1);
      add_edge(v, u, w, 1, i + 1);
      val[u] += w;
      val[v] += w;
    }
    while (!q.empty()) q.pop();
    vis[1] = true;
    q.push(1);
    while (!q.empty()) {
      int u = q.front();
      q.pop();
      for (int i = head[u]; i != -1; i = edge[i].next) {
        int v = edge[i].v;
        if (vis[v]) continue;
        val[v] -= 2 * edge[i].w;
        ans[edge[i].id] = edge[i].type;
        if (val[v] == 0 && v != N) {
          vis[v] = true;
          q.push(v);
        }
      }
    }
    for (int i = 1; i <= M; i++) printf("%d\n", ans[i]);
  }
  return 0;
}
