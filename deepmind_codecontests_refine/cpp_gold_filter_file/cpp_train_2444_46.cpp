#include <bits/stdc++.h>
using namespace std;
const int SIZE = 2e5 + 4;
const int d4x[] = {1, -1, 0, 0};
const int d4y[] = {0, 0, 1, -1};
const int d8x[] = {1, 0, -1, 0, 1, -1, -1, 1};
const int d8y[] = {0, 1, 0, -1, 1, 1, -1, -1};
void fastio() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
}
string mesh[51];
bool visited[51][51];
bool iscycle = false;
int n, m;
void dfs(int x, int y, int fromX, int fromY, int needColor) {
  if (x < 0 || x >= n || y < 0 || y >= m) return;
  if (mesh[x][y] != needColor) return;
  if (visited[x][y]) {
    iscycle = true;
    return;
  }
  visited[x][y] = true;
  for (int d = 0; d < 4; d++) {
    int nextX = x + d4x[d];
    int nextY = y + d4y[d];
    if (nextX == fromX && nextY == fromY) continue;
    dfs(nextX, nextY, x, y, needColor);
  }
}
void solveTest() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> mesh[i];
  }
  memset(visited, false, sizeof(visited));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (!visited[i][j]) {
        dfs(i, j, -1, -1, mesh[i][j]);
      }
    }
  }
  if (iscycle) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}
int main() {
  fastio();
  solveTest();
  return 0;
}
