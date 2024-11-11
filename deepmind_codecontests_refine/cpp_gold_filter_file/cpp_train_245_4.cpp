#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 9;
const int mxn = 4005;
int n, w, b;
long long ans, res;
long long c[mxn][mxn], fac[mxn];
inline void init() {
  int tmp = max(n, max(w, b));
  for (int i = 0; i <= tmp; i++) c[i][0] = 1;
  for (int i = 1; i <= tmp; i++)
    for (int j = 1; j <= i; j++)
      c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % mod;
  fac[0] = 1;
  for (int i = 1; i <= max(w, b); i++) fac[i] = (i * fac[i - 1]) % mod;
}
int main() {
  scanf("%d%d%d", &n, &w, &b);
  init();
  for (int i = 1; i <= b; i++) {
    long long res = n - i - 1;
    if (!res) break;
    res = res * c[b - 1][i - 1] % mod;
    res = res * fac[b] % mod;
    res = res * c[w - 1][n - i - 1] % mod;
    res = res * fac[w] % mod;
    ans = (ans + res) % mod;
  }
  printf("%I64d\n", ans);
  return 0;
}
