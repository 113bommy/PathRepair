#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 10;
const int maxn5 = 5e5 + 10;
const int maxnt = 1.2e6 + 10;
const int maxn3 = 1e3 + 10;
const long long mod = 1e9 + 7;
const long long inf = 2e18;
long long f[maxn5];
long long pw(long long a, long long b) {
  return (b == 0 ? 1 : (pw(a * a % mod, b / 2) * (b % 2 == 1 ? a : 1)) % mod);
}
long long ent(long long n, long long k) {
  long long a = 1, b = 1;
  for (long long i = 1; i <= k; i++) {
    b *= i, b %= mod;
    a *= (n - i + 1), a %= mod;
  }
  return (a * pw(b, mod - 2)) % mod;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  long long s, ans = 0;
  cin >> n >> s;
  for (int i = 0; i < n; i++) cin >> f[i];
  for (int mask = 1; mask < (1 << n); mask++) {
    long long need = s;
    for (int j = 0; j < n; j++)
      if ((mask >> j) & 1) need -= f[j] + 1;
    if (need < 0) continue;
    long long val = ent(need + n - 1, n - 1);
    ans += val * (__builtin_popcount(mask) % 2 == 1 ? 1 : -1);
    ans = (ans + mod) % mod;
  }
  long long all = ent(s + n - 1, n - 1);
  cout << (all - ans + mod) % mod << endl;
  return 0;
}
