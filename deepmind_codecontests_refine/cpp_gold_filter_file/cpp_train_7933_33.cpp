#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9 + 7;
int dx[] = {1, -1, 0, 0, 1, -1, 1, -1, 0},
    dy[] = {0, 0, 1, -1, 1, -1, -1, 1, 0};
char tmp[10][10], a[10][10];
bool used[10][10][105];
void dfs(int i, int j, int tim) {
  used[i][j][tim] = true;
  if (tim > 100) {
    return;
  }
  if (i == 7 && j == 0) {
    cout << "WIN" << endl;
    exit(0);
  }
  for (int k = 0; k < 9; k++) {
    int nx = i + dx[k], ny = j + dy[k];
    if (nx < 0 || nx >= 8 || ny < 0 || ny >= 8) continue;
    if (a[nx][ny - tim - 1] != 'S' && a[nx][ny - tim] != 'S') {
      if (!used[nx][ny][tim + 1]) dfs(nx, ny, tim + 1);
    }
  }
}
int main() {
  for (int i = 0; i < 8; i++) {
    cin >> tmp[i];
  }
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      a[i][j] = tmp[j][i];
    }
  }
  dfs(0, 7, 0);
  for (int i = 0; i < 105; i++) {
    if (used[7][0][i]) {
      cout << "WIN" << endl;
      return 0;
    }
  }
  cout << "LOSE" << endl;
  return 0;
}
