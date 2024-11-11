#include <bits/stdc++.h>
using namespace std;
int n;
int graph[101][101];
int cost[101][101];
bool dir[101][101];
bool used[101][101];
int C = 0;
int bestC = 10001;
void dfs(int i, int parent, int root) {
  if (i == root) return;
  for (int j = 1; j <= n; j++) {
    if (graph[i][j] != 0 && j != parent) {
      if (dir[j][i]) {
        C += graph[j][i];
      }
      dfs(j, i, root);
    }
  }
}
void solve() {
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (graph[i][j] != 0) {
        if (dir[j][i]) {
          C += graph[j][i];
        }
        dfs(j, i, i);
        if (C < bestC) {
          bestC = C;
        }
        C = 0;
      }
    }
  }
}
int main() {
  cin >> n;
  int i, j, value;
  for (int k = 0; k < n; k++) {
    cin >> i >> j >> value;
    graph[i][j] = value;
    graph[j][i] = value;
    dir[i][j] = true;
  }
  solve();
  cout << bestC;
  return 0;
}
