#include <bits/stdc++.h>
int main() {
  int n, a[1000];
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }
  std::sort(a, a + n);
  for (int i = 0; i < n; ++i) {
    if (i & 1) {
      printf("%d ", a[n - 1 - i / 2]);
    } else {
      printf("%d ", a[i / 2]);
    }
  }
  return 0;
}
