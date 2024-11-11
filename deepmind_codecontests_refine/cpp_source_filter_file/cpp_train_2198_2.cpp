#include <bits/stdc++.h>
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int b;
    scanf("%d", &b);
    int result, k;
    while (b > 0) {
      k += b & 1;
      b /= 2;
    }
    result = pow(2, k);
    printf("%d\n", result);
  }
}
