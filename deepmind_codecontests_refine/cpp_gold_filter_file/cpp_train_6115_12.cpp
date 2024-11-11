#include <bits/stdc++.h>
int main() {
  int n, m, i, a[100], b[100];
  scanf("%d%d", &n, &m);
  for (i = 0; i < n; i++) scanf("%d", &a[i]);
  for (i = 0; i < m; i++) scanf("%d", &b[i]);
  for (i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (a[i] == b[j]) printf("%d ", a[i]);
    }
  }
  return 0;
}
