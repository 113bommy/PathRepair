#include <bits/stdc++.h>
struct Edge {
  int v1, v2, idx;
  int weight;
  bool operator<(Edge const& other) const { return weight < other.weight; }
};
struct DSU {
 private:
  std::vector<int> parent, rnk;

 public:
  DSU(int n_vertex) {
    rnk.assign(n_vertex, 0);
    parent.resize(n_vertex);
    for (int i = 0; i < n_vertex; ++i) parent[i] = i;
  }
  int findparent(int vertex) {
    return (parent[vertex] ^ vertex
                ? parent[vertex] = findparent(parent[vertex])
                : vertex);
  }
  bool unite_set(int v1, int v2) {
    v1 = findparent(v1), v2 = findparent(v2);
    if (v1 == v2) return false;
    if (rnk[v1] < rnk[v2]) std::swap(v1, v2);
    parent[v2] = v1;
    if (rnk[v1] == rnk[v2]) ++rnk[v1];
    return true;
  }
};
const int logV = 18;
std::vector<std::set<std::pair<int, int> > > adjSet;
std::vector<std::vector<std::pair<int, int> > > adjList;
std::vector<std::vector<int> > up, max_weight;
std::vector<int> depth, result;
std::vector<Edge> edges;
void travel(int vertex, int prev_eidx = -1) {
  for (auto& v : adjList[vertex]) {
    if (v.first != up[vertex][0]) {
      auto& e = edges[v.second];
      depth[v.first] = depth[vertex] + 1;
      up[v.first][0] = vertex;
      max_weight[v.first][0] = e.weight;
      for (int i = 1; i < logV; ++i) {
        max_weight[v.first][i] = max_weight[v.first][i - 1];
        int up_v = up[v.first][i - 1];
        if (up_v != -1) {
          up[v.first][i] = up[up_v][i - 1];
          max_weight[v.first][i] =
              std::max(max_weight[v.first][i], max_weight[up_v][i - 1]);
        }
      }
      travel(v.first, e.idx);
      if (adjSet[v.first].size() > adjSet[vertex].size())
        std::swap(adjSet[v.first], adjSet[vertex]);
      for (auto& w : adjSet[v.first]) {
        auto it = adjSet[vertex].find(w);
        if (it != adjSet[vertex].end())
          adjSet[vertex].erase(it);
        else
          adjSet[vertex].emplace(w);
      }
      adjSet[v.first].clear();
    }
  }
  if (prev_eidx != -1) {
    if (adjSet[vertex].empty())
      result[prev_eidx] = -1;
    else
      result[prev_eidx] = adjSet[vertex].begin()->first - 1;
  }
}
int get_max_weight(int v1, int v2) {
  if (depth[v1] > depth[v2]) std::swap(v1, v2);
  int ret = 0;
  for (int i = logV - 1; i >= 0; --i) {
    if (depth[v2] - depth[v1] >= (1 << i)) {
      ret = std::max(ret, max_weight[v2][i]);
      v2 = up[v2][i];
    }
  }
  if (v1 == v2) return ret;
  for (int i = logV - 1; i >= 0; --i) {
    if (up[v1][i] != up[v2][i]) {
      ret = std::max(ret, std::max(max_weight[v1][i], max_weight[v2][i]));
      v1 = up[v1][i], v2 = up[v2][i];
    }
  }
  ret = std::max(ret, std::max(max_weight[v1][0], max_weight[v2][0]));
  return ret;
}
int main() {
  std::ios_base::sync_with_stdio(0);
  std::cin.tie(0);
  int n_vertex, n_edge;
  std::cin >> n_vertex >> n_edge;
  edges.resize(n_edge);
  for (int i = 0; i < n_edge; ++i) edges[i].idx = i;
  for (auto& e : edges) {
    std::cin >> e.v1 >> e.v2 >> e.weight;
    --e.v1, --e.v2;
  }
  std::sort(edges.begin(), edges.end());
  DSU dsu(n_vertex);
  std::vector<bool> selected(n_vertex, false);
  adjList.resize(n_vertex);
  adjSet.resize(n_vertex);
  for (int i = 0; i < n_edge; ++i) {
    auto& e = edges[i];
    if (dsu.unite_set(e.v1, e.v2)) {
      selected[e.idx] = true;
      adjList[e.v1].emplace_back(e.v2, i);
      adjList[e.v2].emplace_back(e.v1, i);
    } else {
      adjSet[e.v1].emplace(e.weight, e.idx);
      adjSet[e.v2].emplace(e.weight, e.idx);
    }
  }
  up.assign(n_vertex, std::vector<int>(logV, -1));
  max_weight.assign(n_vertex, std::vector<int>(logV, 0));
  depth.resize(n_vertex), depth[0] = 0;
  result.resize(n_edge);
  travel(0);
  for (auto& e : edges) {
    if (!selected[e.idx]) result[e.idx] = get_max_weight(e.v1, e.v2) - 1;
  }
  for (int i = 0; i < n_edge; ++i) std::cout << result[i] << " ";
  return 0;
}
