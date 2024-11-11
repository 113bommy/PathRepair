#include <bits/stdc++.h>
using namespace std;
const int MXN = (int)3e5 + 7;
const int MOD = (int)1e9 + 7;
long long w, h, fact[MXN], val[MXN];
int n;
pair<int, int> a[MXN];
long long binpow(long long a, int n) {
  if (!n) return 1;
  if (n & 1) return binpow(a, n - 1) * a % MOD;
  long long b = binpow(a, n / 2) % MOD;
  return b * b % MOD;
}
long long inv(long long a) { return binpow(a, MOD - 2) % MOD; }
long long cnk(long long n, long long k) {
  return fact[n] * inv(fact[k] * fact[n - k] % MOD) % MOD;
}
int main() {
  fact[0] = 1;
  for (int i = 1; i <= 1e5; i++) {
    fact[i] = fact[i - 1] * i % MOD;
  }
  cin >> h >> w >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i].first >> a[i].second;
  }
  n++;
  a[n] = {h, w};
  sort(a + 1, a + n + 1);
  for (int i = 1; i <= n; i++) {
    val[i] = cnk(a[i].first + a[i].second - 2, a[i].second - 1) % MOD;
    for (int j = 1; j < i; j++) {
      if (a[j].first <= a[i].first && a[j].second <= a[i].second) {
        int nx = a[i].first - a[j].first, ny = a[i].second - a[j].second;
        val[i] -= (val[j] * cnk(nx + ny, ny) % MOD);
        val[i] = (val[i] % MOD + MOD) % MOD;
      }
    }
  }
  cout << val[n];
  return 0;
}
