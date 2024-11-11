#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5, MOD = 1000000007;
int T, n, a[N], f[N];
int main() {
  f[0] = 1;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", a + i);
  sort(a + 1, a + 1 + n);
  for (int i = 1; i <= n; i++) {
    if (a[i] == 1)
      f[i] = (f[i - 1] + 1LL * (i - 1) * f[i - 2] % MOD) % MOD;
    else
      f[i] = (f[i - 1] + 1LL * (i - 1) * f[i - 1] % MOD) % MOD;
  }
  printf("%d\n", f[n]);
  return 0;
}
