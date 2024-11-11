#include <bits/stdc++.h>
using namespace std;
int main(void) {
  int a[3];
  scanf("%d %d %d", &a[0], &a[1], &a[2]);
  int m1 = a[0], m2 = a[1], m3 = a[2];
  int k1 = 0, k2 = 0, k3 = 0;
  if ((m1 + m2 + m3) % 2 != 0) {
    printf("Impossible\n");
  } else {
    sort(a, a + 3);
    if (a[0] + a[1] < a[2]) {
      printf("Impossible\n");
    } else {
      if (a[0] == a[1] && a[1] == a[2]) {
        int temp = a[0] / 2;
        printf("%d %d %d\n", temp, temp, temp);
      } else {
        int kj = (a[0] + a[1] + a[2]) / 2;
        printf("%d %d %d\n", kj - m1, kj - m2, kj - m3);
      }
    }
  }
  return 0;
}
