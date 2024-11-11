#include <bits/stdc++.h>
using namespace std;
const int fx[4] = {0, 1, 0, -1};
const int fy[4] = {1, 0, -1, 0};
const char fg[4] = {'U', 'R', 'D', 'L'};
int flag[205][205];
int tree[205][205];
int qx[111111];
int qy[111111];
int qf[111111];
int x0, x1, Y0, Y1, gx, gy;
int h, t, cx, px, cy, py;
int back[205][205];
int tx[1111], ty[1111];
int n;
inline int fang(int dx, int dy) { return ((dx | dy) & 2) | (dx & 1); }
bool bfs() {
  int i;
  qx[0] = x0;
  qy[0] = Y0;
  t++;
  flag[x0 + 102][Y0 + 102] = 1;
  back[x0 + 102][Y0 + 102] = -1;
  for (h = 0; h < t; h++) {
    cx = qx[h];
    cy = qy[h];
    for (i = 0; i < 4; i++) {
      px = cx + fx[i];
      py = cy + fy[i];
      if (flag[px + 102][py + 102]) continue;
      flag[px + 102][py + 102] = flag[cx + 102][cy + 102] + 1;
      back[px + 102][py + 102] = i;
      qx[t] = px;
      qy[t] = py;
      t++;
    }
  }
  if (flag[x1 + 102][Y1 + 102] == 0) return 0;
  t = flag[x1 + 102][Y1 + 102] - 1;
  cx = x1;
  cy = Y1;
  for (i = t; i > 0;) {
    qx[i] = cx;
    qy[i] = cy;
    h = back[cx + 102][cy + 102];
    qf[--i] = h;
    cx -= fx[h];
    cy -= fy[h];
  }
  qx[0] = cx;
  qy[0] = cy;
  return 1;
}
void wangshangsuo() {
  gx = tx[0];
  gy = ty[0];
  for (int i = 1; i < n; i++)
    if (ty[i] < gy) gx = tx[i], gy = ty[i];
  for (; Y1 != gy - 1; Y0--, Y1--) printf("D");
  for (; x1 != gx; x0--, x1--) printf("L");
  for (; Y0 != Y1; Y0++) printf("U");
  for (; x0 <= 100 || x1 <= 100; x0++, x1++) printf("R");
  for (; Y0 <= 100; Y0++, Y1++) printf("U");
}
void wangyousuo() {
  gx = tx[0];
  gy = ty[0];
  for (int i = 1; i < n; i++)
    if (tx[i] < gx) gx = tx[i], gy = ty[i];
  for (; x1 != gx - 1; x0--, x1--) printf("L");
  for (; Y1 != gy; Y0--, Y1--) printf("D");
  for (; x0 != x1; x0++) printf("R");
  for (; Y0 <= 100 || Y1 <= 100; Y0++, Y1++) printf("U");
  for (; x0 <= 100; x0++, x1++) printf("R");
}
void wangzuosuo() {
  gx = tx[0];
  gy = ty[0];
  for (int i = 1; i < n; i++)
    if (tx[i] > gx) gx = tx[i], gy = ty[i];
  for (; Y1 != gy; Y0--, Y1--) printf("D");
  for (; x0 != gx + 1; x0--) printf("L");
  for (; x0 != 101; x0++) printf("R");
  for (x1 = 101; Y0 <= 100 || Y1 <= 100; Y0++, Y1++) printf("U");
}
void wangxiasuo() {
  gx = tx[0];
  gy = ty[0];
  for (int i = 1; i < n; i++)
    if (ty[i] > gy) gx = tx[i], gy = ty[i];
  for (; x1 != gx; x0--, x1--) printf("L");
  for (; Y0 != gy + 1; Y0--) printf("D");
  for (; Y0 != 101; Y0++) printf("U");
  for (Y1 = 101; x0 <= 100 || x1 <= 100; x0++, x1++) printf("R");
}
void chaselong() {
  int g;
  for (h = 0; t < 20000 && (qx[h] != qx[t] || qy[h] != qy[t]); h++) {
    g = qf[h];
    printf("%c", fg[g]);
    px = qx[t] + fx[g];
    py = qy[t] + fy[g];
    if (px > 100 || px < -100 || py > 100 || py < -100 ||
        !tree[px + 102][py + 102]) {
      qf[t] = g;
      t++;
      qx[t] = px;
      qy[t] = py;
    }
  }
  x0 = qx[h];
  Y0 = qy[h];
  x1 = qx[t];
  Y1 = qy[t];
  if (x0 == x1 && Y0 == Y1) {
    printf("\n");
    return;
  }
  for (; x0 >= -100 && x0 <= 100; x0++, x1++) printf("R");
  for (; x1 >= -100 && x1 <= 100; x0++, x1++) printf("R");
  for (; Y0 <= 100 || Y1 <= 100; Y0++, Y1++) printf("U");
  for (; Y0 > 101 && Y1 > 101; Y0--, Y1--) printf("D");
  for (; x0 <= 100 || x1 <= 100; x0++, x1++) printf("R");
  for (; x0 > 101 && x1 > 101; x0--, x1--) printf("L");
  if (x0 > 101) wangzuosuo();
  if (x1 > 101) wangyousuo();
  if (Y0 > 101) wangxiasuo();
  if (Y1 > 101) wangshangsuo();
  printf("\n");
}
int main() {
  int i;
  scanf("%d%d%d%d%d", &x0, &Y0, &x1, &Y1, &n);
  if (n == 0) {
    printf("-1\n");
    return 0;
  }
  for (i = 0; i < 205; i++) {
    flag[0][i] = -1;
    flag[102 << 1][i] = -1;
    flag[i][0] = -1;
    flag[i][102 << 1] = -1;
  }
  for (i = 0; i < n; i++) {
    scanf("%d%d", tx + i, ty + i);
    flag[tx[i] + 102][ty[i] + 102] = -1;
    tree[tx[i] + 102][ty[i] + 102] = 1;
  }
  if (!bfs()) {
    printf("-1\n");
    return 0;
  }
  chaselong();
  return 0;
}
