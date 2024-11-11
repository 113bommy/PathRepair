#include <bits/stdc++.h>
int main() {
  int a, b;
  int s, k;
  while (~scanf("%d%d", &a, &b)) {
    int sum = 0;
    sum += a;
    s = a;
    while (s >= b) {
      k = s % b;
      s = s / b;
      sum = sum + s;
      s = s + k;
    }
    printf("%d\n", sum);
  }
  return 0;
}
