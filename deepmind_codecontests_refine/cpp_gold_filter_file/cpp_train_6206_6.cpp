#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;
long long cities[41];
long long dp[(1 << 21)];
long long fastpow(long long a, long long b) {
  long long ret = 1;
  while (b) {
    if (b % 2) ret = (ret * a) % MOD;
    a = (a * a) % MOD;
    b >>= 1;
  }
  return ret;
}
string print(long long mask) {
  string s;
  for (int i = 20; i >= 0; i--) {
    if (mask & (1 << i))
      s += '1';
    else
      s += '0';
  }
  return s;
}
int main() {
  int n, k;
  cin >> n >> k;
  if (n == 1) return puts("0");
  for (int i = 0; i < n; i++) {
    int a;
    long long tot = 0;
    for (int j = 0; j < n; j++) {
      cin >> a;
      if (a) tot |= (1LL << j);
    }
    tot |= (1LL << i);
    cities[i] = tot;
  }
  int h = 20;
  int h2 = n - h;
  long long sz = 0;
  long long tmpmask = (1 << h) - 1;
  if (h2 > 0) {
    for (long long i = 1; i < (1 << h2); i++) {
      long long mask = i;
      for (int j = 0; j < h2; j++) {
        if ((i >> j) & 1) {
          mask &= cities[j + h] >> h;
        }
      }
      if (mask == i) dp[mask] = __builtin_popcount(i);
    }
    for (long long i = 1; i < (1 << h2); i++) {
      for (int j = 0; j < h2; j++) {
        if ((i >> j) & 1) {
          dp[i] = max(dp[i], dp[i ^ (1 << j)]);
        }
      }
    }
  }
  for (long long i = 1; i < (1 << min(h, n)); i++) {
    long long mask = i;
    long long mask2 = (1 << max(0, h2)) - 1;
    for (int j = 0; j < h; j++) {
      if ((i >> j) & 1) {
        mask &= (cities[j] & tmpmask);
        mask2 &= (cities[j] >> h);
      }
    }
    if (mask == i) sz = max(sz, dp[mask2] + __builtin_popcount(i));
  }
  cout << fixed << setprecision(9) << k * k * (sz - 1) / (sz * (2.0)) << endl;
}
