#include <bits/stdc++.h>
using namespace std;
int n, i, j, k, x, y, z, m, q, w, h, timer;
int a[300500], b[300500], tin[300500], tout[300500], up[300500][20], lv[300500];
int curl1[300500], curl2[300500], ans[300500], dst[300500];
vector<int> g[300500];
void dfs(int v, int lvl, int p = -1) {
  tin[v] = timer;
  lv[v] = lvl;
  if (p == -1)
    up[v][0] = 1;
  else
    up[v][0] = p;
  for (int i = 1; i <= 19; i++) up[v][i] = up[up[v][i - 1]][i - 1];
  for (int i = 0; i < g[v].size(); i++) {
    int to = g[v][i];
    if (to != p) {
      dfs(to, lvl + 1, v);
    }
  }
  tout[v] = timer++;
}
bool upper(int x, int y) { return (tin[x] <= tin[y] && tout[x] >= tout[y]); }
int lca(int x, int y) {
  if (upper(x, y)) return x;
  if (upper(y, x)) return y;
  for (int i = 10; i >= 0; i--) {
    if (!upper(up[x][i], y)) x = up[x][i];
  }
  return up[x][0];
}
int dist(int x, int y) {
  int lc = lca(x, y);
  return lv[x] + lv[y] - 2 * lv[lc];
}
int main() {
  cin >> n;
  n++;
  for (i = 0; i < n - 1; i++) {
    scanf("%d", &x);
    y = i + 2;
    a[i] = x, b[i] = i + 2;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  dfs(1, 0);
  int curc1 = 1, curc2 = 1, curleaf1 = 1, curleaf2 = 1;
  for (i = 2; i <= n; i++) {
    int curdist = dist(curleaf1, curleaf2);
    if (dist(i, curleaf2) > curdist) {
      curleaf1 = i;
      curdist++;
    } else if (dist(i, curleaf1) > curdist) {
      curleaf2 = i;
      curdist++;
    }
    curl1[i] = curleaf1;
    curl2[i] = curleaf2;
    dst[i] = curdist;
  }
  for (i = 1; i <= n; i++) {
    int l = max(2, i), r = n;
    if (max(dist(i, curl1[l]), dist(i, curl2[l])) != dst[l]) continue;
    while (l < r) {
      int mid = (l + r + 1) / 2;
      int mm1 = dist(curl1[mid], i);
      int mm2 = dist(curl2[mid], i);
      if (max(mm1, mm2) == dst[mid])
        l = mid;
      else
        r = mid - 1;
    }
    ans[max(i, 2)]++;
    ans[l + 1]--;
  }
  for (i = 2; i <= n; i++) {
    ans[i] += ans[i - 1];
    printf("%d\n", ans[i]);
  }
  return 0;
}
