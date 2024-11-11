#include <bits/stdc++.h>
using namespace std;
const int MAXN = 3e2 + 5;
int n;
int O[MAXN][MAXN], Alex[MAXN];
bool vis[MAXN];
int r[MAXN];
int main() {
  while (~scanf("%d", &n)) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        scanf("%d", &O[i][j]);
      }
    }
    int x;
    for (int i = 1; i <= n; i++) {
      scanf("%d", &x);
      Alex[x] = i;
    }
    for (int i = 1; i <= n; i++) {
      memset(vis, false, sizeof(vis));
      int o = -1;
      for (int j = 1; j <= n; j++) {
        if (i == j) continue;
        if (o != -1 && Alex[j] > Alex[o]) continue;
        o = j;
        vis[j] = true;
      }
      for (int j = 1; j <= n; j++) {
        if (vis[O[i][j]]) {
          r[i] = O[i][j];
          break;
        }
      }
    }
    for (int i = 1; i <= n; i++) {
      printf("%d%c", r[i], i == n ? '\n' : ' ');
    }
  }
  return 0;
}
