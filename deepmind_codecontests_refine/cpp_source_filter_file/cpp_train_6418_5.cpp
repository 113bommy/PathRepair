#include <bits/stdc++.h>
int main() {
  int n;
  int B = 0, C = 0;
  int result = 0;
  scanf("%d", &n);
  for (int i = 1; i < n; i++) {
    int a;
    scanf("%d", &a);
    if (a >= 0) {
      B = B + a;
    } else {
      C = C + a;
    }
  }
  result = B - C;
  printf("%d", result);
  return 0;
}
