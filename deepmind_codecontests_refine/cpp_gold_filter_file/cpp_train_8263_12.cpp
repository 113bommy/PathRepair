#include <bits/stdc++.h>
long long i, a, b, c, n, x, C, M = 1e9 + 7;
int main() {
  scanf("%d", &n);
  for (i = 1; i <= n; i++) scanf("%d", &x), C += x == 1;
  a = b = c = 1;
  for (i = 2; i <= C; i++) c = (b + a * (i - 1) % M) % M, a = b, b = c;
  for (i = C + 1; i <= n; i++) c = c * i % M;
  printf("%d\n", c);
}
