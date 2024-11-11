#include <bits/stdc++.h>
int main() {
  int n, i, s[200000], t[200000], j, x = 1, y, max = 0;
  scanf("%d", &n);
  for (i = 1; i <= n; i++) {
    scanf("%d", &s[i]);
  }
  max = s[n];
  t[n] = 0;
  for (i = n - 1; i >= 1; i--) {
    if (s[i] >= max) {
      t[i] = 0;
      max = s[i];
    } else {
      t[i] = max + 1 - s[i];
    }
  }
  for (i = 1; i <= n; i++) {
    printf("%d ", t[i]);
  }
  return 0;
}
