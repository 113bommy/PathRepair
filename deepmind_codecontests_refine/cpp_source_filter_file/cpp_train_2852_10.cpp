#include <bits/stdc++.h>
using namespace std;
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
const int maxn = 1000;
const int maxx = 640;
const int minx = 20;
const int x_shft = 330, y_shft = x_shft;
bool A[maxn][maxn];
bool used[maxn][maxn];
pair<int, int> Q[maxn * maxn];
pair<int, int> P[maxn][maxn];
vector<pair<int, int> > tree;
string move_to(int sx, int sy, int fx, int fy) {
  memset(used, false, sizeof(used));
  used[sx][sy] = true;
  int l = 0, r = 0;
  Q[0] = make_pair(sx, sy);
  while (l <= r) {
    int x = Q[l].first, y = Q[l++].second;
    if (x == fx && y == fy) {
      break;
    }
    for (int i = 0; i < 4; ++i) {
      int sx = x + dx[i];
      int sy = y + dy[i];
      if (sx < 0 || sy < 0 || sx >= maxn || sy >= maxn || A[sx][sy] ||
          used[sx][sy]) {
        continue;
      }
      used[sx][sy] = true;
      P[sx][sy] = make_pair(x, y);
      Q[++r] = make_pair(sx, sy);
    }
  }
  string res;
  int x = fx, y = fy;
  while (used[fx][fy] && (x != sx || y != sy)) {
    int px = P[x][y].first, py = P[x][y].second;
    res += px < x ? 'R' : (px > x ? 'L' : (py < y ? 'U' : 'D'));
    x = px;
    y = py;
  }
  reverse(res.begin(), res.end());
  return res;
}
string shadow_move(int &x, int &y, string act) {
  string res;
  for (int i = 0; i < (int)act.size(); ++i) {
    switch (act[i]) {
      case 'L':
        if (!A[x - 1][y]) {
          --x;
          res += 'L';
        }
        break;
      case 'R':
        if (!A[x + 1][y]) {
          ++x;
          res += 'R';
        }
        break;
      case 'U':
        if (!A[x][y + 1]) {
          ++y;
          res += 'U';
        }
        break;
      case 'D':
        if (!A[x][y - 1]) {
          --y;
          res += 'D';
        }
        break;
    }
  }
  return res;
}
void solve1(int vx, int vy, int sx, int sy) {
  string acts = move_to(vx, vy, maxx, maxx);
  string res = acts;
  shadow_move(sx, sy, acts);
  vx = maxx;
  vy = maxx;
  int ix = 1, iy = 1;
  if (vx < sx) {
    acts = move_to(vx, vy, minx, vy);
    vx = minx;
    res += acts;
    shadow_move(sx, sy, acts);
    ix = -1;
  }
  if (vy < sy) {
    acts = move_to(vx, vy, vx, minx);
    vy = minx;
    res += acts;
    shadow_move(sx, sy, acts);
    iy = -1;
  }
  int px = -ix * 100500, py = -iy * 100500;
  for (int i = 0; i < (int)tree.size(); ++i) {
    if (ix * tree[i].first > ix * px ||
        (tree[i].first == px && iy * tree[i].second > iy * py)) {
      px = tree[i].first;
      py = tree[i].second;
    }
  }
  acts = move_to(sx, sy, px, py + iy);
  sx = px;
  sy = py + iy;
  shadow_move(vx, vy, acts);
  res += acts;
  res += move_to(vx, vy, vx, py + iy);
  vy = py + iy;
  acts = move_to(sx, sy, px + ix, py);
  sx = px + ix;
  sy = py;
  shadow_move(vx, vy, acts);
  res += acts;
  res += move_to(vx, vy, px + ix, vy);
  vx = px + ix;
  cout << res << endl;
  assert(vx == sx && vy == sy);
}
void solve2(int vx, int vy, int sx, int sy) {
  string acts = move_to(vx, vy, sx, sy);
  string res = acts;
  while (vx != sx || vy != sy) {
    vx = sx;
    vy = sy;
    acts = shadow_move(sx, sy, acts);
    res += acts;
    assert((int)res.size() < 1000 * 1000);
  }
  cout << res << endl;
}
int main() {
  int vx, vy, sx, sy, m;
  cin >> vx >> vy >> sx >> sy >> m;
  vx += x_shft;
  vy += y_shft;
  sx += x_shft;
  sy += y_shft;
  for (int i = 0; i < m; ++i) {
    int x, y;
    cin >> x >> y;
    tree.push_back(make_pair(x + x_shft, y + y_shft));
    A[x + x_shft][y + y_shft] = true;
  }
  if (!m || !move_to(vx, vy, sx, sy).size()) {
    cout << "-1\n";
    return 0;
  }
  if (move_to(vx, vy, maxx, maxx).size()) {
    solve1(vx, vy, sx, sy);
  } else {
    solve2(vx, vy, sx, sy);
  }
  return 0;
}
