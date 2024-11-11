#include <bits/stdc++.h>
int main() {
  int i, n1, n2, k, m;
  scanf("%d%d%d%d", &n1, &n2, &k, &m);
  int a[n1], b[n2];
  for (i = 0; i < n1; i++) scanf("%d", &a[i]);
  for (i = 0; i < n2; i++) scanf("%d", &b[i]);
  if (a[k - 1] < b[n2 - m - 1])
    printf("YES\n");
  else
    printf("NO\n");
  return 0;
}
