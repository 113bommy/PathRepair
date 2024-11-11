#include <bits/stdc++.h>
int main() {
  int a;
  scanf("%d", &a);
  if (a == 5)
    printf("1\n");
  else
    printf("%d\n", a % 3 + 1);
  return 0;
}
