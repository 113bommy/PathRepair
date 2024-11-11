#include <bits/stdc++.h>
using namespace std;
int N, M;
int path[2010], ans[2010];
bool graph[110][110];
bool used[110][110];
void dfs(int x, int y) {
  int i;
  if (!graph[x][y] || used[x][y]) return;
  used[x][y] = used[y][x] = true;
  for ((i) = 0; (i) < (int)(N); (i)++) dfs(y, i);
}
bool connected(int x) {
  int i, j;
  for ((i) = 0; (i) < (int)(N); (i)++)
    for ((j) = 0; (j) < (int)(N); (j)++) used[i][j] = false;
  for ((i) = 0; (i) < (int)(N); (i)++) dfs(x, i);
  for ((i) = 0; (i) < (int)(N); (i)++)
    for ((j) = 0; (j) < (int)(N); (j)++)
      if (graph[i][j] && !used[i][j]) return false;
  return true;
}
void func(int len, int x) {
  int i, j;
  for ((i) = 0; (i) < (int)(len); (i)++) ans[i] = path[i];
  ans[len] = x;
  for (i = len; i < M; i++)
    for ((j) = 0; (j) < (int)(N); (j)++)
      if (graph[x][j]) {
        graph[x][j] = graph[j][x] = false;
        if (connected(j)) {
          x = j;
          ans[i + 1] = x;
          continue;
        }
        graph[x][j] = graph[j][x] = true;
      }
  for ((i) = 0; (i) < (int)(M); (i)++) cout << ans[i] + 1 << ' ';
  cout << ans[M] + 1 << endl;
}
int main(void) {
  int i, j;
  cin >> N >> M;
  for ((i) = 0; (i) < (int)(M + 1); (i)++) {
    cin >> path[i];
    path[i]--;
  }
  bool found = false;
  for (i = M - 1; i >= 0; i--) {
    graph[path[i]][path[i + 1]] = graph[path[i + 1]][path[i]] = true;
    for (j = path[i + 1] + 1; j < N; j++)
      if (graph[path[i]][j]) {
        graph[path[i]][j] = graph[j][path[i]] = false;
        if (connected(j)) break;
        graph[path[i]][j] = graph[j][path[i]] = true;
      }
    if (j < N) {
      found = true;
      func(i + 1, j);
      break;
    }
  }
  if (!found) cout << "No solution" << endl;
  return 0;
}
