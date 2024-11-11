#include <bits/stdc++.h>
using namespace std;
bool debug = false;
int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
char a[16][16];
int dis[16][16][1 << 12];
int mark[16][16];
int n, m, len, er, ec, tme;
int r[11], c[11];
struct State {
  int r, c, s;
};
int mask;
State ns(int r, int c, int s) {
  State st;
  st.r = r;
  st.c = c;
  st.s = s;
  return st;
}
int getdir(int nowr, int nowc, int orgr, int orgc) {
  for (int i = 0; i < 4; i++) {
    if (nowr + dx[i] == orgr && nowc + dy[i] == orgc) {
      return i;
    }
  }
  return -1;
}
int main(int argc, char* argv[]) {
  memset(dis, -1, sizeof(dis));
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++) {
    scanf("%s", a[i]);
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (isdigit(a[i][j])) {
        r[a[i][j] - '1'] = i;
        c[a[i][j] - '1'] = j;
        len = max(len, a[i][j] - '0');
      }
      if (a[i][j] == '@') {
        er = i;
        ec = j;
      }
    }
  }
  int st = 0;
  mask = (1 << (len * 2 - 2)) - 1;
  for (int i = 1; i < len; i++) {
    st |= getdir(r[i], c[i], r[i - 1], c[i - 1]) << (i * 2 - 2);
  }
  queue<State> q;
  q.push(ns(r[0], c[0], st));
  dis[r[0]][c[0]][st] = 0;
  while (!q.empty()) {
    int lr = q.front().r, lc = q.front().c, ls = q.front().s;
    q.pop();
    tme++;
    mark[lr][lc] = tme;
    int dr = lr, dc = lc, ds = ls;
    for (int i = 2; i < len; i++) {
      int dir = (ds & 3) ^ 2;
      dr += dx[dir];
      dc += dy[dir];
      ds >>= 2;
      mark[dr][dc] = tme;
    }
    for (int i = 0; i < 4; i++) {
      int nx = lr + dx[i], ny = lc + dy[i];
      int ds = ((ls << 2) & mask) | i;
      if (nx < 0 || nx >= n || ny < 0 || ny >= m || a[nx][ny] == '#' ||
          mark[nx][ny] == tme || ~dis[nx][ny][ds])
        continue;
      q.push(ns(nx, ny, ds));
      dis[nx][ny][ds] = dis[lr][lc][ls] + 1;
    }
  }
  int ans = 1e9;
  for (int i = 0; i < (1 << 12); i++) {
    if (~dis[er][ec][i]) ans = min(ans, dis[er][ec][i]);
  }
  if (ans == 1e9) ans = -1;
  printf("%d", ans);
  return 0;
}
