#include <bits/stdc++.h>
int tm[10][100008], a[100008];
long long ans[100008], t[100008];
int main() {
  int n, m, op;
  while (~scanf("%d%d%d", &n, &m, &op)) {
    for (int i = 1; i <= n; i++) {
      scanf("%d", &a[i]);
    }
    memset(ans, 0, sizeof(ans));
    memset(t, 0, sizeof(t));
    for (int i = 1; i <= m; i++) {
      scanf("%d%d%d", &tm[0][i], &tm[1][i], &tm[2][i]);
    }
    int x, y, z;
    while (op--) {
      scanf("%d%d", &x, &y);
      ans[y + 1]--;
      ans[x]++;
    }
    for (int i = 1; i <= m; i++) ans[i] += ans[i - 1];
    for (int i = 1; i <= m; i++) {
      x = tm[0][i];
      y = tm[1][i];
      z = tm[2][i];
      long long pk = 1;
      long long qq = (long long)z * ans[i];
      t[y + 1] -= qq;
      t[x] += qq;
    }
    for (int i = 1; i <= n; i++) t[i] += t[i - 1];
    for (int i = 1; i <= n; i++) printf("%lld ", t[i] + a[i]);
    printf("\n");
  }
}
