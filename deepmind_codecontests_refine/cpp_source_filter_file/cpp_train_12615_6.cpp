#include <bits/stdc++.h>
using namespace std;
int Q, n, m, a[55][1005];
int f[10005], g[10005], h[10005];
struct node {
  int sum, id;
} l[1005];
bool cmp(node x, node y) { return x.sum > y.sum; }
int main() {
  scanf("%d", &Q);
  for (int x = 1; x <= Q; x++) {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++) l[i].sum = 0;
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= m; j++) {
        scanf("%d", &a[i][j]);
        l[j].sum = max(l[j].sum, a[i][j]);
        l[j].id = j;
        a[i + n][j] = a[i][j];
      }
    sort(l + 1, l + m + 1, cmp);
    memset(f, 0, sizeof(f));
    for (int i = 1; i <= min(n, m); i++) {
      for (int j = 0; j < (1 << n); j++) g[j] = f[j];
      for (int j = 1; j <= n; j++) {
        for (int k = 0; k < (1 << n); k++) f[k] = g[k];
        for (int k = 0; k < (1 << n); k++) {
          for (int r = 0; r < n; r++) {
            if ((k & (1 << r)) != 0)
              f[k] = max(f[k], f[k - (1 << r)] + a[j + r][l[i].id]);
          }
        }
        for (int k = 0; k < (1 << n); k++) h[k] = max(h[k], f[k]);
      }
      for (int j = 0; j < (1 << n); j++) {
        f[j] = h[j];
        h[j] = 0;
      }
    }
    printf("%d\n", f[(1 << n) - 1]);
  }
}
