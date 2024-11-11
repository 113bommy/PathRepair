#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, i, j;
  while (scanf("%d%d", &n, &k) != EOF) {
    int x = n * k;
    if (n / 2 == 0 && k >= n / 2) {
      printf("-1\n");
      continue;
    } else if (k > n / 2) {
      printf("-1\n");
      continue;
    }
    printf("%d\n", n * k);
    for (i = 1; i <= n; i++) {
      for (j = 1; j <= k; j++) {
        int y;
        if ((i + j) % n == 0)
          y = n;
        else
          y = (i + j) % n;
        printf("%d %d\n", i, y);
      }
    }
  }
  return 0;
}
