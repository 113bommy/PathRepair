#include <bits/stdc++.h>
using namespace std;
bool visited[55][55];
char c[55][55];
bool era = 0;
int n, m;
int dc[] = {-1, 1, 0, 0};
int dr[] = {0, 0, 1, -1};
bool ans = 0;
int targetx, targety;
bool check(int x, int y, char ch) {
  if (x < 0 || x >= n || y < 0 || y >= m) return 0;
  if (ch == c[x][y])
    return 1;
  else
    return 0;
}
void dfs(int x, int y, char ch, int length) {
  if (x == targetx && y == targety && length >= 4) ans = true;
  if (!check(x, y, ch) || visited[x][y]) return;
  visited[x][y] = true;
  for (int i = 0; i < 4; i++) dfs(x + dc[i], y + dr[i], ch, length + 1);
}
int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) cin >> c[i][j];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      memset(visited, 0, sizeof visited);
      targetx = i;
      targety = j;
      dfs(i, j, c[i][j], 0);
      if (ans == 1) {
        cout << "Yes";
        return 0;
      }
    }
  }
  cout << "No";
  return 0;
}
