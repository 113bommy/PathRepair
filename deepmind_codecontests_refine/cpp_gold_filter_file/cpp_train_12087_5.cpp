#include <bits/stdc++.h>
int main() {
  int i, n, array[1000];
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%d", &array[i]);
    if (array[i] == 1) {
      printf("HARD");
      return 0;
    }
  }
  printf("EASY");
  return 0;
}
