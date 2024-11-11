#include <bits/stdc++.h>
using namespace std;
const int maxn = 505, maxm = 1e6 + 5;
const long long MOD = 998244353;
int n, m, ls[maxn], ls_sz;
long long f[maxn][maxn], lto[maxn], rto[maxn];
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; i++) {
    int x;
    scanf("%d", &x);
    if (!ls_sz || ls[ls_sz] != x) ls[++ls_sz] = x;
  }
  if (ls_sz > 2 * n) {
    printf("0\n");
    return 0;
  }
  for (int i = 1; i <= ls_sz; i++) {
    if (!lto[ls[i]]) lto[ls[i]] = i;
    rto[ls[i]] = i;
  }
  for (int i = 1; i <= n; i++)
    if (lto[i] == rto[i]) f[lto[i]][rto[i]] = 1;
  for (int i = 0; i <= ls_sz; i++) f[i + 1][i] = 1;
  for (int len = 2; len <= ls_sz; len++) {
    for (int l = 1; l <= ls_sz - len + 1; l++) {
      int r = l + len - 1, mncol = ls[l];
      for (int i = l + 1; i <= r; i++) mncol = min(mncol, ls[i]);
      if (lto[mncol] < l || rto[mncol] > r) continue;
      long long s1 = 0, s2 = 0;
      for (int i = l; i <= lto[mncol]; i++)
        s1 = (s1 + f[l][i - 1] * f[i][lto[mncol] - 1] % MOD) % MOD;
      for (int i = rto[mncol]; i <= r; i++)
        s2 = (s2 + f[rto[mncol] + 1][i] * f[i + 1][r] % MOD) % MOD;
      f[l][r] = s1 * s2 % MOD;
      int pre = 0;
      for (int i = lto[mncol]; i <= rto[mncol]; i++) {
        if (ls[i] != mncol) continue;
        if (pre) f[l][r] = f[l][r] * f[pre + 1][i - 1] % MOD;
        pre = i;
      }
    }
  }
  printf("%lld\n", f[1][ls_sz]);
  return 0;
}
