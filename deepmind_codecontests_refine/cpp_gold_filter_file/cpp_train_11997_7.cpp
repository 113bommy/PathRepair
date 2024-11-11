#include <bits/stdc++.h>
using namespace std;
string a[55];
int m, n, len;
int X[4] = {-1, 0, 1, 0}, Y[4] = {0, 1, 0, -1};
int vis[55][55][4][2];
struct stage {
  int bp, dp, cp;
  int x, y, step;
};
bool legal(int x, int y) {
  return x > 0 && x <= m && y > 0 && y <= len && a[x][y - 1] != '0';
}
void move(stage &p) {
  int x = p.x, y = p.y, c = a[x][y - 1];
  int d1 = p.dp, d2 = (d1 + (p.cp ? 1 : -1) + 4) % 4;
  while (legal(x, y) && a[x][y - 1] == c) x += X[d1], y += Y[d1];
  x -= X[d1], y -= Y[d1];
  while (legal(x, y) && a[x][y - 1] == c) x += X[d2], y += Y[d2];
  x -= X[d2], y -= Y[d2];
  if (legal(x + X[d1], y + Y[d1])) {
    p.x = x + X[d1], p.y = y + Y[d1], p.bp = a[p.x][p.y - 1] - '0';
  } else {
    if (p.cp == 0)
      p.cp = 1;
    else
      p.cp = 0, (p.dp += 1) %= 4;
  }
  p.step++;
}
int main() {
  cin >> m >> n;
  for (int i = (1); i <= (m); i++) cin >> a[i];
  len = a[1].size();
  stage cur = {a[1][0] - '0', 1, 0, 1, 1, 1};
  while (!vis[cur.x][cur.y][cur.dp][cur.cp]) {
    if (cur.step == n + 1) {
      cout << cur.bp << endl;
      return 0;
    }
    vis[cur.x][cur.y][cur.dp][cur.cp] = cur.step, move(cur);
  }
  int start = vis[cur.x][cur.y][cur.dp][cur.cp], rho = cur.step - start;
  n = (n - start + 1) % rho;
  while (n--) move(cur);
  cout << cur.bp << endl;
  return 0;
}
