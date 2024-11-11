#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
int dis1[N][N], dis2[N][N], x1, ___y1, x2, y2, n, m;
int dx[8] = {1, -1, 2, -2, 1, -1, 2, -2}, dy[8] = {2, 2, 1, 1, -2, -2, -1, -1};
queue<pair<int, int> > Q;
void bfs1(int x, int y) {
  Q.push(make_pair(x, y));
  dis1[x][y] = 1;
  while (!Q.empty()) {
    pair<int, int> now = Q.front();
    Q.pop();
    for (int i = 0; i < 8; i++) {
      pair<int, int> t = make_pair(now.first + dx[i], now.second + dy[i]);
      if (t.first > 0 && t.first <= n && t.second > 0 && t.second <= m &&
          !dis1[t.first][t.second]) {
        Q.push(t);
        dis1[t.first][t.second] = dis1[now.first][now.second] + 1;
      }
    }
  }
}
void bfs2(int x, int y) {
  Q.push(make_pair(x, y));
  dis2[x][y] = 1;
  while (!Q.empty()) {
    pair<int, int> now = Q.front();
    Q.pop();
    for (int i = 0; i < 8; i++) {
      pair<int, int> t = make_pair(now.first + dx[i], now.second + dy[i]);
      if (t.first > 0 && t.first <= n && t.second > 0 && t.second <= m &&
          !dis2[t.first][t.second]) {
        Q.push(t);
        dis2[t.first][t.second] = dis2[now.first][now.second] + 1;
      }
    }
  }
}
void dfs1(int x, int y) {
  for (int i = 0; i < 8; i++) {
    int tx = dx[i] + x, ty = dy[i] + y;
    if (tx > 0 && ty > 0 && tx <= n && ty <= m && dis1[tx][ty] < dis1[x][y]) {
      printf("%d %d\n", tx, ty);
      dfs1(tx, ty);
      return;
    }
  }
}
void dfs2(int x, int y) {
  for (int i = 0; i < 8; i++) {
    int tx = dx[i] + x, ty = dy[i] + y;
    if (tx > 0 && ty > 0 && tx <= n && ty <= m && dis2[tx][ty] < dis2[x][y]) {
      printf("%d %d\n", tx, ty);
      dfs2(tx, ty);
      return;
    }
  }
}
int main() {
  scanf("%d%d%d%d%d%d", &n, &m, &x1, &___y1, &x2, &y2);
  bfs1(n / 2, m / 2);
  bfs2(n / 2 + 1, m / 2);
  int D1 = dis1[x1][___y1], D2 = dis2[x2][y2];
  int D3 = dis2[x1][___y1], D4 = dis1[x2][y2];
  if ((x1 + ___y1) % 2 == (x2 + y2) % 2) {
    if (D1 > D2)
      puts("BLACK"), dfs2(x2, y2);
    else if (D4 <= D1) {
      puts("BLACK");
      dfs1(x2, y2);
      dfs2(n / 2, m / 2);
    } else {
      puts("WHITE");
      dfs1(x1, ___y1);
    }
  } else {
    if (D1 <= D2)
      puts("WHITE"), dfs1(x1, ___y1);
    else if (D3 - 1 <= D2) {
      puts("WHITE");
      dfs2(x1, ___y1);
      dfs1(n / 2 + 1, m / 2);
    } else {
      puts("BLACK");
      dfs2(x2, y2);
    }
  }
  return 0;
}
