#include <bits/stdc++.h>
using namespace std;
int a[2001], b[2001][2001];
using namespace std;
int main() {
  int i, j, k, n, l;
  while (scanf("%d", &n) == 1) {
    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));
    for (i = 1; i <= n; i++) {
      scanf("%d", &k);
      a[k]++;
      for (j = 1;; j++) {
        if (b[k][j] == 0) {
          b[k][j] = i;
          break;
        }
      }
    }
    k = 0;
    for (i = 1; i < 2001; i++) {
      if (a[i] > 1) {
        k++;
        if (a[i] > 2) {
          k++;
          break;
        }
      }
    }
    if (k == 2) {
      printf("YES\n");
      for (i = 0; i < 3; i++) {
        int t = 0;
        for (j = 1; j < 2001; j++) {
          for (l = 1;; l++) {
            if (b[j][l] != 0)
              printf("%d ", b[j][l]);
            else {
              if (a[j] > 1 && t == 0) {
                t = 1;
                for (k = 1; k < l - 1; k++) {
                  swap(b[j][k], b[j][k + 1]);
                }
                a[j]--;
              }
              break;
            }
          }
        }
        printf("\n");
      }
    } else
      printf("NO\n");
  }
}
