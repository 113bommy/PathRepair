#include <bits/stdc++.h>
int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  int a[n];
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  std::sort(a, a + n);
  for (int i = n - 1; i >= 0; i--)
    if (k % a[i] == 0) {
      printf("%d", a[i]);
      return 0;
    }
}
