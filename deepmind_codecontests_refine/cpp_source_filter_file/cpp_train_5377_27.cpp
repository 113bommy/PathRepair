#include <bits/stdc++.h>
int main() {
  int e, l, count;
  scanf("%d", &e);
  for (l = 1; l <= (e / 2); l++) {
    if ((e - l) % l == 0) {
      count++;
    }
  }
  printf("%d", count);
}
