#include <bits/stdc++.h>
using namespace std;
int k = 0;
int isCorrect(int x, int y, int n, int m) {
  if (x < 0 || y < 0 || x >= n || y >= m) return (0);
  return (1);
}
void dfs(int x, int y, char A[500][500], bool visited[500][500], int n, int m,
         pair<int, int> parent[500][500], int child[500][500]) {
  visited[x][y] = true;
  if (isCorrect(x, y - 1, n, m)) {
    if (A[x][y - 1] != '#' && !visited[x][y - 1]) {
      parent[x][y - 1] = make_pair(x, y);
      ++child[x][y];
      dfs(x, y - 1, A, visited, n, m, parent, child);
    }
  }
  if (isCorrect(x, y + 1, n, m)) {
    if (A[x][y + 1] != '#' && !visited[x][y + 1]) {
      parent[x][y + 1] = make_pair(x, y);
      ++child[x][y];
      dfs(x, y + 1, A, visited, n, m, parent, child);
    }
  }
  if (isCorrect(x - 1, y, n, m)) {
    if (A[x - 1][y] != '#' && !visited[x - 1][y]) {
      parent[x - 1][y] = make_pair(x, y);
      ++child[x][y];
      dfs(x - 1, y, A, visited, n, m, parent, child);
    }
  }
  if (isCorrect(x + 1, y, n, m)) {
    if (A[x + 1][y] != '#' && !visited[x + 1][y]) {
      parent[x + 1][y] = make_pair(x, y);
      ++child[x][y];
      dfs(x + 1, y, A, visited, n, m, parent, child);
    }
  }
  if (child[x][y] == 0 && k > 0) {
    --child[parent[x][y].first][parent[x][y].second];
    A[x][y] = 'X';
    --k;
  }
}
int main() {
  int n, m;
  cin >> n >> m >> k;
  char A[500][500];
  pair<int, int> parent[500][500];
  int child[500][500];
  bool visited[500][500];
  int x, y;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> A[i][j];
      if (A[i][j] == '.') {
        x = i;
        y = j;
      }
      visited[i][j] = false;
      parent[i][j] = make_pair(i, j);
      child[i][j] = 0;
    }
  }
  dfs(x, y, A, visited, n, m, parent, child);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cout << A[i][j] << " ";
    }
    cout << endl;
  }
}
