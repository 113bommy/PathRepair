#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
const int mod = 1e9 + 7;
int n, k;
map<int, int> mii;
long long fc[N];
long long pow(long long x, int y, int MOD) {
  if (y == 0) return 1;
  long long res = pow(x, y / 2, MOD);
  res = res * res % MOD;
  if (y & 1) res = res * x % MOD;
  return res;
}
long long c(int n, int k) {
  long long res = pow(fc[n], 1, mod) * pow(fc[n - k], mod - 2, mod) % mod;
  res = res * pow(fc[k], mod - 2, mod) % mod;
  return res;
}
int main() {
  fc[0] = 1;
  for (int i = 1; i < N; ++i) fc[i] = fc[i - 1] * i % mod;
  cin >> n >> k;
  for (int i = 0; i < n; ++i) {
    int l, r;
    cin >> l >> r;
    mii[l]++;
    mii[r + 1]--;
  }
  long long ans = 0;
  int l = mii.begin()->first;
  int sum = 0;
  for (map<int, int>::iterator it = mii.begin(); it != mii.end(); ++it) {
    int dist = it->first - l;
    if (sum >= k) {
      ans += 1ll * dist * c(sum, k);
      ans %= mod;
    }
    sum += it->second;
    l = it->first;
  }
  cout << ans;
}
