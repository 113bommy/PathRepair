#include <bits/stdc++.h>
int main() {
  int n, m, k;
  int a[20000 + 1][10 + 1] = {0};
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      scanf("%d", &a[i][j]);
    }
  }
  int group[10 + 1] = {0};
  int people[20000] = {0};
  for (int i = 0; i < k; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    group[y - 1]++;
    people[x - 1]++;
  }
  for (int i = 0; i < n; i++) {
    int ans = -group[i];
    for (int j = 0; j < m; j++) {
      if (a[i][j]) {
        ans += group[j];
      }
    }
    printf("%d", ans);
    if (i < n - 1) printf(" ");
  }
  printf("\n");
}
