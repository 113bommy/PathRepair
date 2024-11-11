#include <bits/stdc++.h>
int main() {
  int n, i, x, c = 0, bi = 0, ba = 0;
  scanf("%d", &n);
  for (i = 3; i < n + 3; i++) {
    scanf("%d", &x);
    if (i % 3 == 0) {
      c = c + x;
    }
    if (i % 3 == 1) {
      bi = bi + x;
    }
    if (i % 3 == 2) {
      ba = ba + x;
    }
  }
  if ((c > bi) && (c > ba)) {
    printf("chest");
  } else if ((bi > c) && (bi > ba)) {
    printf("biceps");
  } else {
    printf("back");
  }
  return (0);
}
