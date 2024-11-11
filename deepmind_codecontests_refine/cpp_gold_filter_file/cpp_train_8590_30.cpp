#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, d, h;
  cin >> n >> d >> h;
  if (d == h && d == 1 && n > 2) {
    printf("-1\n");
    return 0;
  }
  if (d + 1 <= n && 2 * h >= d) {
    for (int i = 1; i <= h; i++) {
      printf("%d %d\n", i, i + 1);
    }
    if (d != h) {
      printf("1 %d\n", h + 2);
      for (int i = 1; i < (d - h); i++) {
        printf("%d %d\n", h + i + 1, h + i + 2);
      }
      int k = n - d - 1;
      while (k) {
        printf("%d %d\n", 1, d + 1 + k);
        k--;
      }
    } else {
      int k = n - h - 1;
      while (k) {
        printf("2 %d\n", h + 1 + k);
        k--;
      }
    }
  } else {
    printf("-1\n");
  }
}
