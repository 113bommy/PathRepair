#include <bits/stdc++.h>
int main() {
  int n, p[8], total = 0, day;
  scanf("%d", &n);
  for (int i = 1; i < 8; i++) {
    scanf("%d", &p[i]);
  }
  while (total <= n) {
    for (int i = 1; i < 8; i++) {
      if (total <= n) {
        total += p[i];
        day = i;
      }
    }
  }
  printf("%d", day);
  return 0;
}
