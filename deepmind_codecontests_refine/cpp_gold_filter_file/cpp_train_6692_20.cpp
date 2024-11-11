#include <bits/stdc++.h>
using namespace std;
int main() {
  int k, a;
  int arr[36] = {1, 2, 3, 4, 1, 2, 3, 4, 1, 2, 3, 4, 1, 2, 3, 4, 1, 2,
                 3, 4, 1, 2, 3, 4, 1, 2, 3, 4, 1, 2, 3, 4, 1, 2, 3, 4};
  scanf("%d", &k);
  for (int i = 0; i < k; i++) {
    int e;
    scanf("%d", &a);
    if (a <= 9) {
      e = 4 * (a - 1);
    } else {
      if (a <= 99) {
        a = a / 11;
        e = 4 * (a - 1) + 1;
      } else {
        if (a <= 999) {
          a = a / 111;
          e = 4 * (a - 1) + 2;
        } else {
          if (a <= 9999) {
            a = a / 1111;
            e = 4 * (a - 1) + 3;
          }
        }
      }
    }
    int g = 0;
    for (int j = 0; j <= e; j++) {
      g = g + arr[j];
    }
    printf("%d\n", g);
  }
}
