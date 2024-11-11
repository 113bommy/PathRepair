#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, s, i, j, k, d[510][510] = {1000000007}, c[510][510],
                        cnt[510][510] = {0};
  scanf("%d%d", &n, &m);
  for (i = 1; i <= n; ++i)
    for (j = 1; j <= n; ++j) c[i][j] = d[i][j] = 1000000007;
  while (m--) {
    scanf("%d%d%d", &i, &j, &s);
    c[i][j] = c[j][i] = d[i][j] = d[j][i] = s;
  }
  for (i = 1; i <= n; ++i) d[i][i] = 0;
  for (i = 1; i <= n; ++i)
    for (j = 1; j <= n; ++j)
      for (k = 1; k <= n; ++k) d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
  for (i = 1; i <= n; ++i)
    for (j = 1; j <= n; ++j) {
      if (d[i][j] < 1000000007) {
        for (k = 1; k <= n; ++k)
          if (d[i][k] < 1000000007 && c[k][j] < 1000000007 &&
              d[i][k] + c[k][j] == d[i][j])
            ++cnt[i][j];
      }
    }
  for (i = 1; i <= n; ++i)
    for (j = i + 1; j <= n; ++j) {
      int co = 0;
      for (k = 1; k <= n; ++k)
        if (d[i][k] + d[k][j] == d[i][j]) co += cnt[i][k];
      printf("%d ", co);
    }
}
