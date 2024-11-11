#include <bits/stdc++.h>
int main() {
  int n;
  scanf("%d", &n);
  if (n % 5 == 0)
    printf("%d", n / 2);
  else
    printf("%d", n / 2 + 1);
}
