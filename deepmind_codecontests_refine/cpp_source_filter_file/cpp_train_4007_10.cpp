#include <bits/stdc++.h>
using namespace std;
const double EPS = 1e-9;
const int INF = INT_MAX / 4;
bool board[1010][1010];
int dx[4][3] = {{1, 1, 0}, {1, 1, 0}, {-1, -1, 0}, {-1 - 1, 0}};
int dy[4][3] = {{0, -1, -1}, {0, 1, 1}, {0, -1, -1}, {0, 1, 1}};
int main(int argc, char const *argv[]) {
  int n, m, k, ans = -1;
  cin >> n >> m >> k;
  for (int i = 0; i < 1001; i++) {
    for (int j = 0; j < 1001; j++) {
      board[i][j] = false;
    }
  }
  vector<int> xx(k), yy(k);
  for (int i = 0; i < k; i++) {
    cin >> yy[i] >> xx[i];
  }
  for (int casen = 0; casen < k; casen++) {
    int x = xx[casen], y = yy[casen];
    board[y][x] = 1;
    bool flag = 0;
    for (int i = 0; i < 4; i++) {
      int cnt = 0;
      for (int j = 0; j < 3; j++) {
        int nx = x + dx[i][j], ny = y + dy[i][j];
        if (board[ny][nx]) cnt++;
      }
      if (cnt == 3) {
        flag = 1;
        break;
      }
    }
    if (flag) {
      ans = casen + 1;
      break;
    }
  }
  if (ans == -1) ans = 0;
  cout << ans << endl;
  return 0;
}
