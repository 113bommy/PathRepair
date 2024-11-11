#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, k, x, y;
  scanf("%d%d%d", &n, &m, &k);
  int a[k][2];
  for (int i = 0; i < k; i++) scanf("%d%d", &a[i][0], &a[i][1]);
  printf("%d\n", n + m - 2 + n * m);
  for (int i = 0; i < m - 1; i++) printf("L");
  for (int i = 0; i < n - 1; i++) printf("U");
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < m - 1; j++) {
      if (i % 2)
        printf("L");
      else
        printf("R");
    }
    printf("D");
  }
  printf("\n");
}
