#include <bits/stdc++.h>
int main() {
  int i, h, m, t;
  scanf("%d", &t);
  for (i = 0; i < t; i++) {
    scanf("%d%d", &h, &m);
    printf("%d\n", ((24 - t) * 60 - m));
  }
}
