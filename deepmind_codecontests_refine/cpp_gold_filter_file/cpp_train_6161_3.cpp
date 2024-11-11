#include <bits/stdc++.h>
using namespace std;
const int dx[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
const int dy[8] = {-1, 1, -2, 2, -2, 2, -1, 1};
int n, m;
int xw, yw, xb, yb;
int xtw, ytw, xtb, ytb;
deque<pair<int, int>> ww, wb, bw, bb;
int dist[1000][1000], parx[1000][1000], pary[1000][1000];
int crap;
void shortestWay(int sx, int sy, int tx, int ty, deque<pair<int, int>> &res) {
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j) dist[i][j] = -1;
  dist[sx][sy] = 0;
  queue<pair<int, int>> q;
  q.push({sx, sy});
  while (!q.empty()) {
    int x = q.front().first, y = q.front().second;
    q.pop();
    if (x == tx && y == ty) break;
    for (int i = 0; i < 8; ++i) {
      int xx = x + dx[i], yy = y + dy[i];
      if (xx < 0 || yy < 0 || xx >= n || yy >= m) continue;
      if (dist[xx][yy] == -1) {
        dist[xx][yy] = dist[x][y] + 1;
        parx[xx][yy] = x, pary[xx][yy] = y;
        q.push({xx, yy});
      }
    }
  }
  int cx = tx, cy = ty;
  while (cx != sx || cy != sy) {
    res.push_front({cx, cy});
    int ccx = parx[cx][cy];
    cy = pary[cx][cy];
    cx = ccx;
  }
}
void normal(deque<pair<int, int>> &way, int ox, int oy) {
  for (int i = 0; i < way.size(); ++i) {
    cout << way[i].first + 1 << " " << way[i].second + 1 << "\n" << flush;
    if (way[i].first == ox && way[i].second == oy) exit(0);
    if (i < way.size() - 1) {
      cin >> ox >> oy;
      ox--;
      oy--;
    }
  }
}
void normalWhite() {
  cout << "WHITE\n" << flush;
  normal(ww, xb, yb);
}
void normalBlack() {
  cout << "BLACK\n" << flush;
  cin >> xw >> yw;
  xw--;
  yw--;
  normal(bb, xw, yw);
}
void advanced(deque<pair<int, int>> &way, int x, int y, int tx, int ty, int ox,
              int oy) {
  if (way.size() > 0) {
    normal(way, ox, oy);
    cin >> ox >> oy;
    ox--;
    oy--;
    x = way.back().first, y = way.back().second;
  }
  for (int i = 0; i < 8; ++i) {
    int xx = x + dx[i], yy = y + dy[i];
    if (xx == ox && yy == oy) {
      cout << xx + 1 << " " << yy + 1 << "\n" << flush;
      exit(0);
    }
  }
  deque<pair<int, int>> d;
  if (tx > x) {
    d.push_back({x + 1, y + 2});
    d.push_back({x + 3, y + 1});
    d.push_back({x + 1, y});
  } else {
    d.push_back({x - 1, y + 2});
    d.push_back({x - 3, y + 1});
    d.push_back({x - 1, y});
  }
  normal(d, ox, oy);
}
void advancedWhite() {
  cout << "WHITE\n" << flush;
  advanced(wb, xw, yw, xtw, ytw, xb, yb);
}
void advancedBlack() {
  cout << "BLACK\n" << flush;
  cin >> xw >> yw;
  xw--;
  yw--;
  advanced(bw, xb, yb, xtb, ytb, xw, yw);
}
int main() {
  cin >> n >> m >> xw >> yw >> xb >> yb;
  xw--;
  yw--;
  xb--;
  yb--;
  xtw = n / 2 - 1;
  ytw = m / 2 - 1;
  xtb = n / 2;
  ytb = m / 2 - 1;
  shortestWay(xw, yw, xtw, ytw, ww);
  shortestWay(xw, yw, xtb, ytb, wb);
  shortestWay(xb, yb, xtw, ytw, bw);
  shortestWay(xb, yb, xtb, ytb, bb);
  if ((xw + yw) % 2 != (xb + yb) % 2) {
    if (ww.size() <= bb.size())
      normalWhite();
    else if (wb.size() >= bb.size() + 2)
      normalBlack();
    else
      advancedWhite();
  } else {
    if (bb.size() < ww.size())
      normalBlack();
    else if (bw.size() > ww.size())
      normalWhite();
    else
      advancedBlack();
  }
}
