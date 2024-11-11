#include <bits/stdc++.h>
using namespace std;
int a[123456];
int main() {
  int n;
  scanf("%d", &n);
  int i;
  for (i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
  }
  if (n < 3 || (n % 2 == 0 && a[n])) {
    printf("-1\n");
    return 0;
  }
  int sum = 0;
  if (n % 2)
    for (i = n; i > 0; i -= 2) {
      if (a[i] > 0) {
        sum += a[i];
        a[i - 1] -= a[i];
        a[i / 2] -= a[i];
      }
      if (a[i - 1] > 0) {
        sum += a[i - 1];
        a[i / 2] -= a[i];
      }
    }
  else {
    for (i = n + 1; i > 0; i -= 2) {
      if (a[i] > 0) {
        sum += a[i];
        a[i - 1] -= a[i];
        a[i / 2] -= a[i];
      }
      if (a[i - 1] > 0) {
        sum += a[i - 1];
        a[i / 2] -= a[i];
      }
    }
  }
  printf("%d\n", sum);
  return 0;
}
