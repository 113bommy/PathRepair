#include <bits/stdc++.h>
using namespace std;
const int dx[] = {-1, 0, 1};
const int dy[] = {3, 3, 3};
int n, k;
bool inRange(int x, int y) {
  if (x < 0 || x > 2) return false;
  if (y < 0 || y >= n) return false;
  return true;
}
int main() {
  int T;
  cin >> T;
  while (T--) {
    int s;
    string M[3];
    vector<bool> vst[3];
    cin >> n >> k;
    for (int i = 0; i < 3; i++) vst[i].resize(n);
    for (int i = 0; i < 3; i++) {
      cin >> M[i];
      if (M[i][0] == 's') s = i;
    }
    queue<int> que;
    que.push(s);
    que.push(0);
    bool YES = 0;
    while (!que.empty() && !YES) {
      int x = que.front();
      que.pop();
      int y = que.front();
      que.pop();
      if (!inRange(x, y)) continue;
      if (vst[x][y]) continue;
      vst[x][y] = 1;
      if ('A' <= M[x][y] && M[x][y] <= 'Z') continue;
      if (y == n - 1) {
        YES = 1;
        break;
      }
      for (int i = 0; i < 3; i++) {
        int xx = x;
        int yy = y + 1;
        if (!inRange(xx, yy)) continue;
        if ('A' <= M[xx][yy] && M[xx][yy] <= 'Z') continue;
        if (y == n - 1) {
          YES = 1;
          break;
        }
        xx += dx[i];
        if (!inRange(xx, yy)) continue;
        if ('A' <= M[xx][yy] && M[xx][yy] <= 'Z') continue;
        yy++;
        if (!inRange(xx, yy)) continue;
        if ('A' <= M[xx][yy] && M[xx][yy] <= 'Z') continue;
        if (y == n - 1) {
          YES = 1;
          break;
        }
        y++;
        que.push(xx);
        que.push(yy);
      }
    }
    if (YES)
      puts("YES");
    else
      puts("NO");
  }
}
