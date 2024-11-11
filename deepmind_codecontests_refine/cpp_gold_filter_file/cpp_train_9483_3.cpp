#include <bits/stdc++.h>
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  int c[n], a[m];
  for (int i = 0; i < n; i++) {
    scanf("%d", &c[i]);
  }
  for (int i = 0; i < m; i++) {
    scanf("%d", &a[i]);
  }
  int j = 0, g = 0;
  for (int i = 0; i < n; i++) {
    if (c[i] <= a[j] && j < m) {
      g++;
      j++;
    }
  }
  printf("%d", g);
  return 0;
}
