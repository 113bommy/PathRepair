#include <bits/stdc++.h>
int num[5];
int main() {
  int i, big;
  for (i = 0; i < 4; i++) {
    scanf("%d", &num[i]);
  }
  big = num[0];
  for (i = 1; i < 4; i++) {
    if (num[i] > num[i - 1]) {
      big = num[i];
    }
  }
  for (i = 0; i < 4; i++) {
    if ((big - num[i]) > 0) {
      printf("%d ", (big - num[i]));
    }
  }
  return 0;
}
