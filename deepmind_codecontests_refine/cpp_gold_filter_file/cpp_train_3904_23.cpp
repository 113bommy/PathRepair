#include <bits/stdc++.h>
int main() {
  int n, m, k;
  while (scanf("%d%d%d", &n, &m, &k) != EOF) {
    int x, y, yes = 0;
    while (k--) {
      scanf("%d%d", &x, &y);
      if (x <= 5 || x >= n - 4 || y <= 5 || y >= m - 4) yes = 1;
    }
    if (yes)
      puts("YES");
    else
      puts("NO");
  }
  return 0;
}
