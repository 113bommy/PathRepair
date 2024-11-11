#include <bits/stdc++.h>
int tree[1000][1000], inq[1000][1000], la[1000][1000], ls[1000][1000];
int qx[1020200], qy[1020200];
int vx, vy, sx, sy, xx, yy, m, VX, VY, SX, SY;
void init() {
  scanf("%d %d %d %d %d", &vx, &vy, &sx, &sy, &m);
  VX = vx;
  VY = vy;
  SX = sx;
  SY = sy;
  if (m == 0) {
    printf("-1");
    exit(0);
  }
  while (m--) {
    scanf("%d %d", &xx, &yy);
    tree[xx + 500][yy + 500] = 1;
  }
}
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
char di[10] = "LDRU";
void bfs() {
  int l, r, ix, iy, kx, ky, j, i;
  memset(inq, 0, sizeof(inq));
  l = r = 0;
  qx[l] = vx;
  qy[r] = vy;
  inq[vx + 500][vy + 500] = 1;
  while (l <= r) {
    i = l++;
    ix = qx[i];
    iy = qy[i];
    for (j = 0; j < 4; j++) {
      kx = ix + dx[j];
      ky = iy + dy[j];
      if (inq[kx + 500][ky + 500]) continue;
      if (tree[kx + 500][ky + 500]) continue;
      if (kx < -480 || kx > 480 || ky < -480 || ky > 480) continue;
      r++;
      qx[r] = kx;
      qy[r] = ky;
      inq[kx + 500][ky + 500] = 1;
      la[kx + 500][ky + 500] = j;
    }
  }
}
void bf2() {
  int l, r, ix, iy, kx, ky, j, i;
  memset(inq, 0, sizeof(inq));
  l = r = 0;
  qx[l] = sx;
  qy[r] = sy;
  inq[sx + 500][sy + 500] = 1;
  while (l <= r) {
    i = l++;
    ix = qx[i];
    iy = qy[i];
    for (j = 0; j < 4; j++) {
      kx = ix + dx[j];
      ky = iy + dy[j];
      if (inq[kx + 500][ky + 500]) continue;
      if (tree[kx + 500][ky + 500]) continue;
      if (kx < -480 || kx > 480 || ky < -480 || ky > 480) continue;
      r++;
      qx[r] = kx;
      qy[r] = ky;
      inq[kx + 500][ky + 500] = 1;
      ls[kx + 500][ky + 500] = j;
    }
  }
}
char buf[1020202];
char put[1020202];
int lput;
void apply(int j) {
  vx += dx[j];
  vy += dy[j];
  if (!tree[sx + dx[j] + 500][sy + dy[j] + 500]) sx += dx[j], sy += dy[j];
  put[++lput] = di[j];
}
void outside1() {
  int i, j, k = 1000000, x, y;
  if (!inq[750][750]) return;
  i = 250;
  j = 250;
  while (i != vx || j != vy) {
    k--;
    buf[k] = la[i + 500][j + 500];
    int aa = la[i + 500][j + 500];
    i -= dx[aa];
    j -= dy[aa];
  }
  for (i = k; i < 1000000; i++) apply(buf[i]);
  x = -1000000;
  for (i = -100; i <= 100; i++)
    for (j = -100; j <= 100; j++)
      if (tree[i + 500][j + 500])
        if (i > x)
          x = i, y = j;
        else if (i == x && j > y)
          y = j;
  bf2();
  i = x;
  j = y + 1;
  k = 1000000;
  while (i != sx || j != sy) {
    k--;
    buf[k] = ls[i + 500][j + 500];
    int aa = ls[i + 500][j + 500];
    i -= dx[aa];
    j -= dy[aa];
  }
  for (i = k; i < 1000000; i++) apply(buf[i]);
  if (vy < sy || vx < sx) {
    lput = 0;
    vy = VY;
    sy = SY;
    vx = VX;
    sx = SX;
    return;
  }
  while (vy != sy) apply(1);
  apply(2);
  apply(1);
  while (vx != sx) apply(0);
  for (int i = 1; i <= lput; i++) putchar(put[i]);
  exit(0);
}
void outside2() {
  int i, j, k = 1000000, x, y;
  if (!inq[250][750]) return;
  i = -250;
  j = 250;
  while (i != vx || j != vy) {
    k--;
    buf[k] = la[i + 500][j + 500];
    int aa = la[i + 500][j + 500];
    i -= dx[aa];
    j -= dy[aa];
  }
  for (i = k; i < 1000000; i++) apply(buf[i]);
  x = 1000000;
  for (i = -100; i <= 100; i++)
    for (j = -100; j <= 100; j++)
      if (tree[i + 500][j + 500])
        if (i < x)
          x = i, y = j;
        else if (i == x && j > y)
          y = j;
  bf2();
  i = x;
  j = y + 1;
  k = 1000000;
  while (i != sx || j != sy) {
    k--;
    buf[k] = ls[i + 500][j + 500];
    int aa = ls[i + 500][j + 500];
    i -= dx[aa];
    j -= dy[aa];
  }
  for (i = k; i < 1000000; i++) apply(buf[i]);
  if (vy < sy || vx > sx) {
    lput = 0;
    vy = VY;
    sy = SY;
    vx = VX;
    sx = SX;
    return;
  }
  while (vy != sy) apply(1);
  apply(0);
  apply(1);
  while (vx != sx) apply(2);
  for (int i = 1; i <= lput; i++) putchar(put[i]);
  exit(0);
}
void outside3() {
  int i, j, k = 1000000, x, y;
  if (!inq[250][250]) return;
  i = -250;
  j = -250;
  while (i != vx || j != vy) {
    k--;
    buf[k] = la[i + 500][j + 500];
    int aa = la[i + 500][j + 500];
    i -= dx[aa];
    j -= dy[aa];
  }
  for (i = k; i < 1000000; i++) apply(buf[i]);
  x = 1000000;
  for (i = -100; i <= 100; i++)
    for (j = -100; j <= 100; j++)
      if (tree[i + 500][j + 500])
        if (i < x)
          x = i, y = j;
        else if (i == x && j < y)
          y = j;
  bf2();
  i = x;
  j = y - 1;
  k = 1000000;
  while (i != sx || j != sy) {
    k--;
    buf[k] = ls[i + 500][j + 500];
    int aa = ls[i + 500][j + 500];
    i -= dx[aa];
    j -= dy[aa];
  }
  for (i = k; i < 1000000; i++) apply(buf[i]);
  if (vy > sy || vx > sx) {
    lput = 0;
    vy = VY;
    sy = SY;
    vx = VX;
    sx = SX;
    return;
  }
  while (vy != sy) apply(3);
  apply(0);
  apply(3);
  while (vx != sx) apply(2);
  for (int i = 1; i <= lput; i++) putchar(put[i]);
  exit(0);
}
void outside4() {
  int i, j, k = 1000000, x, y;
  if (!inq[750][250]) return;
  i = 250;
  j = -250;
  while (i != vx || j != vy) {
    k--;
    buf[k] = la[i + 500][j + 500];
    int aa = la[i + 500][j + 500];
    i -= dx[aa];
    j -= dy[aa];
  }
  for (i = k; i < 1000000; i++) apply(buf[i]);
  x = -1000000;
  for (i = -100; i <= 100; i++)
    for (j = -100; j <= 100; j++)
      if (tree[i + 500][j + 500])
        if (i > x)
          x = i, y = j;
        else if (i == x && j < y)
          y = j;
  bf2();
  i = x;
  j = y - 1;
  k = 1000000;
  while (i != sx || j != sy) {
    k--;
    buf[k] = ls[i + 500][j + 500];
    int aa = ls[i + 500][j + 500];
    i -= dx[aa];
    j -= dy[aa];
  }
  for (i = k; i < 1000000; i++) apply(buf[i]);
  if (vy > sy || vx < sx) {
    lput = 0;
    vy = VY;
    sy = SY;
    vx = VX;
    sx = SX;
    return;
  }
  while (vy != sy) apply(3);
  apply(2);
  apply(3);
  while (vx != sx) apply(0);
  for (int i = 1; i <= lput; i++) putchar(put[i]);
  exit(0);
}
int q[1020202];
int l, r;
void apply2(int j) {
  vx += dx[j];
  vy += dy[j];
  if (!tree[sx + dx[j] + 500][sy + dy[j] + 500])
    sx += dx[j], sy += dy[j], q[++r] = j;
  putchar(di[j]);
}
void inside() {
  int i, j, k;
  l = 0;
  r = -1;
  i = sx;
  j = sy;
  k = 1000000;
  while (i != vx || j != vy) {
    k--;
    buf[k] = la[i + 500][j + 500];
    int aa = la[i + 500][j + 500];
    i -= dx[aa];
    j -= dy[aa];
  }
  for (i = k; i < 1000000; i++) apply2(buf[i]);
  while (l <= r && (sx != vx || sy != vy)) apply2(q[l++]);
}
int main() {
  init();
  bfs();
  if (!inq[sx + 500][sy + 500])
    printf("-1");
  else if (inq[250][250]) {
    outside4();
    outside3();
    outside2();
    outside1();
  } else
    inside();
  return 0;
}
