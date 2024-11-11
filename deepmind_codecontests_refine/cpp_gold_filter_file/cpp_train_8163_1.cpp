#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[1100][1100];
int r[1100], c[1100];
int main() {
  int i, j, k, o = 1;
  while (~scanf("%d", &n)) {
    int ans = 0;
    memset(r, 0, sizeof(r));
    memset(c, 0, sizeof(c));
    for (i = 1; i <= n; i++) {
      for (j = 1; j <= n; j++) scanf("%d", &a[i][j]);
    }
    for (i = 1; i <= n; i++) {
      for (j = 1; j <= n; j++) ans = (ans + (a[i][j] * a[j][i])) % 2;
    }
    int q;
    scanf("%d", &q);
    while (q--) {
      int num, u, v;
      scanf("%d", &num);
      if (num == 1) {
        scanf("%d", &u);
        v = (r[u] + c[u]) % 2;
        v ^= a[u][u];
        if (v == 1)
          ans = ((ans - 1) + 2) % 2;
        else
          ans = (ans + 1) % 2;
        r[u]++;
      } else if (num == 2) {
        scanf("%d", &u);
        v = (r[u] + c[u]) % 2;
        v ^= a[u][u];
        if (v == 1)
          ans = ((ans - 1) + 2) % 2;
        else
          ans = (ans + 1) % 2;
        c[u]++;
      } else
        printf("%d", ans);
    }
    puts("");
  }
  return 0;
}
