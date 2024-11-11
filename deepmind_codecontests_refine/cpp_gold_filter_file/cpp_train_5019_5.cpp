#include <bits/stdc++.h>
using namespace std;
const int _ = 5e3 + 7;
const int mod = 998244353;
int n, m, K, P, ans, S[_][_];
int Pw(int a, int p) {
  int res = 1;
  while (p) {
    if (p & 1) res = 1ll * res * a % mod;
    a = 1ll * a * a % mod;
    p >>= 1;
  }
  return res;
}
int main() {
  cin >> n >> m >> K;
  P = Pw(m, mod - 2);
  for (int i = 0; i <= K; ++i) {
    S[i][0] = i == 0;
    for (int j = 1; j <= i; ++j)
      S[i][j] = (1ll * j * S[i - 1][j] + S[i - 1][j - 1]) % mod;
  }
  for (int i = 0, nd = 1, pj = 1; i <= K;
       ++i, nd = 1ll * nd * (n - i + 1) % mod, pj = 1ll * pj * P % mod)
    ans = (ans + 1ll * S[K][i] * nd % mod * pj % mod) % mod;
  cout << ans << endl;
  return 0;
}
