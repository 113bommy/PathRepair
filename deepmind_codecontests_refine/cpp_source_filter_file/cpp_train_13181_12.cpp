#include <bits/stdc++.h>
using namespace std;
int n, k;
bool vis[16];
int main() {
  scanf("%d", &n, &k);
  for (int i = 1, y; i <= n; i++) {
    y = 0;
    for (int j = 1, x; j <= k; j++) {
      scanf("%d", &x);
      y = (y << 1) + x;
    }
    vis[y] = 1;
  }
  for (int i = 0; i <= 15; i++)
    for (int j = 0; j <= 15; j++)
      if (vis[i] && vis[j] && !(i & j)) {
        printf("yes");
        return 0;
      }
  printf("no");
  return 0;
}
