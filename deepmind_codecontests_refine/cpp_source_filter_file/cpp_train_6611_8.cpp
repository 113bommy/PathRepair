#include <bits/stdc++.h>
int main() {
  int i, j, n, m, ans = 1;
  scanf("%d%d", &n, &m);
  int a[m], f[1000005], b;
  for (i = 0; i < n; i++) {
    scanf("%d", &b);
    if (f[b] == 0)
      f[b] = i + 1;
    else
      f[b] = -1;
  }
  for (i = 0; i < m; i++) {
    if (ans != 1) break;
    scanf("%d", &b);
    if (f[b] == 0)
      ans = -1;
    else if (f[b] == -1)
      ans = 0;
    else
      a[i] = f[b];
  }
  if (ans == 1) {
    printf("Possible\n");
    for (i = 0; i < m; i++) printf("%d ", a[i]);
  } else if (ans == 0)
    printf("Ambiguity");
  else
    printf("Impossible");
}
