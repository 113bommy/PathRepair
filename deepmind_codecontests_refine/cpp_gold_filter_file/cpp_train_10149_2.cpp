#include <bits/stdc++.h>
using namespace std;
int n, m, b, MOD;
long long ans;
int a[550], s[550], f[550][550];
int main() {
  scanf("%d%d%d%d", &n, &m, &b, &MOD);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  f[0][0] = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      for (int k = a[i]; k <= b; k++) {
        f[j][k] = (f[j - 1][k - a[i]] + f[j][k]) % MOD;
      }
    }
  }
  for (int i = 0; i <= b; i++) ans = (ans + f[m][i]) % MOD;
  printf("%lld", ans);
  return 0;
}
