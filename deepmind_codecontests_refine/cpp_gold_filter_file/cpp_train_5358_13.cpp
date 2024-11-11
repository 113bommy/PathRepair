#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, s, i;
  scanf("%d", &a);
  scanf("%d", &b);
  if (a == 0) {
    for (i = b + 1; i >= 1; i--) {
      printf("%d ", i);
    }
    scanf("\n");
  } else {
    if (a == 1 && b != 1) {
      printf("1 ");
      for (i = a + 2; i <= a + b + 1; i++) {
        printf("%d ", i);
      }
      for (i = a + 1; i >= 2; i--) {
        printf("%d ", i);
      }
      scanf("\n");
    } else if (b == 1 && a != 1) {
      for (i = 2; i <= a + b + 1; i++) {
        printf("%d ", i);
      }
      printf("1\n");
    } else if (a == 1 && b == 1) {
      printf("2 3 1 ");
    } else {
      for (i = b + 1; i <= a + b + 1; i++) {
        printf("%d ", i);
      }
      for (i = b; i >= 1; i--) {
        printf("%d ", i);
      }
      scanf("\n");
    }
  }
  return 0;
}
