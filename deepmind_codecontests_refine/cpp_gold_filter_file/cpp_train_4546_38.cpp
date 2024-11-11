#include <bits/stdc++.h>
int main() {
  int n;
  scanf("%d", &n);
  if (n == 1 || n == 2)
    printf("%d", n);
  else
    printf("%d", n / 2 + 1);
}
