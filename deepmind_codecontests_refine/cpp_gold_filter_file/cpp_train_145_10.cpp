#include <bits/stdc++.h>
#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-err58-cpp"
#pragma ide diagnostic ignored "cppcoreguidelines-pro-type-member-init"
using namespace std;
const int maxiii = 100022;
struct node {
  bool seen;
  vector<pair<int, bool>> Adj;
  vector<int> B;
};
node graph[maxiii];
void dfs(int v, int p, int e) {
  graph[v].seen = true;
  for (int i = 0; i < graph[v].Adj.size(); ++i)
    if (!graph[v].Adj[i].second) {
      int u = graph[v].Adj[i].first;
      if (!graph[u].seen)
        dfs(u, v, i);
      else if (u != p) {
        graph[u].B.push_back(v);
        graph[v].Adj[i].second = true;
      }
    }
  if (graph[v].B.size() % 2 == 1)
    graph[v].B.push_back(p);
  else if (p != -1) {
    graph[p].B.push_back(v);
    graph[p].Adj[e].second = true;
  }
  for (int i = 0; i < graph[v].B.size(); i += 2)
    cout << graph[v].B[i] << " " << v << " " << graph[v].B[i + 1] << "\n";
}
int main() {
  ios::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  if (m % 2) {
    cout << "No solution";
    return 0;
  }
  for (int i = 0; i < m; ++i) {
    int a, b;
    cin >> a >> b;
    graph[a].Adj.emplace_back(b, false);
    graph[b].Adj.emplace_back(a, false);
  }
  dfs(1, -1, -1);
}
#pragma clang diagnostic pop
