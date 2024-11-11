#include <bits/stdc++.h>
int main() {
  short n, i;
  scanf("%hu", &n);
  short year[n];
  for (i = 0; i < n - 1; i++) scanf("%hu", &year[i]);
  short a, b;
  scanf("%hu %hu", &a, &b);
  short total = 0;
  for (i = a - 1; i < b - 1; i++) total += year[i];
  printf("%d", total);
}
