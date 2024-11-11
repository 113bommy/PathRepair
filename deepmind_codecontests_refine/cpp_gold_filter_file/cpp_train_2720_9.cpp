#include <bits/stdc++.h>
int main() {
  int n, fact = 0;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    fact = fact + i;
  }
  if (fact % 2 == 0) {
    printf("0");
  } else {
    printf("1");
  }
}
