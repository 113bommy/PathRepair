#include <bits/stdc++.h>
using namespace std;
const int max_n = 2001;
const long long mod = 1000000007;
long long a[max_n];
long long comb[max_n];
long long inv[max_n];
long long ext_gcd(long long a, long long b, long long &x, long long &y) {
  long long t, ret;
  if (!b) {
    x = 1, y = 0;
    return a;
  }
  ret = ext_gcd(b, a % b, x, y);
  t = x, x = y, y = t - a / b * y;
  return ret;
}
void cal_inv() {
  for (long long i = 1; i < max_n; i++) {
    long long x, y;
    ext_gcd(i, mod, x, y);
    inv[i] = (x % mod + mod) % mod;
  }
}
void cal(long long k, long long n) {
  comb[0] = 1;
  for (long long i = 1; i <= n - 1; i++) {
    comb[i] = 1;
    for (long long j = i + k - 1; j >= k; j--) {
      comb[i] *= j;
      comb[i] %= mod;
    }
    for (long long j = 2; j <= i; j++) {
      comb[i] *= inv[j];
      comb[i] %= mod;
    }
  }
}
int main() {
  cal_inv();
  long long n, k;
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  if (k == 0) {
    for (int i = 0; i < n; i++) {
      cout << (a[i] % mod + mod) % mod << " ";
    }
    cout << endl;
    return 0;
  }
  cal(k, n);
  for (int i = 0; i < n; i++) {
    long long ret = 0;
    for (int j = 0; j <= i; j++) {
      ret += comb[i - j] * a[j];
      ret %= mod;
    }
    ret += mod;
    ret %= mod;
    printf("%d ", ret);
  }
  cout << endl;
  return 0;
}
