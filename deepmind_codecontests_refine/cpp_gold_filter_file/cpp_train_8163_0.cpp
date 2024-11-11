#include <bits/stdc++.h>
using namespace std;
int t, ar[1009][1009], i, j, k, l, m, n, a, b, c, ans, q, br[1000009];
int main() {
  scanf("%d", &n);
  for (i = 1; i <= n; i++)
    for (j = 1; j <= n; j++) scanf("%d", &ar[i][j]);
  ans = 0;
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= n; j++) {
      ans = ans + ar[i][j] * ar[j][i];
    }
  }
  ans = ans % 2;
  t = 0;
  scanf("%d", &q);
  while (q--) {
    scanf("%d", &k);
    if (k != 3) {
      scanf("%d", &a);
      if (ans == 0)
        ans = 1;
      else
        ans = 0;
    } else {
      br[t] = ans;
      t++;
    }
  }
  for (i = 0; i < t; i++) printf("%d", br[i]);
  printf("\n");
  return 0;
}
