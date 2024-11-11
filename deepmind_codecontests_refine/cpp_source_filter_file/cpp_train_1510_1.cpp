#include <bits/stdc++.h>
using namespace std;
const int maxm = 2000 + 10;
const int maxn = 100000 + 10;
const int mod = 1000000000 + 7;
int h, w, n;
long long fac[2 * maxn];
long long dp[maxm];
pair<int, int> p[maxm];
long long pow_mul(long long a, long long b) {
  long long res = 1;
  while (b) {
    if (b & 1) res = res * a % mod;
    a = (a * a) % mod;
    b >>= 1;
  }
  return res;
}
long long C(long long a, long long b) {
  if (b > a) return 0;
  return fac[a] * pow_mul(fac[b] * fac[a - b] % mod, mod - 2) % mod;
}
long long lucas(long long a, long long b) {
  if (b == 0) return 1;
  return (C(a % mod, b % mod) * lucas(a / mod, b / mod)) % mod;
}
void init() {
  fac[0] = 1, fac[1] = 1;
  for (int i = 1; i < 2 * maxn; i++) {
    fac[i] = fac[i - 1] * i % mod;
  }
}
int main() {
  init();
  cin >> h >> w >> n;
  for (int i = 1; i <= n; i++) {
    int x, y;
    cin >> x >> y;
    p[i].first = x;
    p[i].second = y;
  }
  p[n + 1].first = h, p[n + 1].second = w;
  sort(p + 1, p + 1 + n + 1);
  for (int i = 1; i <= n + 1; i++) {
    dp[i] = lucas(p[i].first + p[i].second - 2, p[i].first - 1);
    for (int j = 1; j < i; j++) {
      if (p[j].second < p[i].second) {
        dp[i] -= dp[j] *
                 lucas(p[i].first - p[j].first + p[i].second - p[j].second,
                       p[i].first - p[j].first) %
                 mod;
        (dp[i] += mod) %= mod;
      }
    }
  }
  cout << dp[n + 1] << endl;
  return 0;
}
