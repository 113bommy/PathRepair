#include <bits/stdc++.h>
using namespace std;
int H[1004][1004];
int main() {
  int x, y, z, i, j;
  int n, m, k, s = 0;
  scanf("%d %d", &n, &k);
  if (n / 2 <= k) {
    printf("-1");
    return 0;
  }
  printf("%d\n", n * k);
  for (i = 1; i <= n; i++) {
    s = 0;
    for (j = 1; s != k && j <= n; j++)
      if (!H[i][j] && i != j) {
        printf("%d %d\n", i, j);
        s++;
        H[i][j] = 1;
        H[j][i] = 1;
      }
  }
}
