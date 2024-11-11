#include <bits/stdc++.h>
int main() {
  int t;
  scanf("%d ", &t);
  for (int k = 1; k <= t; k++) {
    int n, m;
    scanf("%d %d", &n, &m);
    int a[n];
    int sum = 0;
    for (int i = 0; i < n; i++) {
      scanf("%d", &a[i]);
      sum = sum + a[i];
    }
    if (sum > m)
      printf("%d\n", m);
    else
      printf("%d\n", sum);
  }
  return 0;
}
