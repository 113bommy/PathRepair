#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
vector<long long> fat, inv, inv_fat;
long long P(int n, int k) { return fat[n] * inv_fat[n - k] % mod; }
signed main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  fat.resize(n + 1);
  inv.resize(n + 1);
  inv_fat.resize(n + 1);
  for (int k = 0; k < 2; ++k) fat[k] = inv[k] = inv_fat[k] = 1;
  for (int k = 2; k <= n; ++k) {
    fat[k] = k * fat[k - 1] % mod;
    inv[k] = -(mod / k) * inv[mod % k] % mod;
    inv_fat[k] = inv[k] * inv_fat[k - 1] % mod;
  }
  long long ans = fat[n];
  for (int k = 2; k <= n; ++k)
    ans = (ans + P(n, k - 1) * (fat[n - k + 1] - 1)) % mod;
  if (ans < 0) ans += mod;
  cout << ans << '\n';
  return 0;
}
