#include <bits/stdc++.h>
int main() {
  int n;
  scanf("%d", &n);
  int odd = 0, even = 0;
  for (int i = 0; i < n; i++) {
    int x;
    scanf("%d", &x);
    if (x & 1)
      odd++;
    else
      even++;
  }
  if (odd <= even) {
    printf("%d", odd);
    return 0;
  }
  if (odd > even) {
    int x = odd - even;
    printf("%d", even + odd / 3);
    return 0;
  }
  return 0;
}
