#include <bits/stdc++.h>
using namespace std;
int n, x, y, z, res, ans;
long long a[300010];
int f[310][4];
int ff[125][310][4], re[125];
bool vis[5];
void work(int x, int y, int z) {
  int now;
  bool flag = 0;
  int id = (x - 1) * 25 + (y - 1) * 5 + z - 1;
  for (int i = 1; i <= 300; i++)
    for (int j = 0; j < 4; j++) {
      now = 0;
      vis[f[max(i - x, 0)][1]] = 1;
      if (j != 2) vis[f[max(i - y, 0)][2]] = 1;
      if (j != 3) vis[f[max(i - z, 0)][3]] = 1;
      while (vis[now]) now++;
      f[i][j] = now;
      vis[f[max(i - x, 0)][1]] = 0;
      vis[f[max(i - y, 0)][2]] = 0;
      vis[f[max(i - z, 0)][3]] = 0;
      ff[id][i][j] = now;
    }
  re[id] = 1;
  while (!flag) {
    flag = 1;
    for (int i = 30; flag && i <= 300 - re[id]; i++)
      for (int j = 0; j < 4; j++) {
        if (f[i][j] != f[i + re[id]][j]) {
          flag = 0;
          break;
        }
      }
    if (flag) break;
    re[id]++;
  }
}
int F(int id, long long x, int y) {
  if (x <= 300) return ff[id][x][y];
  long long xx = x % re[id] + re[id] * 15;
  return ff[id][xx][y];
}
int main() {
  int T, now, id;
  scanf("%d", &T);
  for (int i = 1; i <= 5; i++)
    for (int j = 1; j <= 5; j++)
      for (int k = 1; k <= 5; k++) work(i, j, k);
  while (T--) {
    scanf("%d%d%d%d", &n, &x, &y, &z);
    id = (x - 1) * 25 + (y - 1) * 5 + z - 1;
    res = 0;
    ans = 0;
    for (int i = 1; i <= n; i++) {
      scanf("%lld", &a[i]);
      res ^= F(id, a[i], 0);
    }
    for (int i = 1; i <= n; i++) {
      res ^= F(id, a[i], 0);
      res ^= F(id, max(a[i] - x, 0ll), 1);
      if (!res) ans++;
      res ^= F(id, max(a[i] - x, 0ll), 1);
      res ^= F(id, max(a[i] - y, 0ll), 2);
      if (!res) ans++;
      res ^= F(id, max(a[i] - y, 0ll), 2);
      res ^= F(id, max(a[i] - z, 0ll), 3);
      if (!res) ans++;
      res ^= F(id, max(a[i] - z, 0ll), 3);
      res ^= F(id, a[i], 0);
    }
    printf("%d\n", ans);
  }
  return 0;
}
