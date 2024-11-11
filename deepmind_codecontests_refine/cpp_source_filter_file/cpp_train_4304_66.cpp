#include <bits/stdc++.h>
int main() {
  int F[18258];
  F[1] = 1;
  int n;
  scanf("%d", &n);
  for (int i = 2; i <= n; i++) F[i] = F[i - 1] + (n - 1) * 12;
  printf("%d", F[n]);
  return 0;
}
