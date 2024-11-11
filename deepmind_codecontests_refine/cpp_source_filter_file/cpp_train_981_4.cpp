#include <bits/stdc++.h>
int spider[4000000];
int ans[20000];
char map[20000];
int main() {
  memset(ans, 0, sizeof(0));
  int n, m, i, j;
  int k;
  scanf("%d%d%d", &n, &m, &k);
  for (i = 1; i <= n; i++) {
    scanf("%s", map);
    for (j = 0; map[j] != '\0'; j++) {
      if (map[j] == 'L')
        if (j - i + 2 >= 1) ans[j - i + 2]++;
      if (map[j] == 'R')
        if (j + i <= m) ans[j + i]++;
      if (map[j] == 'U')
        if (i % 2 != 0) ans[j + 1]++;
    }
  }
  for (i = 1; i < n; i++) printf("%d ", ans[i]);
  printf("%d\n", ans[n]);
  return 0;
}
