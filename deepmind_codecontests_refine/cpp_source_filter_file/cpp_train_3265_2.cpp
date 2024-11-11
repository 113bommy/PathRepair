#include <bits/stdc++.h>
using namespace std;
const int mv[4][2] = {1, 0, -1, 0, 0, -1, 0, 1};
const int INF = 1000000000;
int n, m;
bool isJunction(char c) { return c <= 'z' && c >= 'a'; }
int bfs(const vector<string> &tag, char bc, char ec, int &ax, int &ay,
        const vector<string> &mat, int k) {
  int bx = -1, by = -1;
  for (int n_ = (n), i = 0; i < n_; ++i)
    for (int n_ = (m), j = 0; j < n_; ++j)
      if (tag[i][j] == bc) bx = i, by = j;
  assert(bx != -1 && by != -1);
  int ex = -1, ey = -1;
  for (int n_ = (n), i = 0; i < n_; ++i)
    for (int n_ = (m), j = 0; j < n_; ++j)
      if (tag[i][j] == ec) ex = i, ey = j;
  assert(ex != -1 && ey != -1);
  vector<vector<int> > d(n, vector<int>(m, INF));
  d[bx][by] = 0;
  queue<pair<int, int> > que;
  que.push(make_pair(bx, by));
  vector<vector<bool> > in(n, vector<bool>(m, false));
  in[bx][by] = true;
  vector<vector<pair<int, int> > > pre(
      n, vector<pair<int, int> >(m, make_pair(-1, -1)));
  for (; !que.empty(); que.pop()) {
    pair<int, int> &now = que.front();
    for (int n_ = (4), i = 0; i < n_; ++i) {
      int nx = now.first + mv[i][0], ny = now.second + mv[i][1];
      if (nx < n && nx >= 0 && ny < m && ny >= 0) {
        char c = mat[nx][ny];
        if (c != '#') {
          if (!isJunction(c) || c == ec) {
            int nc = isJunction(mat[now.first][now.second])
                         ? 1
                         : mat[now.first][now.second] - '0';
            if (d[now.first][now.second] + nc < d[nx][ny]) {
              d[nx][ny] = d[now.first][now.second] + nc;
              pre[nx][ny] = now;
              if (!in[nx][ny]) {
                que.push(make_pair(nx, ny));
              }
            }
          }
        }
      }
    }
    in[now.first][now.second] = false;
  }
  if (k <= d[ex][ey]) {
    pair<int, int> p = make_pair(ex, ey);
    while (p.first != -1) {
      if (k == d[p.first][p.second]) {
        ax = p.first, ay = p.second;
        break;
      }
      p = pre[p.first][p.second];
    }
  }
  assert(d[ex][ey] != INF);
  return d[ex][ey];
}
int main(int argc, char *argv[]) {
  int k;
  string route;
  cin >> n >> m >> k;
  vector<string> mat(n);
  for (int n_ = (n), i = 0; i < n_; ++i) cin >> mat[i];
  int bx, by, ex, ey;
  cin >> bx >> by >> route >> ex >> ey;
  bx--, by--, ex--, ey--;
  vector<string> tag = mat;
  tag[bx][by] = 'B', tag[ex][ey] = 'E';
  route = "B" + route + "E";
  for (int n_ = (route.size() - 1), i = 0; i < n_; ++i) {
    int ansx, ansy;
    k -= bfs(tag, route[i], route[i + 1], ansx, ansy, mat, k);
    if (k <= 0) {
      cout << ansx + 1 << " " << ansy + 1 << endl;
      break;
    }
  }
  if (k > 0) cout << ex + 1 << " " << ey + 1 << endl;
  return 0;
}
