#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
long long st[5010][5010], n, k, ans;
long long ksm(long long aa, long long bb) {
  long long res = 1;
  while (bb > 0) {
    if (bb & 1) res = res * aa % mod;
    bb >>= 1, aa = aa * aa % mod;
  }
  return res;
}
int main() {
  scanf("%lld%lld", &n, &k);
  st[1][1] = 1;
  for (int i = 2; i <= k; i++)
    for (int j = 1; j <= i; j++)
      st[i][j] = (st[i - 1][j] * j + st[i - 1][j - 1]) % mod;
  for (int i = 0; i <= k; i++) {
    long long res = 1;
    for (int j = 1; j <= i; j++) res = res * (n - j + 1) % mod;
    res = res * ksm(2, n - i) % mod;
    res = res * st[k][i];
    ans = (ans + res) % mod;
  }
  printf("%lld\n", ans);
  return 0;
}
