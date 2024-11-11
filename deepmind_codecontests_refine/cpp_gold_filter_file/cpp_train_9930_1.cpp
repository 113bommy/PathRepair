#include <bits/stdc++.h>
int bir, bes, iki, unknown, m, n, komsu[1000001];
int main() {
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= m; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    komsu[a]++;
    komsu[b]++;
  }
  for (int i = 1; i <= n; i++) {
    if (komsu[i] == 1) {
      bir++;
      continue;
    }
    if (komsu[i] == 2) {
      iki++;
      continue;
    }
    if (komsu[i] == m) {
      bes++;
      continue;
    }
    printf("unknown topology");
    return 0;
  }
  if (bes == 1) {
    printf("star topology");
    return 0;
  }
  if (iki && bir) {
    printf("bus topology");
    return 0;
  }
  printf("ring topology");
  return 0;
}
