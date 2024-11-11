#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
const int N = 100005;
const double PI = 4 * atan(1);
const long long MAX = 9223372036854775807;
set<char> vowel = {'A', 'O', 'Y', 'E', 'U', 'I', 'a', 'o', 'e', 'u', 'i'};
int dx[] = {1, -1, 0, 0, 1, -1, 1, -1};
int dy[] = {0, 0, 1, -1, 1, 1, -1, -1};
long long gcd(long long a, long long b) { return (b == 0 ? a : gcd(b, a % b)); }
long long lcm(long long a, long long b) { return a * (b / gcd(a, b)); }
bool issquare(long long w) { return trunc(sqrt(w)) * trunc(sqrt(w)) == w; }
bool isprime(long long u) {
  for (long long i = 2; i <= (int)sqrt(u); i++) {
    if (u % i == 0) return 0;
  }
  return 1;
}
long long mod(long long to_mod) {
  to_mod %= MOD;
  while (to_mod < 0) to_mod += MOD;
  return to_mod % MOD;
}
long long moduloMultiplication(long long a, long long b, long long mod) {
  long long res = 0;
  a %= mod;
  while (b) {
    if (b & 1) res = (res + a) % mod;
    a = (2 * a) % mod;
    b >>= 1;
  }
  return res;
}
long long power(long long x, long long y) {
  long long res = 1;
  x = x;
  while (y > 0) {
    if (y & 1) res = (res * x);
    y = y >> 1;
    x = (x * x);
  }
  return res;
}
long long n, m, x, y, ans, z, res;
int main() {
  ios_base::sync_with_stdio(false);
  cin >> n >> m;
  y = m;
  z = 0;
  for (int i = 0; i < n; i++) {
    cin >> x;
    res = x;
    z = 0;
    x -= min(x, y);
    y -= min(y, res);
    if (y == 0) {
      z++;
    }
    if (x > 0) {
      z += (x / m);
      y = m - x % m;
    }
    cout << z << " ";
  }
  return 0;
}
