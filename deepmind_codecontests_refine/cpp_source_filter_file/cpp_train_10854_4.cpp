#include <bits/stdc++.h>
const long long N = 4e6 + 6, mod = 998244353;
using namespace std;
long long v[N];
long long ans, sum;
int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  v[1] = 1;
  for (int i = 2; i <= n; ++i) v[i] = (mod - mod / i) * v[mod % i] % mod;
  ans = (1ll * n * v[m + 1] + 1) % mod;
  for (int i = 1; i <= n; ++i) sum = (sum + v[i]) % mod;
  sum = sum * m + 1, sum %= mod;
  printf("%lld\n", sum * ans % mod);
  return 0;
}
