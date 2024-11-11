#include <bits/stdc++.h>
int map[1010][1010];
int a[1010][1010];
int main() {
  int n, i, t, j;
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%d", &t);
    map[i][i] = t;
    for (j = 0; j < i; j++) {
      map[j][i] = (map[j][i - 1] | t);
    }
  }
  int ans = -1;
  for (i = 0; i < n; i++) {
    scanf("%d", &t);
    a[i][i] = t;
    ans = ((ans) > (a[i][i] + map[i][i]) ? (ans) : (a[i][i] + map[i][i]));
    for (j = 0; j < i; j++) {
      a[j][i] = (a[j][i - 1] | t);
      ans = ((ans) > (a[j][i] + map[j][i]) ? (ans) : (a[j][i] + map[j][i]));
    }
  }
  printf("%d\n", ans);
}
