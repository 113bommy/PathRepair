#include <bits/stdc++.h>
using namespace std;
int a[10005][2];
int main() {
  int n;
  while (~scanf("%d", &n)) {
    for (int i = 0; i < n * n / 2; i++) {
      a[i][0] = i + 1;
      a[n * n / 2 - i - 1][1] = n * n / 2 + i + 1;
    }
    for (int j = 0; j < n * n / 2; j++) {
      printf("%d %d", a[j][0], a[j][1]);
      if ((j + 1) % (n / 2) != 0) {
        printf(" ");
      }
      if ((j + 1) % (n / 2) == 0) {
        printf("\n");
      }
    }
  }
  return 0;
}
