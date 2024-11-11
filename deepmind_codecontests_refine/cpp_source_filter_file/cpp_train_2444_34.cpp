#include <bits/stdc++.h>
using namespace std;
bool graph[2505][2505];
int color[2505], dfsNum[2505];
int num, n1, flag;
void dfs(int u, int p) {
  color[u] = 1;
  dfsNum[u] = ++num;
  for (int v = 0; v < n1; ++v) {
    if (graph[u][v] && (v != p)) {
      if (color[v] == 0)
        dfs(v, u);
      else if (color[v] == 1) {
        flag = 1;
      }
    }
  }
  color[u] = 2;
}
int main() {
  int n, m, pos;
  char mapaC[55][55];
  scanf("%d %d", &n, &m);
  num = 0;
  for (int i = 0, j; i < n; i++) {
    for (j = 0; j < m; j++) {
      graph[i][j] = 0;
    }
    color[i] = 0;
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      scanf(" %c", &mapaC[i][j]);
    }
  }
  n1 = n * m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      pos = (i * m) + j + 1;
      if (mapaC[i][j] == mapaC[i][j - 1]) graph[pos][pos - 1] = 1;
      if (mapaC[i][j] == mapaC[i][j + 1]) graph[pos][pos + 1] = 1;
      if (mapaC[i][j] == mapaC[i - 1][j]) graph[pos][pos - m] = 1;
      if (mapaC[i][j] == mapaC[i + 1][j]) graph[pos][pos + m] = 1;
    }
  }
  for (int i = 1; i <= n1; i++) {
    flag = 0;
    if (color[i] == 0) {
      dfs(i, i);
      if (flag == 1) {
        printf("Yes\n");
        break;
      }
    }
  }
  if (!flag) printf("No\n");
  return 0;
}
