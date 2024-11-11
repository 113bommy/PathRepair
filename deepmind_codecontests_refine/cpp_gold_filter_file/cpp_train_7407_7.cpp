#include <bits/stdc++.h>
using namespace std;
int graph[3000][3000];
int Max = 0;
void deep(int v, int n, int d, int graph[3000][3000]) {
  for (int i = 0; i < n; i += 1) {
    if (graph[i][v] == 1) {
      deep(i, n, d + 1, graph);
    }
  }
  if (d > Max) Max = d;
}
int main() {
  int n, v, d = 0, cntVertex = 0;
  cin >> n;
  int vertex[n];
  for (int i = 0; i < n; i += 1) {
    for (int j = 0; j < n; j += 1) {
      graph[i][j] = 0;
    }
    cin >> v;
    if (v == -1) {
      vertex[i] = 1;
      cntVertex++;
      continue;
    }
    vertex[i] = 0;
    graph[i][v - 1] = 1;
  }
  if (cntVertex == n) {
    cout << 1;
    return 0;
  }
  for (int i = 0; i < n; i += 1) {
    if (vertex[i] == 1) {
      deep(i, n, 1, graph);
    }
  }
  cout << Max;
  return 0;
}
