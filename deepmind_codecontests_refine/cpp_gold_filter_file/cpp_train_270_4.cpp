#include <bits/stdc++.h>
int main() {
  int n, i, W[100], sp[100];
  int k;
  scanf("%d", &n);
  while (n < 1 && n > 100) scanf("%d", &n);
  sp[0] = 3;
  k = 1;
  for (i = 0; i < n; i++) {
    scanf("%d", &W[i]);
    sp[i + 1] = 6 - (W[i] + sp[i]);
    if (W[i] == sp[i]) k = 0;
  }
  if (k == 1)
    printf("YES\n");
  else
    printf("NO\n");
}
