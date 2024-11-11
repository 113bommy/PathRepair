#include <bits/stdc++.h>
using namespace std;
string str[51];
bool visited[51][51], flag = false;
int arrx[] = {1, -1, 0, 0}, arry[] = {0, 0, 1, -1}, n, m;
void dfs(int x, int y, int oldX, int oldY, char renk) {
  if (x < 0 || x >= n || y < 0 || y >= m) return;
  if (str[x][y] != renk) return;
  if (visited[x][y] == true) {
    flag = true;
    return;
  }
  visited[x][y] = true;
  for (int i = 0; i < 4; i++) {
    int newX = x + arrx[i], newY = y + arry[i];
    if (newX == oldX && newY == oldY) continue;
    dfs(newX, newY, x, y, renk);
  }
}
int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) cin >> str[i];
  memset(visited, 0, sizeof(visited));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (!visited[i][j]) dfs(i, j, -1, -1, str[i][j]);
    }
  }
  cout << (flag ? "Yes" : "No") << endl;
  return 0;
}
