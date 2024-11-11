#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e3 + 10;
typedef int i_N1[maxn];
int N, depth[2][maxn];
i_N1 mark, P, reach;
pair<int, int> edge[maxn];
vector<pair<int, int> > adj[maxn];
queue<int> node;
void BFS(int u, int t) {
  memset(reach, 0, sizeof(reach));
  depth[t][u] = 0;
  node.push(u);
  reach[u] = 1;
  while (!node.empty()) {
    u = node.front();
    node.pop();
    for (int i = int(0); i <= int(adj[u].size() - 1); i++) {
      int v = adj[u][i].first, id = adj[u][i].second;
      if (!reach[v]) {
        if (!t) P[v] = u;
        mark[id] = 1;
        depth[t][v] = min(depth[t][v], depth[t][u] + 1);
        reach[v] = 1;
        node.push(v);
      }
    }
  }
}
int main() {
  scanf("%d\n", &N);
  for (int i = 1; i <= N && scanf("%d%d\n", &edge[i].first, &edge[i].second);
       i++) {
    adj[edge[i].first].push_back(pair<int, int>(edge[i].second, i));
    adj[edge[i].second].push_back(pair<int, int>(edge[i].first, i));
  }
  for (int i = int(1); i <= int(N); i++) {
    depth[0][i] = N + 1;
    depth[1][i] = N + 1;
  }
  P[1] = -1;
  BFS(1, 0);
  for (int i = int(1); i <= int(N); i++)
    if (!mark[i]) {
      int u = edge[i].first, v = edge[i].second;
      if (depth[0][u] < depth[0][v]) swap(u, v);
      for (; depth[u] > depth[v]; u = P[u]) BFS(u, 1);
      for (; u != v; u = P[u], v = P[v]) {
        BFS(u, 1);
        BFS(v, 1);
      }
      BFS(u, 1);
      break;
    }
  for (int i = int(1); i <= int(N); i++) printf("%d ", depth[1][i]);
}
