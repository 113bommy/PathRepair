#include <bits/stdc++.h>
using namespace std;
const long double eps = 1e-9;
const int inf = (1 << 30) - 1;
const long long inf64 = ((long long)1 << 62) - 1;
const long double pi = 3.1415926535897932384626433832795;
template <class T>
T sqr(T x) {
  return x * x;
}
template <class T>
T abs(T x) {
  return x < 0 ? -x : x;
}
const int nmax = 300;
const int qmax = 1e6 + 1e5;
int px[] = {-1, 0, 1, 0};
int py[] = {0, -1, 0, 1};
char ch[] = {'L', 'D', 'R', 'U'};
int vx, vy, sx, sy;
int a[nmax][nmax];
int used[nmax][nmax];
char res[qmax];
int m, M;
int x[nmax * nmax], y[nmax * nmax];
void no() {
  puts("-1");
  exit(0);
}
void move(int &x, int &y, int id) {
  int nx = x + px[id];
  int ny = y + py[id];
  if (nx >= 0 && ny >= 0 && nx < nmax && ny < nmax && a[nx][ny] == 1) return;
  x = nx;
  y = ny;
}
void move(int id) {
  move(vx, vy, id);
  move(sx, sy, id);
  res[m++] = ch[id];
}
bool move(int x, int y, int wx, int wy) {
  if (make_pair(x, y) == make_pair(wx, wy)) return 1;
  used[x][y] = 1;
  for (int i = 0; i < (int)(4); i++) {
    int nx = x + px[i];
    int ny = y + py[i];
    if (nx >= 0 && ny >= 0 && nx < nmax && ny < nmax && a[nx][ny] == 0 &&
        !used[nx][ny]) {
      pair<int, int> o1, o2;
      o1 = make_pair(vx, vy);
      o2 = make_pair(sx, sy);
      move(i);
      if (move(nx, ny, wx, wy)) return 1;
      vx = o1.first;
      vy = o1.second;
      sx = o2.first;
      sy = o2.second;
      res[m] = 0;
      m--;
    }
  }
  return 0;
}
void dfs(int x, int y) {
  used[x][y] = 1;
  for (int i = 0; i < (int)(4); i++) {
    int nx = x + px[i];
    int ny = y + py[i];
    if (nx >= 0 && ny >= 0 && nx < nmax && ny < nmax && a[nx][ny] == 0 &&
        !used[nx][ny])
      dfs(nx, ny);
  }
}
void Gmove(int x, int y, int sx, int sy) {
  while (1) {
    bool upd = 0;
    for (int i = 0; i < (int)(4); i++) {
      int nx = x + px[i];
      int ny = y + py[i];
      if (abs(x - sx) >= abs(nx - sx) && abs(y - sy) >= abs(ny - sy)) {
        move(i);
        upd = 1;
        x = nx;
        y = ny;
      }
    }
    if (!upd) break;
  }
}
int main() {
  cin >> vx >> vy >> sx >> sy;
  vx += 150;
  vy += 150;
  sx += 150;
  sy += 150;
  m = 0;
  cin >> M;
  for (int i = 0; i < (int)(M); i++) {
    cin >> x[i] >> y[i];
    x[i] += 150;
    y[i] += 150;
    a[x[i]][y[i]] = 1;
  }
  if (make_pair(vx, vy) == make_pair(sx, sy)) {
    exit(0);
  }
  if (M == 0) no();
  dfs(vx, vy);
  if (!used[sx][sy]) no();
  m = 0;
  pair<int, int> pos = make_pair(nmax, nmax);
  for (int i = 0; i < (int)(nmax); i++)
    for (int j = 0; j < (int)(nmax); j++)
      if (used[i][j]) pos = min(pos, make_pair(i, j));
  if (pos != make_pair(0, 0)) {
    while (make_pair(vx, vy) != make_pair(sx, sy)) {
      memset(used, 0, sizeof used);
      move(vx, vy, sx, sy);
    }
    cout << res << endl;
    exit(0);
  }
  memset(used, 0, sizeof used);
  move(vx, vy, 0, 0);
  for (int i = 0; i < (int)(500); i++) move(0);
  for (int i = 0; i < (int)(500); i++) move(1);
  if (sy > nmax)
    for (int i = 0; i < (int)(500); i++) move(0);
  if (sx > nmax)
    for (int i = 0; i < (int)(500); i++) move(1);
  if (sx >= 0 && sy >= 0) {
    memset(used, 0, sizeof used);
    move(sx, sy, 0, 0);
  }
  if (sy <= 0)
    for (int i = 0; i < (int)(500); i++) move(0);
  if (sx <= 0)
    for (int i = 0; i < (int)(500); i++) move(1);
  assert(sx <= 0 && sy <= 0 && vx <= 0 && vy <= 0);
  if (vx < sx) {
    pair<int, int> now = make_pair(nmax, nmax);
    for (int i = 0; i < (int)(M); i++)
      if (x[i] < now.first) now = make_pair(x[i], y[i]);
    Gmove(sx, sy, now.first - 1, now.second);
    while (vx != sx) move(2);
  }
  if (vx > sx) {
    pair<int, int> now = make_pair(-nmax, nmax);
    for (int i = 0; i < (int)(M); i++)
      if (x[i] > now.first) now = make_pair(x[i], y[i]);
    while (sx < nmax || vx < nmax) move(2);
    Gmove(sx, sy, now.first + 1, now.second);
    while (vx != sx) move(0);
  }
  for (int i = 0; i < (int)(500); i++) {
    move(1);
  }
  for (int i = 0; i < (int)(500); i++) {
    move(0);
  }
  if (vy < sy) {
    pair<int, int> now = make_pair(nmax, nmax);
    for (int i = 0; i < (int)(M); i++)
      if (y[i] < now.second) now = make_pair(x[i], y[i]);
    Gmove(sx, sy, now.first, now.second - 1);
    while (vy != sy) move(3);
  }
  if (vy > sy) {
    pair<int, int> now = make_pair(-nmax, -nmax);
    for (int i = 0; i < (int)(M); i++)
      if (y[i] > now.second) now = make_pair(x[i], y[i]);
    while (sy < nmax || vy < nmax) move(3);
    Gmove(sx, sy, now.first, now.second + 1);
    while (vy != sy) move(1);
  }
  cout << res << endl;
  return 0;
}
