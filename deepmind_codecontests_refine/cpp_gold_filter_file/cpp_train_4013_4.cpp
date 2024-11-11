#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1.0);
uint8_t rot[256];
uint8_t lab[4][1002][1002];
uint8_t vis[4][1002][1002];
long long xm, ym;
struct point {
  long long x, y, z, t;
  point(long long _z, long long _x, long long _y, long long _t)
      : x(_x), y(_y), z(_z), t(_t) {}
};
queue<point> q;
void prep() {
  rot['+'] = '+';
  rot['-'] = '|';
  rot['|'] = '-';
  rot['^'] = '>';
  rot['>'] = 'v';
  rot['v'] = '<';
  rot['<'] = '^';
  rot['L'] = 'U';
  rot['U'] = 'R';
  rot['R'] = 'D';
  rot['D'] = 'L';
  rot['*'] = '*';
}
bool has_left(uint8_t c) {
  if (c == '+' || c == '-' || c == '<' || c == 'U' || c == 'R' || c == 'D')
    return true;
  return false;
}
bool has_right(uint8_t c) {
  if (c == '+' || c == '-' || c == '>' || c == 'U' || c == 'L' || c == 'D')
    return true;
  return false;
}
bool has_up(uint8_t c) {
  if (c == '+' || c == '|' || c == '^' || c == 'L' || c == 'R' || c == 'D')
    return true;
  return false;
}
bool has_down(uint8_t c) {
  if (c == '+' || c == '|' || c == 'v' || c == 'L' || c == 'R' || c == 'U')
    return true;
  return false;
}
bool check(long long x, long long y) {
  if (x == xm && y == ym) return true;
  return false;
}
void add(point p) {
  if (vis[p.z][p.x][p.y]) return;
  q.push(p);
  vis[p.z][p.x][p.y] = 1;
}
int main() {
  long long n, m, i, j, k, res = -1;
  long long xt, yt;
  prep();
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m;
  for (i = 1; i <= n; i++) {
    string s;
    cin >> s;
    for (j = 0; j < m; j++) {
      for (k = 0; k < 4; k++) {
        lab[k][i][j + 1] = s[j];
        s[j] = rot[s[j]];
      }
    }
  }
  cin >> xt >> yt;
  cin >> xm >> ym;
  add(point(0, xt, yt, 0));
  while (!q.empty()) {
    point p = q.front();
    q.pop();
    if (check(p.x, p.y)) {
      res = p.t;
      break;
    }
    if (has_up(lab[p.z][p.x][p.y]) && has_down(lab[p.z][p.x - 1][p.y]))
      add(point(p.z, p.x - 1, p.y, p.t + 1));
    if (has_right(lab[p.z][p.x][p.y]) && has_left(lab[p.z][p.x][p.y + 1]))
      add(point(p.z, p.x, p.y + 1, p.t + 1));
    if (has_left(lab[p.z][p.x][p.y]) && has_right(lab[p.z][p.x][p.y - 1]))
      add(point(p.z, p.x, p.y - 1, p.t + 1));
    if (has_down(lab[p.z][p.x][p.y]) && has_up(lab[p.z][p.x + 1][p.y]))
      add(point(p.z, p.x + 1, p.y, p.t + 1));
    p.z = (p.z + 1) % 4;
    p.t++;
    add(p);
  }
  cout << res << "\n";
  return 0;
}
