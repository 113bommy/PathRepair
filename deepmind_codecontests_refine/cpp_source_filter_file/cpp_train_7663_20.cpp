#include <bits/stdc++.h>
const int kModulo = 1e9 + 7;
int N;
int cursor;
std::unordered_map<int, int> map[2];
std::vector<std::vector<int> > graph;
std::vector<bool> checked;
int nodeCount, cycle;
void ReadInput() {
  scanf("%d", &N);
  graph = std::vector<std::vector<int> >(2 * N + 1);
  for (int i = 0; i < N; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    if (!map[0][x]) {
      map[0][x] = ++cursor;
    }
    if (!map[1][y]) {
      map[1][y] = ++cursor;
    }
    graph[map[0][x]].push_back(map[1][y]);
    graph[map[1][y]].push_back(map[0][x]);
  }
}
void DFS(int node, int dad) {
  nodeCount++;
  checked[node] = true;
  for (auto& son : graph[node]) {
    if (son != dad) {
      if (checked[son]) {
        cycle = true;
      } else {
        DFS(son, node);
      }
    }
  }
}
int Power(int x) {
  int answer = 1;
  for (int i = 1; i <= x; i++) {
    answer = answer * 2 % kModulo;
  }
  return answer;
}
int GetAnswer() {
  int answer = 1;
  for (int i = 1; i <= cursor; i++) {
    if (!checked[i]) {
      nodeCount = 0;
      cycle = false;
      DFS(i, 0);
      int x = Power(nodeCount);
      if (cycle) {
        answer = 1LL * answer * x % kModulo;
      } else {
        x = (x == 0) ? kModulo - 1 : x - 1;
        answer = (answer * x) % kModulo;
      }
    }
  }
  return answer;
}
int main() {
  ReadInput();
  checked = std::vector<bool>(cursor + 1, false);
  printf("%d\n", GetAnswer());
  return 0;
}
