#include <bits/stdc++.h>
using namespace std;
int aa[105][105];
int main() {
  int n, a, b, c = 1, d = 2;
  scanf("%d%d%d", &n, &a, &b);
  if (a * b >= n) {
    for (int i = 0; i < a; i++) {
      for (int j = 0; j < b; j++) {
        if ((i + j) & 1) {
          if (d <= n) {
            printf("%d ", d);
            d += 2;
          } else
            printf("0 ");
        } else {
          if (c <= n) {
            printf("%d ", c);
            c += 2;
          } else
            printf("0 ");
        }
      }
      printf("\n");
    }
  } else
    printf("-1");
  return 0;
}
