#include <bits/stdc++.h>
using namespace std;
const long long big = 1e12;
void dijkstra(vector<vector<pair<long long, long long> > > graph) {
  long long n = graph.size() - 1;
  vector<long long> d(n + 1, big);
  vector<long long> parent(n + 1, -1);
  d[1] = 0;
  using pii = pair<long long, long long>;
  priority_queue<pii, vector<pii>, greater<pii> > my_heap;
  my_heap.push(make_pair(0, 1));
  while (!my_heap.empty()) {
    long long u = my_heap.top().second;
    long long distu = my_heap.top().first;
    my_heap.pop();
    if (d[u] != distu) {
      continue;
    }
    for (auto edges : graph[u]) {
      long long w = edges.second;
      long long v = edges.first;
      if (d[v] > w + d[u]) {
        d[v] = w + d[u];
        parent[v] = u;
        my_heap.push(make_pair(d[v], v));
      }
    }
  }
  vector<long long> ans;
  for (long long v = n; v != -1; v = parent[v]) {
    ans.push_back(v);
  }
  if (ans[ans.size() - 1] != 1) {
    cout << -1;
    return;
  }
  for (long long i = ans.size() - 1; i >= 0; i--) {
    cout << ans[i] << " ";
  }
  return;
}
int main() {
  long long n, m;
  cin >> n >> m;
  vector<vector<pair<long long, long long> > > graph(n + 1);
  for (long long i = 0; i < m; i++) {
    long long u, v, w;
    cin >> u >> v >> w;
    graph[u].push_back(make_pair(v, w));
    graph[v].push_back(make_pair(u, w));
  }
  dijkstra(graph);
}
