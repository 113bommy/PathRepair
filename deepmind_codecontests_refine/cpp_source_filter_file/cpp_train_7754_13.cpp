#include <bits/stdc++.h>
int main() {
  int n;
  scanf("%d", &n);
  int i = sqrt(n);
  for (int i = 1; i <= 10; i++) {
    if (pow(2, i) == n) {
      printf("YES");
      return 0;
    }
  }
  printf("NO");
  return 0;
}
