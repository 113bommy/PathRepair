#include <bits/stdc++.h>
using namespace std;
int a[10][10];
int b[10];
int main() {
  int n, m, i, j, k;
  while (scanf("%d%d", &n, &m) != EOF) {
    for (i = 0; i < n; i++) {
      scanf("%d", &k);
      for (j = 0; j < m; j++) {
        a[i][j] = k % 10;
        k /= 10;
      }
    }
    for (i = 0; i < m; i++) b[i] = i;
    int s = 999999999;
    do {
      int mi = 999999999, ma = 0;
      for (i = 0; i < n; i++) {
        k = 0;
        for (j = m - 1; j >= 0; j--) {
          k *= 10;
          k += a[i][b[j]];
        }
        if (mi > k) mi = k;
        if (ma < k) ma = k;
      }
      if (s > ma - mi) s = ma - mi;
    } while (next_permutation(b, b + m));
    printf("%d\n", s);
  }
}
