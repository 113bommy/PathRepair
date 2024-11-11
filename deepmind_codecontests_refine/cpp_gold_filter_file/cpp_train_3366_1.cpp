#include <bits/stdc++.h>
using namespace std;
int n, m, x[1005], y[1005], d[1005], a[1005];
bool u[1005];
vector<int> e[1005];
bool dfs(int x, int y) {
  if (y > m) return 0;
  if (x == n) {
    int ptr = 0;
    while (y < m) {
      while (u[ptr++])
        ;
      d[y++] = ptr++;
    }
    return 1;
  }
  if (u[x]) return dfs(x + 1, y);
  int yy = y, ori[e[x].size()];
  for (int i = (0); i < (e[x].size()); i++) {
    ori[i] = u[e[x][i]];
    if (!u[e[x][i]]) {
      d[yy++] = e[x][i];
      u[e[x][i]] = 1;
    }
  }
  if (dfs(x + 1, yy)) return 1;
  for (int i = (0); i < (e[x].size()); i++) u[e[x][i]] = ori[i];
  d[y] = x;
  u[x] = 1;
  if (y + 1 < yy && dfs(x + 1, y + 1)) return 1;
  u[x] = 0;
  return 0;
}
bool ok(int l) {
  for (int i = (0); i < (n); i++) u[i] = 0;
  for (int i = (0); i < (n); i++) e[i].clear();
  int k = 0, cnt = 0;
  for (int i = (0); i < (n); i++) {
    for (int j = (0); j < (n); j++)
      if ((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]) > l)
        e[i].push_back(j);
    if (e[i].size() > m) {
      u[i] = 1;
      d[k++] = i;
    }
  }
  for (int i = (0); i < (n); i++)
    if (!u[i])
      for (int j = (0); j < (n); j++)
        if (!u[j] &&
            (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]) > l)
          cnt++;
  if (k > m || cnt / 2 > (m - k) * m) return 0;
  return dfs(0, k);
}
int main() {
  scanf("%d %d", &n, &m);
  for (int i = (0); i < (n); i++) scanf("%d %d", &x[i], &y[i]);
  int l = 0, h = 2147483647;
  while (l < h) {
    int mid = l + h >> 1;
    if (ok(mid)) {
      h = mid;
      for (int i = (0); i < (m); i++) a[i] = d[i];
    } else
      l = mid + 1;
  }
  for (int i = (0); i < (m); i++) printf("%d\n", a[i] + 1);
  scanf("\n");
}
