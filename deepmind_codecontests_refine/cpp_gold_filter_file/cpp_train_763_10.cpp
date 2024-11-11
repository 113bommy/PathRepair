#include <bits/stdc++.h>
int n;
int deg[1000010];
long long int res;
int main() {
  int m, x, y;
  for (scanf("%d%d", &n, &m); m--;) {
    scanf("%d%d", &x, &y);
    deg[x]++;
    deg[y]++;
  }
  res = 0;
  for (int i = 1; i <= n; i++) res += deg[i] * (n - 1LL - deg[i]);
  printf("%I64d\n", n * (n - 1LL) * (n - 2LL) / 6 - res / 2);
  return 0;
}
