#include <bits/stdc++.h>
using namespace std;
int n, m, a[1005][1005], k, x, y, i, j, l, l1, ans, f = 0, b[1005], c[1005];
char s[3];
int main() {
  scanf("%d%d%d", &n, &m, &k);
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= m; j++) {
      scanf("%d", &a[i][j]);
      c[j] = j;
    }
    b[i] = i;
  }
  for (i = 1; i <= k; i++) {
    scanf("%s%d%d", s, &x, &y);
    if (s[0] == 'g') {
      printf("%d\n", a[b[x]][c[y]]);
    } else if (s[0] == 'c') {
      swap(b[x], b[y]);
    } else if (s[0] == 'r') {
      swap(c[x], c[y]);
    }
  }
  return 0;
}
