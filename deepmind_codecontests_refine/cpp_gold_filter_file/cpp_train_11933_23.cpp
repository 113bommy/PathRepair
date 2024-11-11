#include <bits/stdc++.h>
int main(void) {
  int a;
  scanf("%d", &a);
  if (a == 1) {
    printf("1 1\n1");
  } else {
    printf("%d 2\n", (a - 1) * 2);
    printf("1 2");
  }
}
