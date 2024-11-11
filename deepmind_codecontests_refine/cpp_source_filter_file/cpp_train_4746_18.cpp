#include <bits/stdc++.h>
using namespace std;
const int hor[] = {0, 16, 257, 273, 325, 341, 455};
const int ver[] = {0, 16, 68, 84, 325, 341, 365};
char mp[1210][1210];
int g[310][310];
int f[310];
int n, m;
void init() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < 4 * n + 1; ++i) scanf("%s", mp[i]);
}
int val_pd(int x, int y) {
  int cur = 0;
  for (int i = 2; i >= 0; --i)
    for (int j = 2; j >= 0; --j) cur = cur * 2 + (mp[x + i][y + j] == 'O');
  int val = 0;
  for (int i = 0; i < 7; ++i) {
    if (hor[i] == cur) val |= 1;
    if (ver[i] == cur) val |= 2;
  }
  return val;
}
void g_cal() {
  for (int i = 1; i < 4 * n + 1; i += 4)
    for (int j = 1; j < 4 * m + 1; j += 4) g[i / 4][j / 4] = val_pd(i, j);
}
int vec_cal(int col) {
  if (n % 2) return 0;
  for (int i = 0; i < n; ++i)
    if ((g[i][col] & 2) == 0) return 0;
  return 1;
}
int hor_cal(int col) {
  int f[310];
  f[0] = 1;
  f[1] = ((g[0][col] & 1) && (g[0][col - 1] & 1));
  for (int i = 2; i <= n; ++i) {
    f[i] = 0;
    if ((g[i - 1][col] & 1) && (g[i - 1][col - 1] & 1)) f[i] = f[i - 1];
    if ((g[i - 1][col] & 2) && (g[i - 1][col - 1] & 2) && (g[i - 2][col] & 2) &&
        (g[i - 2][col - 1] & 2))
      f[i] = ((long long)f[i] + f[i - 2]) % 1000000007;
  }
  return f[n] - (vec_cal(col) && vec_cal(col));
}
void solve() {
  g_cal();
  f[0] = 1;
  f[1] = vec_cal(0);
  for (int i = 2; i <= m; ++i)
    f[i] = ((long long)f[i - 1] * vec_cal(i - 1) +
            (long long)f[i - 2] * hor_cal(i - 1)) %
           1000000007;
  printf("%d\n", f[m]);
}
int main() {
  init();
  solve();
  return 0;
}
