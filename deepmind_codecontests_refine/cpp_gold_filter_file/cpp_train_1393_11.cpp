#include <bits/stdc++.h>
int main() {
  int n;
  scanf("%d", &n);
  int sum = 0, d, f = 5;
  for (int i = 0; i < n; i++) {
    scanf("%d", &d);
    sum = sum + d;
  }
  for (int i = 1; i <= 5; i++) {
    if ((sum + i) % (n + 1) == 1) f--;
  }
  printf("%d", f);
}
