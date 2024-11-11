#include <bits/stdc++.h>
using ll = long long;
using namespace std;
vector<int> ans;
void dfs(int bit, int v, vector<vector<pair<int, int>>> &graph,
         vector<bool> &visited) {
  visited[v >> 1] = 1;
  while (!graph[bit].empty()) {
    auto d = graph[bit].back();
    graph[bit].pop_back();
    if (!visited[d.second >> 1]) dfs(d.first, d.second, graph, visited);
  }
  ans.emplace_back((v ^ 1) + 1);
  ans.emplace_back(v + 1);
}
int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(15);
  int n, x, y;
  cin >> n;
  vector<int> vertices;
  for (ll i = 0, iLen = (n); i < iLen; ++i) {
    cin >> x >> y;
    vertices.emplace_back(x);
    vertices.emplace_back(y);
  }
  if (n == 1) {
    for (ll k = 20, kLen = (-1); k > kLen; --k)
      if ((vertices[0] & ((1 << k) - 1)) == (vertices[1] & ((1 << k) - 1))) {
        cout << k << endl;
        cout << "1 2" << endl;
        return 0;
      }
  }
  auto create_graph = [&](int k) {
    int mask = (1 << k) - 1;
    vector<vector<pair<int, int>>> graph(mask + 1);
    for (ll i = 0, iLen = (n); i < iLen; ++i) {
      graph[vertices[2 * i] & mask].emplace_back(vertices[2 * i + 1] & mask,
                                                 2 * i);
      graph[vertices[2 * i + 1] & mask].emplace_back(vertices[2 * i] & mask,
                                                     2 * i + 1);
    }
    return graph;
  };
  for (ll k = 20, kLen = (0); k > kLen; --k) {
    ans.clear();
    auto graph = create_graph(k);
    bool ok = 1;
    vector<bool> visited(n);
    int comp = 0;
    for (ll i = 0, iLen = (1 << k); i < iLen; ++i)
      if (graph[i].size() & 1) {
        ok = 0;
        break;
      }
    if (ok)
      for (ll i = 0, iLen = (1 << k); i < iLen; ++i)
        if (graph[i].size() > 0) {
          while (!graph[i].empty()) {
            auto e = graph[i].back();
            graph[i].pop_back();
            if (!visited[e.second >> 1]) {
              comp++;
              dfs(e.first, e.second, graph, visited);
            }
          }
        }
    if (ok && comp == 1 && ans.size() == 2 * n) {
      cout << k << endl;
      for (ll i = 0, iLen = (2 * n); i < iLen; ++i)
        cout << ans[i] << (i == 2 * n - 1 ? "\n" : " ");
      return 0;
    }
  }
  cout << 0 << endl;
  for (ll i = 1, iLen = (2 * n + 1); i < iLen; ++i)
    cout << i << (i == 2 * n ? "\n" : " ");
}
