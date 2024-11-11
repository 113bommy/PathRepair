#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5;
const int MOD = 1e9 + 7;
int fact[MAXN + 1] = {1}, inv_fact[MAXN + 1] = {1};
int mypow(int x, int y) {
  int ans = 1;
  while (y > 0) {
    if (y & 1) ans = (1LL * ans * x) % MOD;
    y >>= 1;
    x = (1LL * x * x) % MOD;
  }
  return ans;
}
inline int comb(int n, int k) {
  return (1LL * fact[n] * inv_fact[k]) % MOD * inv_fact[n - k] % MOD;
}
int main() {
  int n;
  for (int i = 1; i <= MAXN; ++i) {
    fact[i] = (1LL * fact[i - 1] * i) % MOD;
    inv_fact[i] = mypow(fact[i], MOD - 2);
  }
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; ++i) cin >> v[i];
  int sgn = 1;
  while ((n & 3) != 1) {
    vector<int> w;
    for (int i = 0; i < n - 1; ++i) {
      w.push_back((1LL * v[i] + sgn * v[i + 1] + MOD) % MOD);
      sgn = -sgn;
    }
    v = w;
    --n;
  }
  int ans = 1;
  for (int i = 0; i < n; i += 2)
    ans = (ans + (1LL * comb(n / 2, i / 2) * v[i]) % MOD) % MOD;
  cout << ans;
  return 0;
}
