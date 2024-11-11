#include <bits/stdc++.h>
using namespace std;
const int N = 5100;
int n, tim[N][3], all[3], ok[3], lb[6], rb[6], sco[N], dlt[N][8],
    f[2][91][91][91];
void Min(int &x, int y) { x = min(x, y); }
int calc(int k1, int k2, int k3) {
  if (all[0] < lb[k1] || ok[0] > rb[k1]) return n;
  if (all[1] < lb[k2] || ok[1] > rb[k2]) return n;
  if (all[2] < lb[k3] || ok[2] > rb[k3]) return n;
  int a1 = all[0] - max(ok[0], lb[k1]);
  int a2 = all[1] - max(ok[1], lb[k2]);
  int a3 = all[2] - max(ok[2], lb[k3]);
  if (a1 + a2 + a3 >= 90) return 1;
  int s[3];
  s[0] = (k1 + 1) * 500, s[1] = (k2 + 1) * 500, s[2] = (k3 + 1) * 500;
  for (int i = 1; i <= n; i++) {
    sco[i] = i == 1 ? (a1 + a2 + a3) * 100 : 0;
    for (int j = 0; j <= 2; j++)
      if (tim[i][j] != 0) sco[i] += s[j] * (250 - abs(tim[i][j])) / 250;
    for (int j = 0; j <= 7; j++) {
      dlt[i][j] = 0;
      for (int k = 0; k <= 2; k++)
        if ((j >> k) & 1)
          dlt[i][j] += tim[i][k] < 0 ? s[k] * (250 + tim[i][k]) / 250 : 0;
    }
  }
  int qinding = 0, nw = 0;
  memset(f[nw], 0x3f, sizeof(f[nw]));
  f[nw][0][0][0] = 0;
  for (int i = 2; i <= n; i++) {
    if (sco[i] <= sco[1]) continue;
    if (tim[i][0] > 0 && tim[i][1] > 0 && tim[i][2] > 0) {
      ++qinding;
      continue;
    }
    nw ^= 1;
    memset(f[nw], 0x3f, sizeof(f[nw]));
    for (int x = 0; x <= a1; x++)
      for (int y = 0; y <= a2; y++)
        for (int z = 0; z <= a3; z++)
          if (f[nw ^ 1][x][y][z] < n) {
            Min(f[nw][x][y][z], f[nw ^ 1][x][y][z] + 1);
            for (int j = 0; j <= 7; j++)
              if (sco[i] - dlt[i][j] <= sco[1]) {
                int tx = x + ((j >> 0) & 1);
                int ty = y + ((j >> 1) & 1);
                int tz = z + ((j >> 2) & 1);
                Min(f[nw][tx][ty][tz], f[nw ^ 1][x][y][z]);
              }
          }
  }
  int res = n;
  for (int i = 0; i <= a1; i++)
    for (int j = 0; j <= a2; j++)
      for (int k = 0; k <= a3; k++) res = min(res, f[nw][i][j][k]);
  return res + qinding + 1;
}
int main() {
  scanf("%d", &n);
  int tot = 0;
  for (int i = 1; i <= n; i++)
    for (int j = 0; j <= 2; j++) {
      scanf("%d", &tim[i][j]);
      if (tim[i][j] != 0) ++all[j];
      if (tim[i][j] > 0 || (i == 1 && tim[i][j])) ++ok[j];
      if (tim[i][j] < 0) ++tot;
    }
  if (tot >= 90) {
    puts("1");
    return 0;
  }
  for (int i = 0; i <= 5; i++) lb[i] = n + 1, rb[i] = 0;
  for (int i = 0; i <= n; i++) {
    if (i * 32 <= n) {
      lb[5] = min(lb[5], i), rb[5] = i;
      continue;
    }
    for (int j = 4; j >= 0; j--)
      if (i * (1 << j + 1) <= 2 * n) {
        lb[j] = min(lb[j], i), rb[j] = i;
        break;
      }
  }
  int ans = n;
  for (int i = 0; i <= 5; i++)
    for (int j = 0; j <= 5; j++)
      for (int k = 0; k <= 5; k++) ans = min(ans, calc(i, j, k));
  printf("%d\n", ans);
  return 0;
}
