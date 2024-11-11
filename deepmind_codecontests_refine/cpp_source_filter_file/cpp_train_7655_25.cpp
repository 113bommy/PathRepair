#include <bits/stdc++.h>
using namespace std;
int depth[100005];
int up[100005][25];
int father[100005];
int lca(int x, int y) {
  if (depth[x] < depth[y]) swap(x, y);
  int t = depth[x] - depth[y];
  int i;
  for (i = 0; i < 20; i++) {
    if ((1 << i) & t) t = up[t][i];
  }
  for (i = 19; i >= 0; i--) {
    if (up[x][i] == up[y][i]) continue;
    x = up[x][i];
    y = up[y][i];
  }
  return father[x];
}
int main() {
  int n;
  scanf("%d", &n);
  int i;
  int farest_point = 0;
  int farest_depth = 0;
  int ans = 0;
  for (i = 0; i < 20; i++) {
    up[0][i] = -1;
  }
  for (i = 1; i < n; i++) {
    int x;
    scanf("%d", &x);
    x--;
    father[i] = x;
    depth[i] = depth[x] + 1;
    int j;
    up[i][0] = x;
    for (j = 1; j < 20; j++) {
      if (up[i][j - 1] == -1) {
        up[i][j] = -1;
      } else {
        up[i][j] = up[up[i][j - 1]][j - 1];
      }
    }
    if (depth[i] > farest_depth) {
      farest_point = i;
      ans++;
      farest_depth++;
      printf("%d ", ans);
      continue;
    }
    int t = lca(i, farest_point);
    if (depth[i] - depth[t] + farest_depth - depth[t] > ans) {
      ans++;
    }
    printf("%d ", ans);
  }
  return 0;
}
