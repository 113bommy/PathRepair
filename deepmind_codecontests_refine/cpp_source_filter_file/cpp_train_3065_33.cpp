#include <bits/stdc++.h>
using namespace std;
int d[310][110000];
int a1[110000];
int a2[110000];
int first[110000];
int main() {
  int i, j, m, n, s, e, ans, k, last;
  scanf("%d%d%d%d", &m, &n, &s, &e);
  for (i = 0; i < m; i++) scanf("%d", &a1[i]);
  for (i = 0; i < n; i++) scanf("%d", &a2[i]);
  memset(d, -1, sizeof(d));
  d[0][0] = 0;
  ans = 0;
  for (i = 0; i < 305; i++) {
    memset(first, -1, sizeof(first));
    last = n + 1;
    for (j = 1; j <= m; j++) {
      if (d[i][j - 1] != -1) {
        for (k = last - 1; k >= d[i][j - 1]; k--) first[a2[k - 1]] = k;
        if (d[i][j - 1] < last) last = d[i][j - 1];
      }
      if (first[a1[j - 1]] != -1) {
        d[i + 1][j] = first[a1[j - 1]];
        if ((i + 1 > ans) && ((i + 1) * e + first[a1[j - 1]] + j <= s))
          ans = i + 1;
      }
    }
  }
  printf("%d\n", ans);
  return 0;
}
