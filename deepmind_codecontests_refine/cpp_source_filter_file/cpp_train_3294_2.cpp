#include <bits/stdc++.h>
using namespace std;
const long long int mod = 1e9 + 7;
const long long int MOD = 1e18 + 7;
long long int modPow(long long int a, long long int b) {
  long long int res = 1;
  a %= mod;
  for (; b; b >>= 1) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
  }
  return res;
}
long long int MODPow(long long int a, long long int b) {
  long long int res = 1;
  a %= MOD;
  for (; b; b >>= 1) {
    if (b & 1) res = res * a % MOD;
    a = a * a % MOD;
  }
  return res;
}
long long int nCr(long long int n, long long int k) {
  long long int res = 1;
  if (k > n - k) k = n - k;
  for (long long int i = 0; i < k; ++i) {
    res = (res * (n - i)) % mod;
    res = (res * modPow(i + 1, mod - 2)) % mod;
  }
  return res;
}
int main() {
  long long int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    int x[k];
    int d[k + 1];
    cin >> x[0];
    d[0] = x[0];
    for (int i = 1; i < k; i++)
      cin >> x[i], d[i] = ceil((x[i] - x[i - 1] - 1) / 2);
    d[k] = n - x[k - 1] + 1;
    int m = -1;
    for (int i = 0; i < k + 1; i++) m = max(m, d[i]);
    cout << m << "\n";
  }
}
