#include <bits/stdc++.h>
bool visited[100010] = {0};
std::vector<std::vector<int> > letter(100010), g(100010);
int ans[100010] = {0}, ansCount = 0;
bool bfs(int i, bool cannot[]) {
  std::queue<int> q;
  q.push(i);
  while (q.empty() == false) {
    int top = q.front();
    q.pop();
    if (visited[top])
      continue;
    else
      visited[top] = true;
    if (cannot[top]) return 0;
    ans[ansCount] = top;
    ++ansCount;
    for (int i = 0; i < g[top].size(); ++i) {
      int next = g[top][i];
      if (!visited[next]) {
        q.push(next);
      }
    }
  }
  return 1;
}
int main() {
  bool must[100010] = {0}, cannot[100010] = {0};
  int n, m;
  std::cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    int k;
    std::cin >> k;
    for (int j = 0; j < k; ++j) {
      int x;
      std::cin >> x;
      letter[i].push_back(x - 1);
    }
    if (i != 0) {
      bool isDifferent = false;
      for (int j = 0; j < std::min(letter[i].size(), letter[i - 1].size());
           ++j) {
        if (letter[i][j] != letter[i - 1][j]) {
          isDifferent = true;
          if (letter[i][j] > letter[i - 1][j]) {
            g[letter[i][j]].push_back(letter[i - 1][j]);
            break;
          } else if (letter[i - 1][j] > letter[i][j]) {
            cannot[letter[i][j]] = 1;
            must[letter[i - 1][j]] = 1;
            break;
          }
        }
      }
      if (!isDifferent) {
        if (letter[i].size() < letter[i - 1].size()) {
          std::cout << "No";
          return 0;
        }
      }
    }
  }
  for (int i = 0; i < m; ++i) {
    if (must[i] && cannot[i]) {
      std::cout << "No";
      return 0;
    } else if (must[i] && !visited[i]) {
      if (bfs(i, cannot))
        continue;
      else {
        std::cout << "No";
        return 0;
      }
    }
  }
  std::cout << "Yes\n";
  std::cout << ansCount << "\n";
  for (int i = 0; i < ansCount; ++i) std::cout << ans[i] + 1 << " ";
}
