#include <bits/stdc++.h>
int main() {
  int n;
  scanf("%d", &n);
  if (n == 1 || n == 2)
    printf("1");
  else
    printf("%d", n / 2 + 1);
}
