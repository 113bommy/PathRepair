#include <bits/stdc++.h>
using namespace std;
const int N = 25;
int a[N][N];
int n, k, t, l, r, mid;
bool vis[N];
int dfs(int i, int V) {
  if (i > n && V < mid)
    return 1;
  else if (V >= mid)
    return 0;
  int cnt = dfs(i + 1, V);
  if (cnt >= t) return t;
  for (int j = 1; j <= n; j++) {
    if (vis[j] == 0 && a[i][j]) {
      vis[j] = 1;
      cnt += dfs(i + 1, V + a[i][j]);
      vis[j] = 0;
    }
  }
  return cnt;
}
int main() {
  while (~scanf("%d%d%d", &n, &k, &t)) {
    memset(a, 0, sizeof a);
    memset(vis, 0, sizeof vis);
    for (int i = 0; i < k; i++) {
      int u, v, w;
      scanf("%d%d%d", &u, &v, &w);
      a[u][v] = w;
    }
    l = 0, r = 1000 * 20;
    while (l <= r) {
      mid = (l + r) >> 1;
      int z = dfs(1, 0);
      if (dfs(1, 0) >= t)
        r = mid - 1;
      else
        l = mid + 1;
    }
    printf("%d\n", r);
  }
  return 0;
}
