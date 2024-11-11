#include <bits/stdc++.h>
int main() {
  int x, y;
  scanf("%d%d", &x, &y);
  int c = 0;
  if (y % 2 == 1) {
    for (int i = 1; i <= y; i += 2) {
      c++;
    }
  } else {
    for (int i = x; i >= 2; i -= 2) {
      c++;
    }
  }
  printf("%d", c);
}
