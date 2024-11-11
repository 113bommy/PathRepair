#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e6 + 10, mod = 998244353;
int n, m, inv[maxn], ans;
int main() {
  cin >> n >> m;
  inv[1] = 1;
  for (register int i = (2), ed = (max(n, m + 1)); i <= ed; ++i)
    inv[i] = 1ll * (mod - mod / i) * inv[mod % i] % mod;
  for (register int i = (1), ed = (n); i <= ed; ++i) ans = (ans + inv[i]) % mod;
  ans = (1ll * ans * m + 1) % mod * (1ll * n * inv[m + 1] + 1) % mod;
  printf("%d\n", ans);
  return 0;
}
