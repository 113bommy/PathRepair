#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
long long c[1000001] = {0};
long long d[1000001] = {0};
long long f[1000001] = {0};
long long p;
int binpow(long long b, int n) {
  long long ans = 1;
  while (n) {
    if (n & 1) ans = ans * 1ll * b % mod;
    b = b * 1ll * b % mod;
    n /= 2;
  }
  return int(ans);
}
int main() {
  int n;
  cin >> n;
  n++;
  long long a = 1;
  for (int i = 1; i <= 2 * n - 1; i++) a = a * i % mod;
  long long b = 1;
  for (int i = 1; i <= n; i++) b = b * i % mod;
  long long c = 1;
  for (int i = 1; i <= n - 1; i++) c = c * i % mod;
  long long d = binpow(b, mod - 2);
  long long e = binpow(c, mod - 2);
  cout << (2ll * a % mod * d % mod * e % mod - 1 + mod) % mod << endl;
}
