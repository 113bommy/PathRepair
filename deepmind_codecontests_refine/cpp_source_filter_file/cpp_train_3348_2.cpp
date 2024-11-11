#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 5;
int dp[N][25], pos[25], a[N];
int main() {
  int n, q;
  scanf("%d%d", &n, &q);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    for (int j = 0; j <= 20; j++) {
      if (a[i] & (1 << j))
        dp[i][j] = i;
      else {
        for (int k = 0; k <= 20; k++)
          if (a[i] & (1 << k)) dp[i][j] = max(dp[i][j], dp[pos[k]][j]);
      }
    }
    for (int j = 0; j <= 20; j++)
      if (a[i] & (1 << j)) pos[j] = i;
  }
  while (q--) {
    int x, y;
    scanf("%d%d", &x, &y);
    int f = 0;
    for (int i = 0; i <= 20; i++)
      if (x & (1 << i) && dp[y][i] >= x) f = 1;
    printf("%s\n", f ? "Shi" : "Fou");
  }
  return 0;
}
