#include <bits/stdc++.h>
int main() {
  int t, n, m, p, r;
  scanf("%d", &t);
  while (t--) {
    scanf("%d%d", &n, &m);
    if (n == 1 || m == 3 || (n == 2 && m == 2))
      printf("YES\n");
    else
      printf("NO\n");
  }
}
