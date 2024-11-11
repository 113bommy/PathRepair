#include <bits/stdc++.h>
using namespace std;
vector<vector<int> > graph;
vector<int> color;
int result;
void bfs(int from) {
  queue<int> workQ;
  workQ.push(from);
  color[from] = 1;
  while (!workQ.empty()) {
    int curV = workQ.front();
    workQ.pop();
    for (vector<int>::iterator i = graph[curV].begin(); i != graph[curV].end();
         i++) {
      if (color[*i] == 0) {
        color[*i] = 3 - color[curV];
        workQ.push(*i);
      } else if (color[*i] == color[curV]) {
        result++;
        color[curV] = -1;
      }
    }
  }
}
int main() {
  int n, m;
  cin >> n >> m;
  graph.resize(n);
  color.resize(n, 0);
  for (int i = 0; i < m; i++) {
    int from;
    int to;
    cin >> from >> to;
    graph[--from].push_back(--to);
    graph[to].push_back(from);
  }
  for (int i = 0; i < n; i++) {
    if (color[i] == 0) bfs(i);
  }
  if ((n - result) % 2 == 1) result++;
  cout << result << endl;
  return 0;
}
