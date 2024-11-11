#include <bits/stdc++.h>
int main() {
  int n, k;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &k);
    printf("%d\n", k / 2 + 1);
  }
  return 0;
}
