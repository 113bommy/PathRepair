#include <bits/stdc++.h>
char ch;
inline void read(int &x) {
  x = 0;
  ch = getchar();
  while (ch <= 32) ch = getchar();
  while (ch > 32) {
    x = x * 10 + ch - 48;
    ch = getchar();
  };
};
const int dx[8] = {0, 1, 0, -1, -1, -1, 1, 1};
const int dy[8] = {1, 0, -1, 0, -1, 1, -1, 1};
const int D_cnt = 8;
const int K1 = 3, K2 = 4;
int n, m;
bool a[1605][1605];
bool b[1605][1605];
char dist[1605][1605];
int l1[1605 * 1605], l2[1605 * 1605];
int s, t;
inline void push(int x, int y) {
  ++t;
  l1[t] = x;
  l2[t] = y;
};
inline void bfs1() {
  s = t = 0;
  int i, j;
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= m; j++) {
      if (!b[i][j]) {
        push(i, j);
        dist[i][j] = 0;
      };
    };
  };
  while (s < t) {
    int tx, ty;
    ++s;
    tx = l1[s];
    ty = l2[s];
    if (dist[tx][ty] == K1) continue;
    for (i = 0; i < D_cnt; i++) {
      int nx = tx + dx[i], ny = ty + dy[i];
      if (nx < 1 || nx > n || ny < 1 || ny > m) continue;
      if (!b[nx][ny]) continue;
      b[nx][ny] = 0;
      dist[nx][ny] = dist[tx][ty] + 1;
      push(nx, ny);
    };
  };
};
inline void bfs2() {
  s = t = 0;
  int i, j;
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= m; j++) {
      if (b[i][j]) {
        push(i, j);
        dist[i][j] = 0;
      };
    };
  };
  while (s < t) {
    int tx, ty;
    ++s;
    tx = l1[s];
    ty = l2[s];
    if (dist[tx][ty] == K2) continue;
    for (i = 0; i < D_cnt; i++) {
      int nx = tx + dx[i], ny = ty + dy[i];
      if (nx < 1 || nx > n || ny < 1 || ny > m) continue;
      if (b[nx][ny]) continue;
      b[nx][ny] = 1;
      dist[nx][ny] = dist[tx][ty] + 1;
      push(nx, ny);
    };
  };
};
int _cnt;
int visit[1605][1605];
int ll1[1605 * 1605], ll2[1605 * 1605];
inline void fill(int x0, int y0) {
  s = t = 0;
  bool _b = b[x0][y0];
  visit[x0][y0] = ++_cnt;
  push(x0, y0);
  while (s < t) {
    int tx, ty;
    ++s;
    tx = l1[s];
    ty = l2[s];
    int i;
    for (i = 0; i < D_cnt; i++) {
      int nx = tx + dx[i], ny = ty + dy[i];
      if (nx < 1 || nx > n || ny < 1 || ny > m) continue;
      if (visit[nx][ny] == _cnt) continue;
      if (!a[nx][ny] || b[nx][ny] != _b) continue;
      visit[nx][ny] = _cnt;
      push(nx, ny);
    };
  };
};
int ans[10000];
int cnt;
inline void check(int x0, int y0) {
  s = t = 0;
  push(x0, y0);
  visit[x0][y0] = ++_cnt;
  while (s < t) {
    int tx, ty;
    ++s;
    tx = l1[s];
    ty = l2[s];
    int i;
    for (i = 0; i < D_cnt; i++) {
      int nx = tx + dx[i], ny = ty + dy[i];
      if (nx < 1 || nx > n || ny < 1 || ny > m) continue;
      if (visit[nx][ny] == _cnt) continue;
      if (!a[nx][ny]) continue;
      visit[nx][ny] = _cnt;
      push(nx, ny);
    };
  };
  memcpy(ll1, l1, (t + 1) * sizeof(int));
  memcpy(ll2, l2, (t + 1) * sizeof(int));
  int tmp_cnt = _cnt;
  int tmp = 0;
  int i;
  int T = t;
  for (i = 1; i <= T; i++) {
    int tx = ll1[i], ty = ll2[i];
    if (visit[tx][ty] == tmp_cnt) {
      ++tmp;
      fill(tx, ty);
    };
  };
  ans[++cnt] = tmp - 1;
};
int main() {
  read(n);
  read(m);
  int i, j;
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= m; j++) {
      int x;
      read(x);
      a[i][j] = x;
    };
  };
  memcpy(b, a, sizeof(a));
  bfs1();
  bfs2();
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= m; j++) {
      if (a[i][j] && !visit[i][j]) {
        check(i, j);
      };
    };
  };
  std::sort(ans + 1, ans + cnt + 1);
  printf("%d\n", cnt);
  for (i = 1; i <= cnt; i++) {
    printf("%d ", ans[i]);
  };
}
