#include <bits/stdc++.h>
using namespace std;
int n;
int ans[3][100010];
int vis[100010];
int main() {
  while (scanf("%d", &n) != EOF) {
    if (n % 2 == 0) {
      printf("-1\n");
      continue;
    }
    memset(vis, 0, sizeof(vis));
    for (int i = 0; i < n; i++) ans[0][i] = i;
    for (int i = n - 1; i >= 0; i--) ans[1][n - i - 1] = i;
    int flag = 0;
    for (int i = 0; i < n; i++) {
      if (i < n / 2)
        ans[2][i] = n + ans[0][i] - ans[1][i];
      else
        ans[2][i] = ans[0][i] - ans[1][i];
    }
    for (int i = 2; i >= 0; i--) {
      for (int j = 0; j < n; j++) {
        printf("%d ", ans[i][j]);
      }
      printf("\n");
    }
  }
}
