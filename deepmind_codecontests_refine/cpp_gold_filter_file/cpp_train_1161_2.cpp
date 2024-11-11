#include <bits/stdc++.h>
using namespace std;
const long long inf = 0x3f3f3f3f;
const int mod = 998244353;
const int N = 2e5 + 5;
int n, m;
int f[N], in[N], ans;
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n - 1; ++i) {
    int x, y;
    scanf("%d%d", &x, &y);
    in[x]++;
    in[y]++;
  }
  f[0] = ans = 1;
  for (int i = 1; i <= n; ++i) f[i] = 1ll * i * f[i - 1] % mod;
  for (int i = 1; i <= n; ++i) ans = 1ll * ans * f[in[i]] % mod;
  printf("%d\n", 1ll * ans * n % mod);
  return 0;
}
