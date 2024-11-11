#include <bits/stdc++.h>
void err() { std::cout << std::endl; }
template <typename T, typename... Args>
void err(T a, Args... args) {
  std::cout << a << ' ';
  err(args...);
}
using namespace std;
const int mod = 1e9 + 7;
const int maxn = 100000 + 5;
long long qpow(long long x, long long n) {
  long long r = 1;
  while (n) {
    if (n & 1) r = 1ll * r * x % mod;
    n >>= 1;
    x = 1ll * x * x % mod;
  }
  return r % mod;
}
long long inv(long long x) { return qpow(x, mod - 2); }
long long n, k;
long long f[100][50000];
long long dp(long long p, int a, int k) {
  if (f[a][k] > -1) return f[a][k];
  if (k == 0) return qpow(p, a);
  long long ans = 0;
  for (int i = 0; i <= a; i++) ans = (ans + dp(p, i, k - 1)) % mod;
  return f[a][k] = ans * inv(a + 1) % mod;
}
long long cal(long long p, int a) {
  for (int i = 0; i <= a; i++)
    for (int j = 0; j <= k; j++) f[i][j] = -1;
  return dp(p, a, k);
}
int main() {
  cin >> n >> k;
  long long ans = 1;
  for (long long i = 2; 1ll * i * i <= n; i++) {
    if (n % i) continue;
    int cnt = 0;
    while (n % i == 0) cnt++, n /= i;
    long long x = cal(i, cnt);
    ans = ans * x % mod;
  }
  if (n > 1) ans = ans * cal(n, 1) % mod;
  cout << ans;
  return 0;
}
