#include <bits/stdc++.h>
using namespace std;
int n, m, k, i, j, x[20000][2000], ans[20000], t, y, x1[20000], x2[2000];
int main() {
  scanf("%d%d%d", &n, &m, &k);
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) scanf("%d", &x[i][j]);
  }
  for (i = 0; i < k; i++) {
    scanf("%d%d", &t, &y);
    x1[y - 1]++;
    x2[t - 1]++;
  }
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++)
      if (x[i][j] == 1) ans[i] += x1[j];
    ans[i] -= x2[i];
  }
  for (i = 0; i < n; i++) printf("%d ", ans[i]);
}
