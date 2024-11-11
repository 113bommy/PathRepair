#include <bits/stdc++.h>
using namespace std;
const long long N = 1e2 + 10;
const long long EE = 1e6 + 10;
const long long mod = 1e9 + 7;
long long n, T;
long long d[EE][5], t[N], g[N];
long long ans;
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> T;
  for (long long i = 0; i < n; ++i) cin >> t[i] >> g[i];
  long long mass = (1 << n);
  for (long long j = 0; j < n; ++j) {
    d[1 << j][g[j]]++;
  }
  for (long long i = 1; i < mass; ++i) {
    long long sum = 0;
    for (long long j = 0; j < n; ++j) {
      if (i & (1 << j)) {
        long long f, s;
        if (g[j] == 1) f = 2, s = 3;
        if (g[j] == 2) f = 1, s = 3;
        if (g[j] == 3) f = 2, s = 1;
        d[i][g[j]] =
            (d[i][g[j]] + d[i ^ (1 << j)][f] + d[i ^ (1 << j)][s]) % mod;
        sum += t[j];
      }
    }
    if (sum == T) {
      ans = (ans + d[i][1] + d[i][2] + d[i][3]) % mod;
    }
  }
  cout << ans;
  return 0;
}
