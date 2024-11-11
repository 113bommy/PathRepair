#include <bits/stdc++.h>
using namespace std;
constexpr int MAX = 200010;
constexpr int MOD = 1000000009;
long long n, a, b, k;
string s;
long long modpow(long long a, long long b) {
  long long res = 1, p = a;
  while (b > 0) {
    if (b & 1) {
      res = (res * p) % MOD;
    }
    b >>= 1;
    p = (p * p) % MOD;
  }
  return res;
}
int main() {
  cin >> n >> a >> b >> k;
  cin >> s;
  long long a_inv = modpow(a, MOD - 2);
  long long z = 0;
  long long t1 = modpow(a, n), t2 = 1;
  for (int i = 0; i < k; ++i) {
    if (s[i] == '+') {
      z = (z + t1 * t2) % MOD;
    } else {
      z = (z - (long long)(t1 * t2) % MOD) % MOD;
    }
    t1 = (t1 * a_inv) % MOD;
    t2 = (t2 * b) % MOD;
  }
  long long q = modpow((a_inv * b) % MOD, k);
  long long res = 0;
  if (q != 1) {
    res = (modpow(q, (n + 1) / k) - 1 + MOD) % MOD;
    res = (res * modpow(q - 1, MOD - 2)) % MOD;
  } else {
    res = (n + 1) / k;
  }
  res = (res * z) % MOD;
  cout << res << endl;
  return 0;
}
