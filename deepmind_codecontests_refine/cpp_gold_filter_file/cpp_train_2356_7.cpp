#include <bits/stdc++.h>
int main() {
  int n, a[1000], i, ne = 0;
  scanf("%d", &n);
  for (i = 0; i < n; ++i) {
    scanf("%d", a + i);
  }
  for (i = 1; i < n - 1; ++i) {
    if (a[i] > a[i - 1] && a[i] > a[i + 1] ||
        a[i] < a[i - 1] && a[i] < a[i + 1]) {
      ++ne;
    }
  }
  printf("%d", ne);
  return 0;
}
