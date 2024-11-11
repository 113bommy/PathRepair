#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5 + 5;
const long long INF = 0x3f3f3f3f3f3f3f3f;
struct node {
  int v, id;
  long long w;
  node(int v = 0, long long w = 0, int id = 0) : v(v), w(w), id(id) {}
  bool operator<(const node& a) const {
    if (w == a.w)
      return v < a.v;
    else
      return w > a.w;
  }
};
vector<node> G[maxn];
long long dis[maxn];
node pre[maxn];
int n, m, vis[maxn];
void dijkstra(int s) {
  for (int i = 1; i <= n; i++) dis[i] = INF;
  dis[s] = 0;
  pre[s] = node(0, 0, 0);
  vis[s] = 1;
  priority_queue<node> q;
  q.push(node(s, dis[s]));
  while (!q.empty()) {
    node p1 = q.top();
    int u = p1.v;
    vis[u] = 1;
    q.pop();
    for (int i = 0; i < G[u].size(); i++) {
      node p2 = G[u][i];
      int v = p2.v;
      if (!vis[v] && dis[v] > dis[u] + p2.w) {
        dis[v] = dis[u] + p2.w;
        pre[v] = p2;
        q.push(node(v, dis[v], p2.id));
      } else if (dis[v] == dis[u] + p2.w) {
        if (pre[v].w > p2.w) {
          pre[v] = p2;
        }
      }
    }
  }
}
int main() {
  int u, v, w;
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= m; i++) {
    scanf("%d %d %d", &u, &v, &w);
    G[u].push_back(node(v, w, i));
    G[v].push_back(node(u, w, i));
  }
  scanf("%d", &u);
  dijkstra(u);
  long long sum = 0;
  for (int i = 1; i <= n; i++) {
    node p = pre[i];
    if (p.v != 0) {
      sum += p.w;
    }
  }
  printf("%I64d\n", sum);
  for (int i = 1; i <= n; i++) {
    node p = pre[i];
    if (p.v != 0) {
      printf("%d ", p.id);
    }
  }
  return 0;
}
