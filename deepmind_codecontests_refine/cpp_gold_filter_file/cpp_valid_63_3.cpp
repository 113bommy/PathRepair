#include <bits/stdc++.h>
void dfs(int nodes[1005][1005], size_t n, int edge, std::set<int>& group,
         bool visited[1005]) {
  group.insert(edge);
  visited[edge] = true;
  for (size_t i = 0; i < n; i++) {
    if ((nodes[edge][i] == 1) && (group.find(i) == group.end())) {
      dfs(nodes, n, i, group, visited);
    }
  }
}
int get_group(int index, int* groups) {
  if (groups[index] == index) {
    return index;
  } else {
    return groups[index] = get_group(groups[index], groups);
  }
}
int main() {
  int n, m1, m2;
  std::cin >> n >> m1 >> m2;
  int groups1[1005];
  int groups2[1005];
  for (int i = 0; i < n; i++) {
    groups1[i] = i;
    groups2[i] = i;
  }
  for (int i = 0; i < m1; i++) {
    int edge1, edge2;
    std::cin >> edge1 >> edge2;
    edge1--;
    edge2--;
    int group_a = get_group(edge1, groups1);
    int group_b = get_group(edge2, groups1);
    groups1[group_a] = group_b;
  }
  for (int i = 0; i < m2; i++) {
    int edge1, edge2;
    std::cin >> edge1 >> edge2;
    edge1--;
    edge2--;
    int group_a = get_group(edge1, groups2);
    int group_b = get_group(edge2, groups2);
    groups2[group_a] = group_b;
  }
  std::vector<std::pair<int, int>> pairs;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (get_group(i, groups1) != get_group(j, groups1) &&
          get_group(i, groups2) != get_group(j, groups2)) {
        pairs.emplace_back(i, j);
        groups1[get_group(i, groups1)] = get_group(j, groups1);
        groups2[get_group(i, groups2)] = get_group(j, groups2);
      }
    }
  }
  std::cout << pairs.size() << std::endl;
  for (auto& node : pairs) {
    std::cout << node.first + 1 << " " << node.second + 1 << std::endl;
  }
  return 0;
}
