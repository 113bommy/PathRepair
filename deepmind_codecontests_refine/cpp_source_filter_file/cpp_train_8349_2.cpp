#include <bits/stdc++.h>
int main() {
  int t, h, m;
  scanf("%d", &t);
  for (int i = 1; i <= t; i++) {
    scanf("%d%d", &h, &m);
    printf("%d", (24 - h) * 60 + 60 - m);
  }
  return 0;
}
