#include <bits/stdc++.h>
using namespace std;
int tx[8] = {1, 2, 2, 1, -1, -2, -2, -1}, ty[8] = {2, 1, -1, -2, -2, -1, 1, 2},
    d1[2010][2010], d2[2010][2010], n, m;
struct no {
  int x, y;
};
queue<no> q;
void bfs(int x, int y, int d[][2010]) {
  q.push((no){x, y});
  d[x][y] = 0;
  while (!q.empty()) {
    no x = q.front();
    q.pop();
    for (int i = 0; i < 8; i++) {
      int xx = tx[i] + x.x, yy = ty[i] + x.y;
      if (xx < 1 || xx > n || yy < 1 || yy > m || d[xx][yy] < 1e9) continue;
      q.push((no){xx, yy});
      d[xx][yy] = d[x.x][x.y] + 1;
    }
  }
}
void dfs(int x, int y, int d[][2010]) {
  for (int i = 0; i < 8; i++) {
    int xx = x + tx[i], yy = y + ty[i];
    if (xx < 1 || xx > n || yy < 1 || yy > m || d[xx][yy] >= d[x][y]) continue;
    cout << xx << ' ' << yy << endl;
    dfs(xx, yy, d);
    break;
  }
}
int main() {
  memset(d1, 127, sizeof(d1));
  memset(d2, 127, sizeof(d2));
  cin >> n >> m;
  int x1, y1, x2, y2;
  cin >> x1 >> y1 >> x2 >> y2;
  bfs(n / 2, m / 2, d1);
  bfs(n / 2 + 1, m / 2, d2);
  int wd = d1[x1][y1], bd = d2[x2][y2], wp = d2[x1][y1], bp = d1[x2][y2];
  if (((x1 + y1) & 1) == ((x2 + y2) & 1)) {
    if (bd < wd) {
      puts("BLACK");
      dfs(x2, y2, d2);
    } else if (bp - 1 < wd) {
      puts("BLACK");
      dfs(x2, y2, d1);
      dfs(n / 2, m / 2, d2);
    } else {
      puts("WHITE");
      dfs(x1, y1, d1);
    }
  } else {
    if (wd <= bd) {
      puts("WHITE");
      dfs(x1, y1, d1);
    } else if (wp - 1 <= bd) {
      puts("WHITE");
      dfs(x1, y1, d1);
      dfs(n / 2 + 1, m / 2, d2);
    } else {
      puts("BLACK");
      dfs(x2, y2, d2);
    }
  }
}
