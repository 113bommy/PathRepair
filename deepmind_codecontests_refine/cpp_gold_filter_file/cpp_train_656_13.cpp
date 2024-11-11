#include <bits/stdc++.h>
int main() {
  int n, res = 0;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    int help;
    scanf("%d", &help);
    res += help * (i + 1);
  }
  printf("%d\n", res);
  return 0;
}
