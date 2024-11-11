#include <bits/stdc++.h>
int main(void) {
  int num, largenum = 0, i;
  scanf("%d", &num);
  for (int i = 1; i < num; i++) {
    int find = (pow(2, i) - 1) * pow(2, i - 1);
    if (find < num) {
      if (num % num == 0) {
        largenum = find;
      }
    } else {
      break;
    }
  }
  printf("%d", largenum);
  return 0;
}
