#include <bits/stdc++.h>
using namespace std;
const int MAXN = 400 + 10, D = 200;
const int d[4][2] = {{1, 0}, {0, 1}, {0, -1}, {-1, 0}};
const char type[4] = {'R', 'U', 'D', 'L'};
int g[MAXN][MAXN], pre[MAXN][MAXN], h[MAXN][MAXN];
int vx, vy, sx, sy, m, t[MAXN][2];
string CC;
void C(int g[][MAXN], int x, int y, int d) { g[x + D][y + D] = d; }
bool check(int nx, int ny) {
  return nx >= -D && nx <= D && ny >= -D && ny <= D;
}
int G(int g[][MAXN], int x, int y) {
  if (!check(x, y)) return 0;
  return g[x + D][y + D];
}
int head, tail, que[MAXN * MAXN * 10][2];
void BFS(int x, int y) {
  C(h, x, y, 1), C(pre, x, y, -1);
  head = 0, tail = 1;
  que[1][0] = x, que[1][1] = y;
  while (head < tail) {
    ++head;
    for (int i = 0; i < 4; ++i) {
      int nx = que[head][0] + d[i][0], ny = que[head][1] + d[i][1];
      if (check(nx, ny) && !G(g, nx, ny) && !G(h, nx, ny)) {
        C(h, nx, ny, 1);
        C(pre, nx, ny, 3 - i);
        que[++tail][0] = nx, que[tail][1] = ny;
      }
    }
  }
}
void init() {
  cin >> vx >> vy >> sx >> sy >> m;
  if (!m && !(vx == vy && sx == vy)) puts("-1"), exit(0);
  for (int i = 1; i <= m; ++i)
    cin >> t[i][0] >> t[i][1], C(g, t[i][0], t[i][1], 1);
  BFS(sx, sy);
}
static int q[MAXN * MAXN * 10], id[5];
int Go(int& a, int& b, int l) {
  if (l == -1) return -1;
  if (G(g, a + d[l][0], b + d[l][1])) return -1;
  a += d[l][0], b += d[l][1];
  return l;
}
void Push(int& ax, int& ay, int& bx, int& by, int l, int D, int ty) {
  for (int i = 1; i <= D; ++i) CC += type[l];
  ax += d[l][0] * D, ay += d[l][1] * D;
  if (!ty) bx += d[l][0] * D, by += d[l][1] * D;
}
void solve() {
  if (!G(h, vx, vy)) puts("-1"), exit(0);
  int ax = vx, ay = vy, bx = sx, by = sy;
  head = 0, tail = 0;
  for (; ax != bx || ay != by;) {
    if (G(pre, ax, ay) == -1) break;
    int l = Go(ax, ay, G(pre, ax, ay));
    if (Go(bx, by, l) != -1) q[++tail] = l;
    CC += type[l];
  }
  if (ax == bx && ay == by) cout << CC << endl, exit(0);
  for (; (ax != bx || ay != by) && check(ax, ay);) {
    int x = ++head, l = q[x];
    Go(ax, ay, l);
    if (Go(bx, by, l) != -1) q[++tail] = l;
    CC += type[l];
  }
  if (ax == bx && ay == by) cout << CC << endl, exit(0);
  for (int i = 1; i <= m; ++i) {
    if (!id[0] || t[id[0]][0] > t[i][0]) id[0] = i;
    if (!id[1] || t[id[1]][0] < t[i][0]) id[1] = i;
    if (!id[2] || t[id[2]][1] > t[i][1]) id[2] = i;
    if (!id[3] || t[id[3]][1] < t[i][1]) id[3] = i;
  }
  int tx = 0, ty = 0;
  if (ax > bx)
    tx = t[id[1]][0] + 1, ty = t[id[1]][1];
  else
    tx = t[id[0]][0] - 1, ty = t[id[0]][1];
  Push(ax, ay, bx, by, q[tail], MAXN * 2, 0);
  Push(ax, ay, bx, by, 1, MAXN, 0);
  if (bx < tx)
    Push(ax, ay, bx, by, 0, tx - bx, 0);
  else
    Push(ax, ay, bx, by, 3, bx - tx, 0);
  if (by < ty)
    Push(ax, ay, bx, by, 1, ty - by, 0);
  else
    Push(ax, ay, bx, by, 2, by - ty, 0);
  if (ax < bx)
    Push(ax, ay, bx, by, 0, bx - ax, 1);
  else
    Push(ax, ay, bx, by, 3, ax - bx, 1);
  if (ay > by)
    tx = t[id[3]][0], ty = t[id[3]][1] + 1;
  else
    tx = t[id[2]][0], ty = t[id[2]][1] - 1;
  if (ty > by)
    Push(ax, ay, bx, by, 1, ty - by, 0);
  else
    Push(ax, ay, bx, by, 2, by - ty, 0);
  if (tx > bx)
    Push(ax, ay, bx, by, 0, tx - bx, 0);
  else
    Push(ax, ay, bx, by, 3, bx - tx, 0);
  if (ay > by)
    Push(ax, ay, bx, by, 2, ay - by, 1);
  else
    Push(ax, ay, bx, by, 1, by - ay, 1);
  cout << CC << endl;
}
int main() {
  init();
  solve();
  fclose(stdin);
  fclose(stdout);
  return 0;
}
