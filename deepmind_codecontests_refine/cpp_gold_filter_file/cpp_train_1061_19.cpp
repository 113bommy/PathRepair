#include <bits/stdc++.h>
int n, feet, inch;
int main() {
  scanf("%d", &n);
  feet = n / 36;
  inch = (n % 36) / 3;
  if ((n % 36) % 3 * 2 >= 3) ++inch;
  feet += (inch / 12);
  inch %= 12;
  printf("%d %d\n", feet, inch);
  return 0;
}
