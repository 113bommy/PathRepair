#include <bits/stdc++.h>
using namespace std;
int main() {
  int a[111111] = {0};
  int n, i;
  scanf("%d", &n);
  for (i = 0; i < n; i++) scanf("%d", &a[i]);
  sort(a, a + n);
  if (n == 1) {
    if (a[0] == 1)
      printf("2\n");
    else
      printf("1\n");
  } else {
    if (a[n - 1] == 1) {
      a[n - 1] = 2;
      printf("%d", a[0]);
      for (i = 1; i < n; i++) printf(" %d", a[i]);
      printf("\n");
    } else {
      printf("1");
      for (i = 0; i < n - 1; i++) printf(" %d", a[i]);
      printf("\n");
    }
  }
  return 0;
}
