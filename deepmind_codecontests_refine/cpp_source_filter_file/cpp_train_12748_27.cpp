#include <bits/stdc++.h>
int main() {
  int n, s = 1, c = 0, x = 0, k;
  scanf("%d", &n);
  while (c < n - 1) {
    x = x + 1;
    s = s + x;
    if (s > n) {
      s = s - x;
      k = x - (n - s);
      s = k;
    }
    printf("%d", s);
    c++;
  }
}
