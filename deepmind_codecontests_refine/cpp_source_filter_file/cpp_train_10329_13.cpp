#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
long long powmod(long long a, long long b) {
  long long res = 1;
  a %= mod;
  assert(b >= 0);
  for (; b; b >>= 1) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
  }
  return res;
}
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
const int N = 3e5 + 10;
long long f[N];
int main() {
  long long n, m;
  cin >> n >> m;
  f[1] = 1;
  for (int i = 2; i <= n; i++) {
    f[i] = f[i - 1] * i % m;
  }
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    long long res = f[n] * (n - i + 1) % m * f[i] % m;
    ans = (ans + res) % m;
  }
  cout << ans << endl;
  return 0;
}
