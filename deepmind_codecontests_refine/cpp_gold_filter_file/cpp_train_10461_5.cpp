#include <bits/stdc++.h>
int main() {
  int cost, ammount, want, i, j;
  int x = 0;
  int y = 0;
  int need;
  scanf("%d %d %d", &cost, &ammount, &want);
  for (int i = 1; i <= want; i++) {
    x = i * cost;
    y = x + y;
  }
  need = y - ammount;
  if (need < 0) {
    need = 0;
    printf("%d", need);
  } else {
    printf("%d", need);
  }
  return 0;
}
