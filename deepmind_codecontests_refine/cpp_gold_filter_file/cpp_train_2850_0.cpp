#include <bits/stdc++.h>
using namespace std;
struct edge {
  int b, c, num, d;
};
vector<vector<edge> > graph;
bool vis[200005];
int ans[200005];
int flow[200005];
void bfs() {
  queue<int> Q;
  Q.push(1);
  vis[1] = 1;
  while (Q.size()) {
    int cur = Q.front();
    Q.pop();
    for (int i = 0; i < (int)graph[cur].size(); i++) {
      int child = graph[cur][i].b;
      int cost = graph[cur][i].c;
      int num = graph[cur][i].num;
      int d = graph[cur][i].d;
      if (!ans[num]) {
        ans[num] = d;
      }
      flow[child] -= cost;
      if (!vis[child] && !flow[child]) {
        vis[child] = 1;
        Q.push(child);
      }
    }
  }
}
int main() {
  int n, m;
  int a, b, c;
  scanf("%d%d", &n, &m);
  graph = vector<vector<edge> >(n + 1);
  for (int i = 0; i < m; i++) {
    scanf("%d%d%d", &a, &b, &c);
    graph[a].push_back({b, c, i, 1});
    graph[b].push_back({a, c, i, 2});
    flow[a] += c;
    flow[b] += c;
  }
  for (int i = 1; i < n; i++) {
    flow[i] /= 2;
  }
  bfs();
  for (int i = 0; i < m; i++) {
    printf("%d\n", ans[i] - 1);
  }
}
