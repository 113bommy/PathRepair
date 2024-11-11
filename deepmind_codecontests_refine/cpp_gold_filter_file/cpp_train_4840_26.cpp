#include <bits/stdc++.h>
int main() {
  int n, x, f, cnt = 0, good[100];
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    f = 1;
    for (int j = 0; j < n; j++) {
      scanf("%d", &x);
      f &= x % 2 != 1;
    }
    if (f) good[cnt++] = i + 1;
  }
  printf("%d\n", cnt);
  for (int i = 0; i < cnt; i++) printf("%d%c", good[i], i + 1 < cnt ? 32 : 10);
  return 0;
}
