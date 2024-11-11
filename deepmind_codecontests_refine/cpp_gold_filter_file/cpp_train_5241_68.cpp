#include <bits/stdc++.h>
using namespace std;
bool debug = false;
int n, m, k;
int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
int mp[2005][2005], s[2005][2005], u, v, t;
void dfs(int i, int j) {
  if (!s[i][j]) return;
  s[i][j] = 0;
  t++;
  if (i > u || (i == u && j > v)) {
    u = i;
    v = j;
  }
  for (int(k) = 0; (k) < (int)(4); (k)++) dfs(i + dx[k], j + dy[k]);
}
int main() {
  scanf("%d", &n);
  for (int(i) = 0; (i) < (int)(n); (i)++)
    for (int(j) = 0; (j) < (int)(n); (j)++) {
      scanf("%d", mp[i + 1] + j + 1);
    }
  for (int i = 1; i <= n - 4; i++)
    for (int j = 1; j <= n - 4; j++) {
      int ss = 0;
      for (int x = i; x <= i + 4; x++) {
        for (int y = j; y <= j + 4; y++) {
          ss += mp[x][y];
        }
      }
      if (ss >= 15) s[i][j] = 1;
    }
  int a1 = 0, a2 = 0;
  for (int i = 1; i <= n - 4; i++)
    for (int j = 1; j <= n - 4; j++)
      if (s[i][j]) {
        u = i;
        v = j;
        t = 0;
        dfs(i, j);
        double d = sqrt((u - i) * (u - i) + (v - j) * (v - j));
        if (d < 10) continue;
        double d1 = fabs(d * d / 2 - t);
        double d2 = fabs(d * d / 4 * acos(-1) - t);
        if (d1 < d2)
          a1++;
        else
          a2++;
      }
  printf("%d %d", a2, a1);
  return 0;
}
