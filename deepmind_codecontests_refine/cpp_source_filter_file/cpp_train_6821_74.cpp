#include <bits/stdc++.h>
using namespace std;
int i, j, a, b, c, l, r, n, k, u, m, w, lim = 1000000, col[5001][2],
                                        ren[5001][2];
int main() {
  scanf("%d%d%d", &n, &m, &k);
  for (i = 1; i <= n; i++) {
    scanf("%d%d%d", &a, &b, &c);
    if (a == 1)
      ren[b][1] = c, ren[b][0] = i;
    else
      col[b][1] = c, col[b][0] = i;
  }
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= m; j++) {
      if (ren[i][0] > col[j][0])
        printf("%d ", ren[i][1]);
      else
        printf("%d ", col[j][1]);
    }
    printf("\n");
  }
}
