#include <bits/stdc++.h>
using namespace std;
const long long maxn = 2e3 + 10, mod = 1e9 + 7, maxh = 2e5 + 10;
vector<pair<long long, long long>> a;
long long dp[maxn], n, fac[maxh], h, w, cnt;
long long power(long long a, long long b) {
  if (b == 0) return 1;
  return (power(a, b / 2) * power(a, b / 2) % mod * (b % 2 ? a : 1ll)) % mod;
}
long long c(long long r, long long n) {
  if (r > n) return 0;
  return (fac[n] * power(fac[r] * fac[n - r] % mod, mod - 2)) % mod;
}
int main() {
  cin >> h >> w >> n;
  for (int i = 0, x, y; i < n; i++) {
    cin >> x >> y;
    a.push_back({x, y});
  }
  a.push_back({h, w});
  sort(a.begin(), a.end());
  fac[0] = 1;
  for (int i = 1; i < maxh; i++) fac[i] = (fac[i - 1] * i) % mod;
  for (int i = 0; i <= n; i++) {
    auto [xx, yy] = a[i];
    dp[i] = c(xx - 1, xx + yy - 2);
    for (int j = 0; j < i; j++) {
      auto [x, y] = a[j];
      if (y <= yy)
        dp[i] = (dp[i] + mod - dp[j] * c(xx - x, xx + yy - x - y) % mod) % mod;
    }
  }
  cout << dp[n] << endl;
  return 0;
}
