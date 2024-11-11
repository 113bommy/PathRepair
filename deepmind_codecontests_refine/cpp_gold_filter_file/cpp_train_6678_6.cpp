#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  int a[200100], b[200100], max = 1, num = -1;
  memset(b, 0, sizeof(b));
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
    b[a[i]]++;
    if (b[a[i]] >= max) {
      max = b[a[i]];
      num = a[i];
    }
  }
  printf("%d\n", (n - max));
  for (int k = 1; k < n; k++) {
    if (a[k] != num && a[k - 1] == num) {
      if (a[k] > a[k - 1]) {
        printf("2 %d %d\n", k + 1, k);
      } else if (a[k] < a[k - 1]) {
        printf("1 %d %d\n", k + 1, k);
      }
      a[k] = a[k - 1];
    }
  }
  for (int x = n - 1; x >= 0; x--) {
    if (a[x] != num && a[x + 1] == num) {
      if (a[x] > a[x + 1]) {
        printf("2 %d %d\n", x + 1, x + 2);
      } else if (a[x] < a[x + 1]) {
        printf("1 %d %d\n", x + 1, x + 2);
      }
      a[x] = a[x + 1];
    }
  }
  return 0;
}
