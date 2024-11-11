#include <bits/stdc++.h>
using namespace std;
const int dx[8] = {-2, -1, 1, 2, 2, 1, -1, -2},
          dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};
struct Status {
  int i, j, k;
  Status() { i = j = k = 0; }
  Status(int a, int b, int c) { i = a, j = b, k = c; }
};
inline bool operator<(pair<int, int> a, pair<int, int> b) {
  if (b.first == -1) return true;
  if (a.first != b.first) return a.first < b.first;
  return a.second < b.second;
}
int n;
int a[15][15];
inline int P(int x, int y) { return (x - 1) * n + y; }
pair<int, int> dp[105][105][5];
queue<Status> Q;
inline bool inBoard(int x, int y) {
  return (x >= 1 && x <= n && y >= 1 && y <= n);
}
pair<int, int> val;
inline void Push(int p, int nx, int ny, int ch) {
  if (a[nx][ny] == p + 1) {
    if (dp[p + 1][P(nx, ny)][ch].first == -1)
      Q.push(Status(p + 1, P(nx, ny), ch));
    if (val < dp[p + 1][P(nx, ny)][ch]) dp[p + 1][P(nx, ny)][ch] = val;
  } else {
    if (dp[p][P(nx, ny)][ch].first == -1) Q.push(Status(p, P(nx, ny), ch));
    if (val < dp[p][P(nx, ny)][ch]) dp[p][P(nx, ny)][ch] = val;
  }
}
int main() {
  scanf("%d", &n);
  int sx, sy, tx, ty;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) {
      scanf("%d", &a[i][j]);
      if (a[i][j] == 1) sx = i, sy = j;
      if (a[i][j] == n * n) tx = i, ty = j;
    }
  for (int i = 1; i <= n * n; i++)
    for (int j = 1; j <= n * n; j++)
      for (int k = 1; k <= 3; k++) dp[i][j][k].first = -1;
  dp[1][P(sx, sy)][1] = pair<int, int>(0, 0);
  dp[1][P(sx, sy)][2] = pair<int, int>(0, 0);
  dp[1][P(sx, sy)][3] = pair<int, int>(0, 0);
  Q.push(Status(1, P(sx, sy), 1));
  Q.push(Status(1, P(sx, sy), 2));
  Q.push(Status(1, P(sx, sy), 3));
  while (!Q.empty()) {
    Status tmp = Q.front();
    Q.pop();
    int p = tmp.i, x = (tmp.j - 1) / n + 1, y = (tmp.j - 1) % n + 1, ch = tmp.k;
    val = dp[p][P(x, y)][ch];
    val.first++, val.second++;
    for (int i = 1; i <= 3; i++) {
      if (ch == i) continue;
      if (dp[p][P(x, y)][i].first == -1) Q.push(Status(p, P(x, y), i));
      if (val < dp[p][P(x, y)][i]) dp[p][P(x, y)][i] = val;
    }
    val.second--;
    if (ch == 1)
      for (int i = 0; i < 8; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if (!inBoard(nx, ny)) continue;
        Push(p, nx, ny, ch);
      }
    if (ch == 2) {
      for (int i = -n; i <= n; i++) {
        int nx = x + i, ny = y + i;
        if (!inBoard(nx, ny)) continue;
        Push(p, nx, ny, ch);
      }
      for (int i = -n; i <= n; i++) {
        int nx = x - i, ny = y + i;
        if (!inBoard(nx, ny)) continue;
        Push(p, nx, ny, ch);
      }
    }
    if (ch == 3) {
      for (int i = -n; i <= n; i++) {
        int nx = x + i, ny = y;
        if (!inBoard(nx, ny)) continue;
        Push(p, nx, ny, ch);
      }
      for (int i = -n; i <= n; i++) {
        int nx = x, ny = y + i;
        if (!inBoard(nx, ny)) continue;
        Push(p, nx, ny, ch);
      }
    }
  }
  pair<int, int> ans = pair<int, int>(-1, 0);
  for (int i = 1; i <= 3; i++)
    if (dp[n * n][P(tx, ty)][i] < ans) ans = dp[n * n][P(tx, ty)][i];
  printf("%d %d\n", ans.first, ans.second);
  return 0;
}
