#include <bits/stdc++.h>
int main() {
  int x;
  while (scanf("%d", &x) != EOF) {
    printf("%d\n", (x / 2) * ((x + 1) / 2));
    for (int i = 1; i <= x / 2; i++)
      for (int j = 1 + x / 2; j <= x; j++) printf("%d %d\n", i, j);
  }
  return 0;
}
