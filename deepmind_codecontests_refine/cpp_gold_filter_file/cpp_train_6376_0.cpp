#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1050;
int n, m;
char a[MAXN][MAXN];
bool fv[MAXN][MAXN];
const int dir[8][2] = {{0, 1}, {0, -1}, {1, 0},  {-1, 0},
                       {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
struct Tpoint {
  int x, y;
  Tpoint() {}
  Tpoint(const int& x, const int& y) : x(x), y(y) {}
};
queue<Tpoint> Q;
Tpoint all[MAXN * MAXN];
Tpoint bj[MAXN * MAXN];
int bjs;
bool v[MAXN][MAXN];
bool v2[MAXN][MAXN];
int ans;
bool test() {
  int tt = 0;
  tt = 1;
  Tpoint now = bj[1];
  v2[now.x][now.y] = true;
  while (1) {
    bool ok = false;
    for (int d = 0; d < 4; d++) {
      int nx = now.x + dir[d][0];
      int ny = now.y + dir[d][1];
      if (nx < 1 || ny < 1 || nx > n || ny > m) continue;
      if (v2[nx][ny]) continue;
      if (v[nx][ny]) {
        ok = true;
        v2[nx][ny] = true;
        tt++;
        now = Tpoint(nx, ny);
        break;
      }
    }
    if (!ok) break;
  }
  if (abs(now.x - bj[1].x) + abs(now.y - bj[1].y) == 1) {
    if (tt == bjs) {
      for (int i = 1; i <= bjs; i++) {
        int t = 0;
        for (int d = 0; d < 4; d++) {
          int nx = bj[i].x + dir[d][0];
          int ny = bj[i].y + dir[d][1];
          if (nx < 1 || ny < 1 || nx > n || ny > m) continue;
          if (v2[nx][ny]) t++;
        }
        if (t != 2) return false;
      }
      return true;
    }
  }
  return false;
}
void floodfill(int sx, int sy) {
  while (!Q.empty()) Q.pop();
  Q.push(Tpoint(sx, sy));
  int tot = 1;
  all[tot] = Tpoint(sx, sy);
  while (!Q.empty()) {
    Tpoint f = Q.front();
    Q.pop();
    for (int d = 0; d < 8; d++) {
      int nx = f.x + dir[d][0];
      int ny = f.y + dir[d][1];
      if (1 <= nx && nx <= n && 1 <= ny && ny <= m) {
        if (a[nx][ny] == '0' && !fv[nx][ny]) {
          fv[nx][ny] = true;
          Q.push(Tpoint(nx, ny));
          tot++;
          all[tot] = Tpoint(nx, ny);
        }
      }
    }
  }
  bool bad = false;
  bjs = 0;
  for (int i = 1; i <= tot; i++) {
    for (int d = 0; d < 8; d++) {
      int nx = all[i].x + dir[d][0];
      int ny = all[i].y + dir[d][1];
      if (1 <= nx && nx <= n && 1 <= ny && ny <= m) {
        if (a[nx][ny] == '1') {
          if (v[nx][ny]) continue;
          bjs++;
          ;
          bj[bjs] = Tpoint(nx, ny);
          v[nx][ny] = true;
        }
      } else {
        bad = true;
        break;
      }
    }
  }
  if (!bad && bjs > ans) {
    if (test()) {
      if (bjs > ans) ans = bjs;
    }
  }
  for (int i = 1; i <= bjs; i++)
    v[bj[i].x][bj[i].y] = v2[bj[i].x][bj[i].y] = false;
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) {
    scanf("%s", a[i]);
    for (int j = m; j >= 1; j--) a[i][j] = a[i][j - 1];
  }
  ans = 0;
  for (int i = 1; i < n; i++)
    for (int j = 1; j < m; j++)
      if (a[i][j] == '1' && a[i + 1][j] == '1' && a[i][j + 1] == '1' &&
          a[i + 1][j + 1] == '1') {
        ans = 4;
        break;
      }
  memset(fv, 0, sizeof(fv));
  memset(v, 0, sizeof(v));
  memset(v2, 0, sizeof(v2));
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      if (!fv[i][j] && a[i][j] == '0') {
        floodfill(i, j);
      }
  cout << ans << endl;
  return 0;
}
