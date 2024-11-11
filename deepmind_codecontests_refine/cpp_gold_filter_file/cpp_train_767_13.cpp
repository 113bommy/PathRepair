#include <bits/stdc++.h>
using namespace std;
bool a[3000 + 5][(3000 << 1) + 5], vis[(3000 + 5) * ((3000 << 1) + 5)];
int father[30000000 + 5], t, r, c, n, step[8][2];
int check(int x, int y) {
  if (x < 1 || x > r || y < 1 || y > (c << 1)) return 0;
  return a[x][y];
}
int getfather(int u) {
  return father[u] == u ? u : father[u] = getfather(father[u]);
}
void ui(int u, int v) {
  u = getfather(u), v = getfather(v);
  if (u == v) return;
  father[u] = v;
}
int mo(int x) {
  if (x <= 0) return x + 2 * c;
  if (x > 2 * c) return x - 2 * c;
  return x;
}
int main() {
  scanf("%d%d%d", &r, &c, &n);
  for (int i = 1; i <= ((r - 1) * (c << 1) + (c << 1)); i++) father[i] = i;
  int ans = 0;
  step[0][0] = -1, step[0][1] = -1;
  step[1][0] = -1, step[1][1] = 0;
  step[2][0] = -1, step[2][1] = 1;
  step[3][0] = 0, step[3][1] = -1;
  step[4][0] = 0, step[4][1] = 1;
  step[5][0] = 1, step[5][1] = -1;
  step[6][0] = 1, step[6][1] = 0;
  step[7][0] = 1, step[7][1] = 1;
  memset(a, 0, sizeof(a));
  while (n--) {
    int x, y;
    scanf("%d%d", &x, &y);
    if (c == 1) continue;
    a[x][y] = a[x][y + c] = 1;
    for (int i = 0; i < 8; i++)
      if (check(x + step[i][0], mo(y + step[i][1])))
        vis[getfather(
            ((x + step[i][0] - 1) * (c << 1) + (mo(y + step[i][1]))))] = 1;
    y += c;
    bool flag = 0;
    for (int i = 0; i < 8; i++)
      if (check(x + step[i][0], mo(y + step[i][1])))
        if (vis[getfather(
                ((x + step[i][0] - 1) * (c << 1) + (mo(y + step[i][1]))))])
          flag = 1;
    y -= c;
    for (int i = 0; i < 8; i++)
      if (check(x + step[i][0], mo(y + step[i][1])))
        vis[getfather(
            ((x + step[i][0] - 1) * (c << 1) + (mo(y + step[i][1]))))] = 0;
    if (flag) {
      a[x][y] = a[x][y + c] = 0;
      continue;
    }
    for (int i = 0; i < 8; i++)
      if (check(x + step[i][0], mo(y + step[i][1])))
        vis[((x + step[i][0] - 1) * (c << 1) +
             (mo(y + step[i][1])))] = 0,
                     ui(((x - 1) * (c << 1) + (y)),
                        ((x + step[i][0] - 1) * (c << 1) +
                         (mo(y + step[i][1]))));
    y += c;
    for (int i = 0; i < 8; i++)
      if (check(x + step[i][0], mo(y + step[i][1])))
        ui(((x - 1) * (c << 1) + (y)),
           ((x + step[i][0] - 1) * (c << 1) + (mo(y + step[i][1]))));
    ans++;
  }
  printf("%d\n", ans);
  return 0;
}
