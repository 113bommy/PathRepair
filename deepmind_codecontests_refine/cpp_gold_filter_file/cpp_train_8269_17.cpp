#include <bits/stdc++.h>
int main() {
  int n;
  scanf("%d", &n);
  int c = 0, a, b;
  for (int i = 0; i < n; i++) {
    scanf("%d %d", &a, &b);
    if (a != b) {
      c = 1;
    }
  }
  if (c == 0) {
    printf("Poor Alex");
  } else {
    printf("Happy Alex");
  }
}
