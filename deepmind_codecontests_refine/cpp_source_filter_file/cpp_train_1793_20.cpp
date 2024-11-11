#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 10;
int n, m, x, y;
int a[N][10];
int vis[1 << 8];
int judge(int z) {
  memset(vis, 0, sizeof(vis));
  for (int i = 1; i <= n; i++) {
    int t = 0;
    for (int j = 0; j < m; j++) {
      if (a[i][j] >= z) {
        t = t | 1 << j;
      }
    }
    vis[t] = i;
  }
  for (int i = 0; i < (1 << m); i++) {
    for (int j = i; j < (1 << m); j++) {
      if ((i | j) == (1 << m) - 1 && vis[i] && vis[j]) {
        x = vis[i];
        y = vis[j];
        return 1;
      }
    }
  }
  return 0;
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < m; j++) {
      scanf("%d", &a[i][j]);
    }
  }
  int l = 1, r = 30000, mid;
  while (l <= r) {
    mid = (l + r) / 2;
    if (judge(mid))
      l = mid + 1;
    else
      r = mid - 1;
  }
  printf("%d %d", x, y);
  return 0;
}
