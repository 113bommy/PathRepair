#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
long long n, m, k;
long long fn(long long x, long long p) {
  if (p < 2) return (p ? x : 1);
  long long ans = 1;
  if (p % 2) ans = (ans * x) % mod;
  long long s = fn(x, p / 2);
  return ((ans * s) % mod * s) % mod;
}
int main() {
  cin >> n >> m >> k;
  if (n > m) swap(n, m);
  cout << (n % 2 != m % 2 && k == -1 ? 0 : fn(2, (n - 1) * (m - 1)));
  return 0;
}
