#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:50000000")
using namespace std;
int n, z = 0, x, y;
int a[105];
bool f;
int main() {
  scanf("%d", &n);
  if (n % 2 == 0 || n < 2) {
    printf("-1\n");
    return 0;
  }
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (int i = 1; i <= n; i++) {
    while (a[i] > 0) {
      x = 0;
      y = 0;
      f = 0;
      if (i * 2 + 1 <= n) {
        x = 1 + (a[i * 2] > 0) + (a[i * 2 + 1] > 0);
        f = 1;
      }
      if (i / 2 > 0) {
        y = (a[i / 2] > 0) + (a[(i / 2) * 2] > 0) + (a[(i / 2) * 2 + 1] > 0);
        f = 1;
      }
      if (f == 0) {
        printf("-1\n");
        return 0;
      }
      z++;
      if (x > y) {
        a[i]--;
        a[i * 2]--;
        a[i * 2 + 1]--;
      } else {
        a[i / 2]--;
        a[(i / 2) * 2]--;
        a[(i / 2) * 2 + 1]--;
      }
    }
  }
  printf("%d\n", z);
  return 0;
}
