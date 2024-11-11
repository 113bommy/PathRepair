#include <bits/stdc++.h>
using namespace std;
const int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int dy[] = {0, -1, -1, -1, 0, 1, 1, 1};
bool ok[8][8][8];
int main() {
  ios_base::sync_with_stdio(0);
  int n = 8;
  string f[n];
  for (int i = 0; i < n; i++) {
    cin >> f[i];
  }
  ok[7][0][0] = 1;
  for (int t = 1; t < n; t++) {
    bool win = 0;
    for (int y = 0; y < n; y++) {
      for (int x = 0; x < n; x++) {
        if (y >= t && f[y - t][x] == 'S') continue;
        if (y >= (t - 1) && f[y - (t - 1)][x] == 'S') continue;
        for (int z = 0; z < 8; z++) {
          int xx = x + dx[z], yy = y + dy[z];
          if (xx < 0 || xx >= n || yy < 0 || yy >= n) continue;
          if (ok[yy][xx][t - 1]) {
            ok[y][x][t] = 1;
            win = 1;
          }
        }
      }
    }
    if (!win) {
      cout << "LOSE\n";
      return 0;
    }
  }
  cout << "WIN\n";
  return 0;
}
