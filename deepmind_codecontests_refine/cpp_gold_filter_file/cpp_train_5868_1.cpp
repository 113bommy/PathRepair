#include <bits/stdc++.h>
int m, a, b, deg[1000010];
long long n, tri;
int main() {
  scanf("%I64d%d", &n, &m);
  while (m--) {
    scanf("%d%d", &a, &b);
    deg[a]++, deg[b]++;
  }
  for (int i = 1; i <= n; i++) tri += (long long)deg[i] * (n - deg[i] - 1);
  tri >>= 1;
  printf("%I64d\n", n * (n - 1) * (n - 2) / 6 - tri);
}
