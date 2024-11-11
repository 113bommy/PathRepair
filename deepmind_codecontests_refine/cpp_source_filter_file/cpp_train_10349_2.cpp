#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 1e6 + 1;
vector<vector<int>> graph(MAX_N);
int deg[MAX_N];
bool vis[MAX_N];
int res;
void bfs(int node, int target) {
  set<int> a, b;
  a.insert(node);
  while (!a.empty() || !b.empty()) {
    if (a.empty()) {
      a.insert(b.begin(), b.end());
      b.clear();
      if (!vis[target]) res++;
      for (auto it = a.begin(); it != a.end(); it++) vis[*it] = true;
    }
    int v = *a.begin();
    a.erase(a.begin());
    vis[v] = true;
    for (int i = 0; i < graph[v].size(); i++) {
      int u = graph[v][i];
      if (vis[u]) continue;
      deg[u]--;
      if (deg[u] == 0) {
        b.erase(u);
        a.insert(u);
        vis[u] = true;
      } else {
        b.insert(u);
      }
    }
  }
}
int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < m; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    graph[v].push_back(u);
    deg[u]++;
  }
  int source, target;
  scanf("%d %d", &target, &source);
  bfs(source, target);
  if (vis[target]) return printf("-1\n"), 0;
  cout << res << endl;
}
