#include <bits/stdc++.h>
using namespace std;
int graph[401][401];
queue<int> qi;
int dis[400];
int main() {
  int n, m, a, b;
  scanf("%d", &n);
  scanf("%d", &m);
  for (int i = 0; i < m; i++) {
    scanf("%d", &a);
    scanf("%d", &b);
    graph[a][b] = 1;
    graph[b][a] = 1;
  }
  if (graph[1][n]) {
    for (int i = 1; i < n + 1; i++) {
      for (int j = 1; j < n + 1; j++) graph[i][j] = 1 - graph[i][j];
    }
  }
  qi.push(1);
  dis[1] = 1;
  while (!qi.empty()) {
    int tp = qi.front();
    qi.pop();
    for (int i = 1; i < n + 1; i++) {
      if (dis[i] == 0 && graph[tp][i] == 1) {
        dis[i] = dis[tp] + 1;
        qi.push(i);
      }
    }
  }
  cout << dis[n] - 1;
  return 0;
}
