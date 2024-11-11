#include <bits/stdc++.h>
using namespace std;
int main() {
  int k;
  scanf("%d", &k);
  if (k < 18) {
    for (int i = 0; i < k; i++) {
      printf("4");
    }
    printf("\n");
  } else if (k >= 18 && k < 36) {
    if (k % 2 == 0) {
      for (int i = 0; i < k / 2; i++) {
        printf("8");
      }
      printf("\n");
    } else {
      for (int i = 0; i < k / 2; i++) {
        printf("8");
      }
      printf("0\n");
    }
  } else {
    printf("-1\n");
  }
}
