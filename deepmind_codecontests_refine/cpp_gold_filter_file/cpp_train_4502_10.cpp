#include <bits/stdc++.h>
int main() {
  int t;
  scanf("%d", &t);
  for (int i = 0; i < t; i++) {
    int v;
    scanf("%d", &v);
    if (v == 1 || v == 2) {
      printf("%d\n", 0);
    } else if (v % 2 == 0) {
      printf("%d\n", v / 2 - 1);
    } else {
      printf("%d\n", v / 2);
    }
  }
  return 0;
}
