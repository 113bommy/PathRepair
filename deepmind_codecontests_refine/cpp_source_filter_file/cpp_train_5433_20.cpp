#include <bits/stdc++.h>
void dfs_bipartite(int32_t vertex, bool* visited, std::vector<int32_t>* graph,
                   bool& bipartite, bool* part, bool white) {
  part[vertex] = white;
  visited[vertex] = true;
  for (int32_t i = 0; i < graph[vertex].size(); i++)
    if (!visited[graph[vertex][i]])
      dfs_bipartite(graph[vertex][i], visited, graph, bipartite, part, !white);
    else if (part[graph[vertex][i]] == white)
      bipartite = false;
}
int64_t get_bipartite_variants(int32_t n, std::vector<int32_t>* graph,
                               int32_t& connected_components) {
  bool *visted = new bool[n], *part = new bool[n];
  for (int32_t i = 0; i < n; i++) visted[i] = false;
  int64_t answer = 1;
  for (int32_t i = 0; i < n; i++)
    if (!visted[i]) {
      connected_components++;
      bool bipartite = true;
      dfs_bipartite(i, visted, graph, bipartite, part, true);
      if (!bipartite)
        answer = 0;
      else {
        answer *= 2;
      }
    }
  return answer;
}
int64_t get_01(int32_t n, int64_t* graph_masks) {
  int32_t left_half = n / 2;
  std::vector<int32_t> passing_masks;
  for (int32_t i = 0; i < (1 << left_half); i++) {
    bool passes = true;
    for (int32_t j = 0; j < left_half; j++)
      if ((i & (1 << j)) && (graph_masks[j] & i) != 0) {
        passes = false;
        break;
      }
    if (passes) passing_masks.push_back(i);
  }
  int32_t** dp = new int32_t*[21];
  for (int32_t i = 20; i >= 0; i--) {
    dp[i] = new int32_t[1 << 20];
    if (i == 20) {
      for (int32_t j = 0; j < (1 << 20); j++) dp[i][j] = 0;
      for (int32_t j = 0; j < passing_masks.size(); j++)
        dp[i][passing_masks[j]]++;
      continue;
    }
    for (int32_t j = 0; j < (1 << 20); j++)
      dp[i][j] = dp[i + 1][j] + ((j & (1 << i)) ? dp[i + 1][j ^ (1 << i)] : 0);
  }
  int64_t answer = 0;
  int32_t right_half = n - left_half;
  for (int32_t i = 0; i < (1 << right_half); i++) {
    bool passes = true;
    for (int32_t j = 0; j < right_half; j++)
      if ((i & (1 << j)) &&
          (graph_masks[left_half + j] & (i << left_half)) != 0) {
        passes = false;
        break;
      }
    if (passes) {
      int64_t all_connections = 0;
      for (int32_t j = 0; j < right_half; j++)
        if (i & (1 << j)) all_connections |= graph_masks[left_half + j];
      int64_t required_submask = (~all_connections) & ((1 << left_half) - 1);
      answer += dp[0][required_submask];
    }
  }
  return answer;
}
int main() {
  int32_t n, m;
  std::cin >> n >> m;
  if (n == 1) {
    std::cout << 0;
    return 0;
  }
  int64_t* graph_masks = new int64_t[n];
  for (int32_t i = 0; i < n; i++) graph_masks[i] = 0;
  std::vector<int32_t>* graph = new std::vector<int32_t>[n];
  for (int32_t i = 0; i < m; i++) {
    int32_t src, dst;
    std::cin >> src >> dst;
    src--;
    dst--;
    graph[src].push_back(dst);
    graph[dst].push_back(src);
    graph_masks[src] |= 1ll << dst;
    graph_masks[dst] |= 1ll << src;
  }
  int32_t connected_components = 0;
  int32_t num_lone_vertices = 0;
  for (int32_t i = 0; i < n; i++)
    if (graph_masks[i] == 0) num_lone_vertices++;
  int64_t only0 = 1ll << num_lone_vertices;
  int64_t only1 = get_bipartite_variants(n, graph, connected_components);
  int64_t only2 = num_lone_vertices == n ? 0 : (1ll << num_lone_vertices);
  int64_t only01 = get_01(n, graph_masks);
  int64_t only02 = 1ll << connected_components;
  int64_t only12 = only01;
  int64_t answer =
      (1ll << n) + only0 + only1 + only2 - only01 - only02 - only12;
  std::cout << answer;
  return 0;
}
