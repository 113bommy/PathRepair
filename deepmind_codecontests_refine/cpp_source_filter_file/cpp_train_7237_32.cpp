#include <bits/stdc++.h>
int main() {
  int n, m;
  while (~scanf("%d%d", &n, &m)) {
    int y;
    if (m >> 1 & 1)
      y = 1 + (n - m) / 2;
    else {
      y = (m + 1) / 2;
    }
    printf("%d\n", y);
  }
  return 0;
}
