#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i, j, k, a[100005];
  scanf("%d", &n);
  for (i = 0; i < n; i++) scanf("%d", &a[i]);
  if (a[n - 1] == 1) {
    printf("NO\n");
    return 0;
  }
  if (n == 1) {
    printf("YES\n");
    printf("0\n");
    return 0;
  }
  if (n == 2) {
    if (a[n - 2] == 1)
      printf("YES\n1->0\n");
    else
      printf("NO\n");
    return 0;
  }
  if (a[n - 2] == 0 && a[n - 3] == 1) {
    for (i = n - 3; i >= 0; i--)
      if (a[i] == 0) break;
    if (i == -1)
      printf("NO\n");
    else {
      printf("YES\n");
      for (j = 0; j < i; j++) printf("%d->", a[j]);
      printf("(%d->(", a[j]);
      for (j = i + 1; j < n - 2; j++) printf("%d->", a[j]);
      printf("%d))", a[n - 2]);
      printf("->%d", a[n - 1]);
    }
    return 0;
  }
  printf("YES\n");
  for (i = 0; i < n - 3; i++) printf("%d->", a[i]);
  printf("(%d->%d)->%d", a[n - 3], a[n - 2], a[n - 1]);
  return 0;
}
