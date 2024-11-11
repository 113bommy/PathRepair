#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
const int dx[] = {-2, -2, -1, -1, 1, 1, 2, 2};
const int dy[] = {-1, 1, -2, 2, -2, 2, -1, 1};
int dis[2][N][N];
pair<int, int> from[2][N][N];
pair<int, int> q[N * N], W, B;
int n, m;
void SSSP(int fl, int sx, int sy) {
  for (int i = (int)(1); i <= (int)(n); i++)
    for (int j = (int)(1); j <= (int)(m); j++) dis[fl][i][j] = -1;
  int h = 0, t = 1;
  q[1] = pair<int, int>(sx, sy);
  dis[fl][sx][sy] = 0;
  while (h != t) {
    int x = q[++h].first, y = q[h].second;
    for (int d = (int)(0); d <= (int)(7); d++) {
      int nx = x + dx[d], ny = y + dy[d];
      if (nx < 1 || nx > n || ny < 1 || ny > m || dis[fl][nx][ny] != -1)
        continue;
      from[fl][nx][ny] = pair<int, int>(x, y);
      dis[fl][nx][ny] = dis[fl][x][y] + 1;
      q[++t] = pair<int, int>(nx, ny);
    }
  }
}
pair<int, int> get() {
  int x, y;
  scanf("%d %d", &x, &y);
  return pair<int, int>(x, y);
}
void output(pair<int, int> x) {
  printf("%d %d\n", x.first, x.second);
  fflush(stdout);
}
void check() {
  for (int i = (int)(0); i <= (int)(7); i++)
    if (W.first + dx[i] == B.first)
      if (W.second + dy[i] == B.second) {
        output(B);
        exit(0);
      }
}
void solve1(int fl) {
  puts(fl ? "BLACK" : "WHITE");
  fflush(stdout);
  if (fl) W = B, B = get();
  check();
  for (;;) {
    if (!dis[fl][W.first][W.second]) exit(0);
    output(W = from[fl][W.first][W.second]);
    if (!dis[fl][W.first][W.second]) exit(0);
    B = get();
    check();
  }
}
void solve2(int fl) {
  puts(fl ? "BLACK" : "WHITE");
  fflush(stdout);
  if (fl) W = B, B = get();
  check();
  for (;;) {
    if (!dis[fl ^ 1][W.first][W.second]) break;
    output(W = from[fl ^ 1][W.first][W.second]);
    B = get();
    check();
  }
  output(W = pair<int, int>(W.first + (fl ? 1 : -1), W.second - 2));
  B = get();
  check();
  output(W = pair<int, int>(W.first - 2, W.second + 1));
  B = get();
  check();
  output(W = pair<int, int>(W.first + 2, W.second + 1));
  exit(0);
}
int main() {
  scanf("%d%d", &n, &m);
  W = get();
  B = get();
  SSSP(0, n / 2, m / 2);
  SSSP(1, n / 2 + 1, m / 2);
  if ((W.first + B.first + W.second + B.second) & 1) {
    if (dis[0][W.first][W.second] <= dis[1][B.first][B.second]) solve1(0);
    if (dis[1][W.first][W.second] >= dis[1][B.first][B.second] + 2) solve1(1);
    solve2(0);
  } else {
    if (dis[0][W.first][W.second] - 1 >= dis[1][B.first][B.second]) solve1(1);
    if (dis[0][W.first][W.second] <= dis[0][B.first][B.second] + 1) solve1(0);
    solve2(1);
  }
}
