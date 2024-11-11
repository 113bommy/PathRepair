#include <bits/stdc++.h>
int a, b, i = 1;
int main() {
  scanf("%d%d", &a, &b);
  if (a == 1 && b == 10)
    printf("-1");
  else {
    printf("%d", b);
    if (b == 10) i++;
    for (i = 1; i < a; i++) printf("0");
  }
}
