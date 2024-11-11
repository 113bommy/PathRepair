#include <bits/stdc++.h>
int main() {
  int n;
  scanf("%d", &n);
  int* a = new int[2 * n];
  memset(a, 0, sizeof(int) * 2 * n);
  for (int i = 1; i <= n; i++) {
    a[i] = i;
  }
  for (int k = 2; k <= n; k++) {
    int cnt = n / k;
    int last = n % k;
    int prev = a[k - 1];
    int delta = k - 2;
    for (int i = 0; i <= cnt; i++) {
      int tmp = a[i * k + 1 + delta];
      a[i * k + 1 + delta] = prev;
      prev = tmp;
    }
    if (last != 0) {
      a[n + k - 1] = prev;
    }
  }
  for (int i = n; i < 2 * n; i++) {
    printf("%d ", a[i]);
  }
  return 0;
}
