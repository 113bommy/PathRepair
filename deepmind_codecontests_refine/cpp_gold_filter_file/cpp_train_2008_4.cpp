#include <bits/stdc++.h>
using namespace std;
long long poww(long long x, long long y, long long m) {
  x = x % m;
  if (y == 0) {
    return 1;
  }
  if (y % 2 == 0) {
    return poww(x * x, y / 2, m);
  } else {
    return (x * poww(x * x, y / 2, m)) % m;
  }
}
void io();
const int mod = 998244353;
const int maxn = 300000 + 10;
int n;
long long a[maxn];
long long fact[maxn];
int main() {
  io();
  int i, j;
  fact[0] = 1;
  cin >> n;
  for (long long i = 1; i <= 2 * n; i++) {
    fact[i] = fact[i - 1] * i;
    fact[i] %= mod;
  }
  for ((i) = 0; (i) < (2 * n); i = i + 1) cin >> a[i];
  sort(a, a + 2 * n);
  long long second = 0;
  for ((i) = n; (i) < (2 * n); i = i + 1) second += a[i];
  for ((i) = 0; (i) < (n); i = i + 1) second -= a[i];
  second %= mod;
  long long c1 = fact[2 * n];
  long long c2 = (fact[n] * fact[n]) % mod;
  c2 = poww(c2, mod - 2, mod) % mod;
  long long c3 = (c1 * c2) % mod;
  long long ans = (c3 * second) % mod;
  cout << ans;
  return 0;
}
void io() {}
