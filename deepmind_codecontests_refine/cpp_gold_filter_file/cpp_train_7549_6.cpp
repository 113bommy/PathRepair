#include <bits/stdc++.h>
std::vector<std::pair<int, int>> edges[100001];
int marks[100001], res[100001];
int dfs(int vertex) {
  if (marks[vertex] != 0) return marks[vertex];
  marks[vertex] = 1;
  for (std::vector<std::pair<int, int>>::iterator it = edges[vertex].begin();
       it != edges[vertex].end(); ++it) {
    int end = (*it).first;
    if (dfs(end) + 1 > marks[vertex]) {
      marks[vertex] = marks[end] + 1;
      res[vertex] = std::max(res[end], (*it).second);
    }
  }
  return marks[vertex];
}
int main() {
  int n = 0, m = 0;
  std::cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    int beg = 0, end = 0;
    std::cin >> beg >> end;
    beg -= 1;
    end -= 1;
    edges[beg].push_back(std::make_pair(end, i + 1));
  }
  for (int i = 0; i < n; ++i) {
    int result = dfs(i);
    if (result == n) {
      std::cout << res[i];
      return 0;
    }
  }
  std::cout << -1;
  return 0;
}
