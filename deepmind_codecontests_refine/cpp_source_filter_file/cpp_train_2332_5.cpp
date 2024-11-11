#include <bits/stdc++.h>
using namespace std;
int n, m, k, dirx[4] = {1, 0, -1, 0}, diry[4] = {0, 1, 0, -1}, vis[505][505];
vector<string> board;
void DFS(int x, int y, int dpt) {
  vis[x][y]++;
  for (int i = 0; i < 4; i++) {
    if (x + dirx[i] >= n || x + dirx[i] < 0 || y + diry[i] >= m ||
        y + diry[i] < 0)
      continue;
    if (board[x + dirx[i]][y + diry[i]] == '#' || vis[x + dirx[i]][y + diry[i]])
      continue;
    DFS(x + dirx[i], y + diry[i], dpt + 1);
  }
  if (dpt) {
    printf("D %d %d", x + 1, y + 1);
    printf("R %d %d", x + 1, y + 1);
  }
}
void dfs(int x, int y) {
  vis[x][y]++;
  for (int i = 0; i < 4; i++) {
    if (x + dirx[i] >= n || x + dirx[i] < 0 || y + diry[i] >= m ||
        y + diry[i] < 0)
      continue;
    if (board[x + dirx[i]][y + diry[i]] == '#' || vis[x + dirx[i]][y + diry[i]])
      continue;
    k += 2;
    dfs(x + dirx[i], y + diry[i]);
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m;
  string s;
  for (int i = 0; i < n; i++) {
    cin >> s;
    board.push_back(s);
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (board[i][j] == '.') {
        k++;
      }
    }
  }
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      if (board[i][j] == '.' && vis[i][j] == 0) dfs(i, j);
    }
  cout << k << endl;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (board[i][j] == '.') {
        printf("B %d %d", i + 1, j + 1);
      }
    }
  }
  memset(vis, 0, sizeof(vis[0][0]) * 505 * 505);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      if (board[i][j] == '.' && vis[i][j] == 0) DFS(i, j, 0);
    }
  return 0;
}
