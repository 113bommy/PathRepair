#include <bits/stdc++.h>
int main() {
  int a, b;
  int temp;
  scanf("%d%d", &a, &b);
  while (a <= 100005) {
    temp = a % b;
    if (temp == 0) {
      printf("Yes\n");
      return 0;
    }
    a += temp;
  }
  printf("No\n");
  return 0;
}
