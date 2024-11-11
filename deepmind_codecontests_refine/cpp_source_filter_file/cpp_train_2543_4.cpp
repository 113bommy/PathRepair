#include <bits/stdc++.h>
const int mod = 1000000007;
int n, p[1000];
long long d[1001];
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &p[i]);
    p[i]--;
  }
  d[0] = 0;
  d[1] = 2;
  for (int i = 2; i <= n; ++i)
    d[i] = (2 * d[i - 1] % mod - d[p[i - 1]] + 2) % mod;
  printf("%I64d\n", d[n]);
  return 0;
}
