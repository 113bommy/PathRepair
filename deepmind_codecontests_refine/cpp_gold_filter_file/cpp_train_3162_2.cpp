#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  while (scanf("%d", &n) != EOF) {
    int a[101][2];
    int map[101][101];
    int cnt[101];
    int x, y, c;
    memset(cnt, 0, sizeof(cnt));
    for (int i = 0; i < n; i++) {
      scanf("%d%d%d", &x, &y, &c);
      a[x][cnt[x]++] = y;
      a[y][cnt[y]++] = x;
      map[x][y] = 0;
      map[y][x] = c;
    }
    int res1 = 0;
    int v = 1, next;
    int vis[101];
    memset(vis, 0, sizeof(vis));
    vis[1] = 1;
    for (int i = 1; i < n; i++) {
      if (vis[a[v][0]]) {
        next = a[v][1];
      } else {
        next = a[v][0];
      }
      res1 += map[v][next];
      vis[next] = 1;
      v = next;
    }
    res1 += map[v][1];
    int res2 = 0;
    v = 1;
    memset(vis, 0, sizeof(vis));
    vis[1] = 1;
    for (int i = 1; i < n; i++) {
      if (vis[a[v][1]]) {
        next = a[v][0];
      } else {
        next = a[v][1];
      }
      res2 += map[v][next];
      vis[next] = 1;
      v = next;
    }
    res2 += map[v][1];
    printf("%d\n", min(res1, res2));
  }
  return 0;
}
