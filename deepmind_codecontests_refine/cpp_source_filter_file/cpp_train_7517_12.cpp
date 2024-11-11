#include <bits/stdc++.h>
using namespace std;
char Grid[11][11];
int vis[11][11][11];
bool arrive = 0;
int dx[9] = {0, 0, 1, 0, -1, 1, -1, 1, -1};
int dy[9] = {0, 1, 0, -1, 0, 1, -1, -1, 1};
bool Valid(int x, int y) { return x >= 0 && x < 8 && y >= 0 && y < 8; }
void Dfs(int x, int y, int t) {
  if (vis[x][y][t] || arrive) return;
  if (t == 8) {
    arrive = 1;
    return;
  }
  if (x - t >= 0 && Grid[x - t][y] == 'S') return;
  vis[x][y][t] = 1;
  for (int i = 0; i <= 8; i++) {
    int xx = x + dx[i], yy = y + dy[i];
    if (xx - t && Grid[xx - t][yy] == 'S') continue;
    if (Valid(xx, yy)) {
      t++;
      Dfs(xx, yy, t);
      t--;
    }
  }
}
int main() {
  for (int i = 0; i < 8; i++)
    for (int j = 0; j < 8; j++) cin >> Grid[i][j];
  Dfs(7, 0, 0);
  (arrive == 1) ? cout << "WIN" << endl : cout << "LOSE" << endl;
  return 0;
}
