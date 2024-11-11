#include <bits/stdc++.h>
using namespace std;
int n, m, b[101][101] = {0}, a[101][101] = {0};
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      scanf("%d", &b[i][j]);
      a[i][j] = 1;
    }
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      if (b[i][j] == 0) {
        for (int g = 1; g <= m; g++) a[i][g] = 0;
        for (int g = 1; g <= n; g++) a[g][j] = 0;
      }
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      int sum = 0;
      for (int g = 1; g <= m; g++) sum += a[i][g];
      for (int g = 1; g <= n; g++) sum += a[g][j];
      if (b[i][j] == 1 && sum == 0) {
        printf("NO");
        return 0;
      }
    }
  printf("YES\n");
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) printf("%d ", a[i][j]);
    printf("\n");
  }
}
