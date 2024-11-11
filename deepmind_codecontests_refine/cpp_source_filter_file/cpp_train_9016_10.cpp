#include <bits/stdc++.h>
using namespace std;
int a[100005], b[100005], c[100005];
int main() {
  int n, i, j, k, m, ok, tot;
  while (scanf("%d%d%d", &n, &k, &m) != EOF) {
    memset(b, 0, sizeof(b));
    ok = 0;
    for (i = 0; i < n; i++) {
      scanf("%d", &a[i]);
      b[a[i] % m]++;
    }
    for (i = 0; i < m; i++) {
      if (b[i] >= k) {
        tot = 0;
        ok = 1;
        for (j = 0; j < n; j++) {
          if (a[j] % m == i) {
            c[tot++] = a[j];
          }
          if (tot == k) break;
        }
        if (tot == k) break;
      }
    }
    if (ok == 0)
      printf("No\n");
    else {
      printf("Yes\n");
      printf("%d", a[0]);
      for (i = 1; i < k; i++) printf(" %d", c[i]);
      printf("\n");
    }
  }
  return 0;
}
