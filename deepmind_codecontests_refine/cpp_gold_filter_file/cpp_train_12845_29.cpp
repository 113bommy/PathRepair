#include <bits/stdc++.h>
int main() {
  int tot = 0, n, k;
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; i++)
    for (int j = i + 1; j <= n; j++) tot++;
  if (tot <= k)
    puts("no solution");
  else {
    for (int i = 1; i <= n; i++) printf("%d %d\n", i, i * (n + 1));
  }
}
