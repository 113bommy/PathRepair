#include <bits/stdc++.h>
using namespace std;
bool graph[402][402];
int parent[402], n, m, parent1[402];
bool mark[402];
queue<int> bfss;
void add(int x, int p) {
  mark[x] = true;
  parent[x] = p;
  bfss.push(x);
}
void bfs(int vertex) {
  add(vertex, -1);
  while (!bfss.empty()) {
    int x = bfss.front();
    bfss.pop();
    for (int j = 0; j < n; j++) {
      if (graph[x][j])
        if (!mark[j]) {
          add(j, x);
        }
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    graph[a][b] = 1;
    graph[b][a] = 1;
  }
  for (int i = 0; i < n; i++) parent[i] = -2;
  bfs(0);
  for (int i = 0; i < n; i++) {
    parent1[i] = parent[i];
  }
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) {
      if (i != j) {
        if (graph[i][j] == true)
          graph[i][j] = false;
        else
          graph[i][j] = true;
      }
    }
  for (int i = 0; i < n; i++) mark[i] = false;
  for (int i = 0; i < n; i++) parent[i] = -2;
  bfs(0);
  int i = n - 1;
  int j = n - 1;
  if (parent[i] == -2 || parent[j] == -2) {
    cout << -1 << endl;
    return 0;
  }
  int time1 = 0, time2 = 0;
  while (i != 0) {
    i = parent[i];
    time1++;
  }
  while (j != 0) {
    j = parent1[j];
    time2++;
  }
  cout << max(time1, time2) << endl;
}
