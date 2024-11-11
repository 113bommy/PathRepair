#include <bits/stdc++.h>
using namespace std;
struct po {
  int x;
  int y;
  int ans;
  int tu;
  po(void) {
    x = 0;
    y = 0;
    ans = 3;
    tu = 0;
  }
  po(int tx, int ty, int ta, int tt) {
    x = tx;
    y = ty;
    ans = ta;
    tu = tt;
  }
};
char t[1010][1010];
int dp[1010][1010];
int turn[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
int n, m, sx, sy, tx, ty;
int main(void) {
  ios::sync_with_stdio(false);
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> t[i][j];
      dp[i][j] = 3;
      if (t[i][j] == 'S') {
        dp[i][j] = 0;
        sx = i;
        sy = j;
      } else if (t[i][j] == 'T') {
        tx = i;
        ty = j;
      }
    }
  }
  queue<po> bfs;
  for (int i = 0; i < 4; i++) {
    if (sx + turn[i][0] >= 0 && sx + turn[i][0] < n && sy + turn[i][1] >= 0 &&
        sy + turn[i][1] < m && t[sx + turn[i][0]][sy + turn[i][1]] != '*') {
      bfs.push(po(sx + turn[i][0], sy + turn[i][1], 0, i));
    }
  }
  while (!bfs.empty()) {
    bool changed = false;
    if (dp[bfs.front().x][bfs.front().y] > bfs.front().ans) {
      dp[bfs.front().x][bfs.front().y] = bfs.front().ans;
      changed = true;
    }
    if (bfs.front().ans <= 2 && changed) {
      for (int i = 0; i < 4; i++) {
        if (bfs.front().x + turn[i][0] >= 0 && bfs.front().x + turn[i][0] < n &&
            bfs.front().y + turn[i][1] >= 0 && bfs.front().y + turn[i][1] < m &&
            t[bfs.front().x + turn[i][0]][bfs.front().y + turn[i][1]] != '*') {
          bfs.push(po(bfs.front().x + turn[i][0], bfs.front().y + turn[i][1],
                      bfs.front().ans + (i != bfs.front().tu), i));
        }
      }
    }
    bfs.pop();
  }
  if (dp[tx][ty] <= 2) {
    cout << "YES";
  } else {
    cout << "NO";
  }
  return 0;
}
