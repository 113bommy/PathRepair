#include <bits/stdc++.h>
using namespace std;
bool paper[1001][1001];
int n, m;
int dir[9][2] = {0, -1, -1, -1, -1, 0, -1, 1, 0, 1, 1, 1, 1, 0, 1, -1, 0, 0};
bool check(int row, int col) {
  bool ans = false;
  for (int i = 0; i < 9 && !ans; i++) {
    int x = col + dir[i][0], y = row + dir[i][1];
    if (x > 0 && x < n - 1 && y > 0 && y < n - 1 && paper[y][x] == true) {
      ans = true;
      for (int k = 0; k < 8; k++) {
        int xx = dir[k][0] + x, yy = dir[k][1] + y;
        if (!paper[yy][xx]) {
          ans = false;
          break;
        }
      }
    }
  }
  return ans;
}
int main() {
  cin >> n >> m;
  int x, y, ans = -1;
  for (int i = 1; i <= m; i++) {
    cin >> y >> x;
    if (ans == -1) {
      paper[y - 1][x - 1] = true;
      if (i > 8 && check(y - 1, x - 1)) ans = i;
    }
  }
  cout << ans << endl;
  return 0;
}
