#include <bits/stdc++.h>
using namespace std;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int n, m;
char grid[50][50];
bool visited[50][50];
pair<int, int> parent[50][50];
pair<int, int> src;
bool found;
bool valid(int posX, int posY) {
  if (posX >= 0 && posX < n && posY >= 0 && posY < m)
    return true;
  else
    return false;
}
void dfs(int x, int y) {
  if (visited[x][y]) return;
  visited[x][y] = true;
  for (int i = 0; i < 4; i++) {
    int nx = x + dx[i];
    int ny = y + dy[i];
    if (valid(x, y) && grid[nx][ny] == grid[x][y] &&
        (parent[x][y].first != nx || parent[x][y].second != ny) && !found) {
      parent[nx][ny] = make_pair(x, y);
      if (visited[nx][ny]) {
        cout << "YES";
        found = true;
        return;
      } else
        dfs(nx, ny);
    }
  }
}
int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      cin >> grid[i][j];
    }
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      if (found) return 0;
      if (!visited[i][j]) dfs(i, j);
    }
  cout << "NO";
  return 0;
}
