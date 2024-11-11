#include <bits/stdc++.h>
int main() {
  int n;
  scanf("%d", &n);
  if (n & 1)
    printf("%d\n", n / 2);
  else {
    int t = 1;
    while (t < n) t <<= 1;
    printf("%d\n", n - t >> 1);
  }
}
