#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10, mod = 998244353;
int n;
int x[N], y[N], s[N];
int add[N];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d%d%d", &x[i], &y[i], &s[i]);
  for (int i = 1; i <= n; i++) {
    int l = upper_bound(x + 1, x + 1 + n, y[i]) - x;
    add[i] = (1ll * x[i] - y[i] + add[i - 1] - add[l - 1]) % mod;
    add[i] = (add[i] + add[i - 1]) % mod;
  }
  int res = x[n] + 1;
  for (int i = 1; i <= n; i++)
    if (s[i]) res = (1ll * res + add[i] - add[i - 1] + mod) % mod;
  printf("%d\n", res);
  return 0;
}
