#include <bits/stdc++.h>
using namespace std;
long long fact[1000010], digits_sum[1000010], inv_fact[1000010];
long long mod = 1000000000 + 7;
long long power_10[1000010];
long long C(long long n, long long m) {
  long long res = fact[n];
  res = (res * inv_fact[m]) % mod;
  res = (res * inv_fact[n - m]) % mod;
  return res;
}
long long get_mod(long long a, long long b, long long modd) {
  long long res = 1;
  while (b > 0) {
    if (b % 2 == 1) res = (res * a) % modd;
    b = b / 2;
    a = (a * a) % modd;
  }
  return res;
}
int main() {
  int n, k;
  string s;
  cin >> n >> k >> s;
  fact[0] = fact[1] = inv_fact[0] = inv_fact[1] = 1;
  power_10[0] = 1;
  power_10[1] = 10;
  for (int i = 2; i <= 100000; i++) {
    fact[i] = (fact[i - 1] * i) % mod;
    inv_fact[i] = get_mod(fact[i], mod - 2, mod);
    power_10[i] = (power_10[i - 1] * 10) % mod;
  }
  digits_sum[0] = s[0] - 48;
  for (int i = 1; i < n; i++)
    digits_sum[i] = (digits_sum[i - 1] + (s[i] - 48)) % mod;
  long long res = 0;
  for (int l = 0; l <= n - 2; l++) {
    long long r = (power_10[l] * C(n - l - 2, k - 1)) % mod;
    r = (r * digits_sum[n - l - 2]) % mod;
    res = (res + r) % mod;
  }
  for (int i = 0; i <= n - 1; i++) {
    long long r = ((s[i] - 48) * power_10[n - 1 - i]) % mod;
    r = (r * C(i, k)) % mod;
    res = (res + r) % mod;
  }
  cout << res << endl;
  return 0;
}
