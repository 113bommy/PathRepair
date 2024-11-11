#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e3 + 10;
const int mod = 1e9 + 7;
int ted[MAXN], tedT[MAXN], dp[MAXN], fact[MAXN], rev[MAXN];
int mu(int x, int y) { return 1LL * x * y % mod; }
int ad(int x, int y) { return (x + y) % mod; }
int bpow(int x, int y) {
  int res = 1;
  while (y) {
    if (y & 1) res = mu(res, x);
    x = mu(x, x);
    y >>= 1;
  }
  return res;
}
int c(int n, int r) { return mu(fact[n], mu(rev[r], rev[n - r])); }
int main() {
  int n;
  cin >> n;
  fact[0] = 1;
  for (int i = 1; i <= n; i++) {
    cin >> ted[i];
    tedT[i] = ad(tedT[i - 1], ted[i]);
  }
  for (int i = 1; i < MAXN; i++) {
    fact[i] = mu(fact[i - 1], i);
    rev[n] = bpow(fact[n], mod - 2);
  }
  dp[1] = 1;
  for (int i = 2; i <= n; i++) {
    if (ted[i] == 1)
      dp[i] = dp[i - 1];
    else if (ted[i] == 2)
      dp[i] = mu(dp[i - 1], (tedT[i - 1] + 1));
    else
      dp[i] = mu(dp[i - 1], c(ad((tedT[i - 1] + 1), (ted[i] - 1)) - 1,
                              ad(tedT[i - 1], 1) - 1));
  }
  cout << dp[n] << endl;
}
