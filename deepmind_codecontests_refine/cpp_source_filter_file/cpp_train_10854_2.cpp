#include <bits/stdc++.h>
using namespace std;
const int DBG = true;
const int SI = 2e6 + 100;
const long long mod = 998244353;
inline long long pow_mod(long long X, long long N, long long mod) {
  long long res = 1;
  while (N > 0) {
    if (N & 1) res = res * X % mod;
    X = X * X % mod;
    N >>= 1;
  }
  return res;
}
long long n, m;
long long W[SI];
long long inv[SI];
int main() {
  inv[1] = 1;
  for (int i = 2; i < SI; i++) inv[i] = (mod - (mod / i) * inv[mod % i] % mod);
  cin >> n >> m;
  W[1] = 1;
  for (int i = 2; i <= n + 1; i++)
    W[i] = W[i - 1] * (n - (i - 1) + 1) % mod * inv[n + m - (i - 1) + 1] % mod;
  long long E = 0;
  for (int i = 1; i <= n + 1; i++) {
    E = (E + i * m % mod * W[i] % mod * inv[n + m + 1 - i]) % mod;
  }
  long long sum = 1;
  for (int i = 1; i <= n; i++) sum = (sum + m * inv[i] % mod) % mod;
  cout << sum * E % mod;
  return 0;
}
