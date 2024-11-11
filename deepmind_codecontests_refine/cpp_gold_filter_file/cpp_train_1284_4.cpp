#include <bits/stdc++.h>
using namespace std;
int a[30][30];
int mid, n, k;
bool vis[30];
int dfs(int id, int res) {
  if (res > mid) return 0;
  if (id > n) return 1;
  int ret = dfs(id + 1, res);
  for (int i = 1; i <= n; i++) {
    if (!vis[i] && a[id][i]) {
      vis[i] = 1;
      ret += dfs(id + 1, res + a[id][i]);
      vis[i] = 0;
      if (ret > k) break;
    }
  }
  if (ret > k) ret = k;
  return ret;
}
int main() {
  int m;
  scanf("%d%d%d", &n, &m, &k);
  memset(a, 0, sizeof(a));
  int x, y, z;
  for (int i = 1; i <= m; i++) {
    scanf("%d%d%d", &x, &y, &z);
    a[x][y] = z;
  }
  int l = 0, r = n * 1000;
  while (l < r) {
    mid = (l + r) >> 1;
    if (dfs(1, 0) >= k)
      r = mid;
    else
      l = mid + 1;
  }
  printf("%d\n", l);
}
