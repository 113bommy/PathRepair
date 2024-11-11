#include <bits/stdc++.h>
using namespace std;
int vis[110];
int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  int i, j;
  for (i = 1; i <= n; i++) {
    int x;
    scanf("%d", &x);
    for (j = 1; j <= x; j++) {
      int y;
      scanf("%d", &y);
      vis[y] = 1;
    }
  }
  for (i = 1; i <= n; i++) {
    if (vis[i] == 0) {
      printf("NO\n");
      return 0;
    }
  }
  printf("YES\n");
  return 0;
}
