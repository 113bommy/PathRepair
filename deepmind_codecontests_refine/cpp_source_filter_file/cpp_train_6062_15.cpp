#include <bits/stdc++.h>
int main() {
  int t, n, m;
  scanf("%d", &t);
  while (t--) {
    scanf("%d%d", &n, &m);
    int a[n + 1];
    int sum = 0;
    for (int i = 0; i < n; i++) {
      scanf("%d", &a[i]);
      sum += a[i];
    }
    if (sum > m)
      printf("%d", m);
    else
      printf("%d\n", sum);
  }
  return 0;
}
