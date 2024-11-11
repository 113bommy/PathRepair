#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
const int N = 10010;
long long n, k, f[N][60], ans = 1;
vector<pair<long long, int>> p;
long long qpow(long long a, long long n = MOD - 2, long long m = MOD) {
  a %= m;
  long long res = 1;
  while (n) {
    if (n & 1) res = res * a % m;
    a = a * a % m, n >>= 1;
  }
  return res;
}
int main() {
  cin >> n >> k;
  for (int i = 2; (long long)i * i <= n; i++) {
    if (n % i == 0) {
      p.push_back({i, 0});
      while (n % i == 0) {
        n /= i;
        p[p.size() - 1].second++;
      }
    }
  }
  if (n > 1) {
    p.push_back({n, 1});
  }
  for (auto t : p) {
    for (int i = 0; i <= t.second; i++) {
      for (int j = 0; j <= k; j++) {
        f[j][i] = 0;
      }
    }
    f[0][t.second] = 1;
    for (int i = 1; i <= k; i++) {
      for (int j = 0; j <= t.second; j++) {
        f[i][0] += f[i - 1][j] * qpow(j + 1) % MOD;
        f[i][j + 1] -= f[i - 1][j] * qpow(j + 1) % MOD;
      }
      for (int j = 1; j <= t.second; j++) {
        f[i][j] += f[i][j - 1];
        f[i][j] %= MOD;
      }
    }
    long long res = 0;
    for (int i = 0; i <= t.second; i++) {
      res += qpow(t.first, i) * f[k][i] % MOD;
      res %= MOD;
    }
    ans = ans * res % MOD;
  }
  cout << ans;
}
