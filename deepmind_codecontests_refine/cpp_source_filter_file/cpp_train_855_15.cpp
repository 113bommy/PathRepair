#include <bits/stdc++.h>
using namespace std;
long long mod = 998244353;
vector<long long> inv(200001);
vector<long long> nck(200001);
long long exp(long long x, long long p) {
  if (p == 0) return 1;
  if (p == 1) return x % mod;
  long long temp = exp(x, p / 2);
  temp = (temp * temp) % mod;
  if (p % 2 == 0) return temp;
  temp = (x * temp) % mod;
  return temp;
}
int main() {
  for (int i = 1; i <= 200000; i++) {
    inv[i] = exp(i, mod - 2);
  }
  long long n, k;
  cin >> n >> k;
  if (k > n - 1) {
    cout << 0 << endl;
    return 0;
  }
  long long ans = 1;
  if (k == 0) {
    for (int i = 1; i <= n; i++) ans = (ans * i) % mod;
    cout << ans << endl;
    return 0;
  }
  long long c = n - k;
  ans = 0;
  long long fc = 1;
  for (int i = 1; i <= c; i++) {
    fc = (fc * inv[i]) % mod;
    fc = (fc * (n - i + 1)) % mod;
  }
  nck[0] = 1;
  nck[1] = c;
  for (int i = 2; i <= c; i++) {
    nck[i] = (nck[i - 1] * inv[i]) % mod;
    nck[i] = (nck[i] * (c - i + 1)) % mod;
  }
  for (int i = c; i >= 1; i--) {
    long long temp = exp(i, n);
    long long fac = nck[i];
    temp = (temp * fac) % mod;
    if ((n - i) % 2 == 1) {
      ans = (ans + mod - temp) % mod;
    } else {
      ans = (ans + temp) % mod;
    }
  }
  ans = (ans * fc) % mod;
  ans = (2 * ans) % mod;
  cout << ans << endl;
}
