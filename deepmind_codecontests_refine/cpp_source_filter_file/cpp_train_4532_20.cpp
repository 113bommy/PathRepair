#include <bits/stdc++.h>
using namespace std;
int G[20][20];
inline int count(int la, int ra, int lb, int rb) {
  int cnt = 0;
  for (int i = la; i <= ra; i++)
    for (int j = lb; j <= rb; j++)
      if (G[i][j]) cnt++;
  return cnt;
}
int main() {
  int r, c, n, k, x, y;
  scanf("%d%d%d%d", &r, &c, &n, &k);
  for (int i = 1; i <= n; i++) {
    scanf("%d%d", &x, &y);
    G[x][y] = 1;
  }
  int ans = 0;
  for (int i = 1; i <= r; i++)
    for (int j = i; j <= r; j++)
      for (int k = 1; k <= c; k++)
        for (int l = k; l <= c; l++)
          if (count(i, j, k, l) >= k) ans++;
  printf("%d\n", ans);
  return 0;
}
