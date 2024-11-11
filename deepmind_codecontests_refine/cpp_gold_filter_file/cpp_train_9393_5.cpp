#include <bits/stdc++.h>
int main() {
  int t, n;
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    if (n == 1) {
      printf("-1\n");
      continue;
    }
    if (n % 3 != 1) {
      for (int i = 0; i < n - 1; i++) printf("2");
      printf("3\n");
    } else {
      for (int i = 0; i < n - 2; i++) printf("2");
      printf("39\n");
    }
  }
}
