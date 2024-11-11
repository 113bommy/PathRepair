#include <bits/stdc++.h>
using namespace std;
int data[109][109];
int ans[109][34];
int main(void) {
  int i, j, k, n;
  while (scanf("%d", &n) == 1) {
    for (i = 1; i <= n; i++) {
      for (j = 1; j <= n; j++) {
        scanf("%d", &data[i][j]);
      }
    }
    for (i = 1; i <= n; i++) {
      for (j = 1; j <= n; j++) {
        if (j == i) continue;
        int t = data[i][j];
        for (k = 32; t > 0; k--) {
          if (t % 2 == 1) ans[i][k] = 1;
          t /= 2;
        }
      }
    }
    for (i = 1; i <= n; i++) {
      int tt = 0;
      int k = 1;
      for (j = 32; j >= 1; j--, k *= 2) {
        if (ans[i][j] == 1) tt += k;
      }
      printf("%d ", tt);
    }
  }
  return 0;
}
