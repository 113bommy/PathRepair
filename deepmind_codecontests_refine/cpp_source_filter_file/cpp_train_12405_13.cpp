#include <bits/stdc++.h>
using namespace std;
const long long mod = 998244353;
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long n;
  cin >> n;
  vector<long long> degree(n + 1, 0);
  for (long long i = 0; i < n - 1; ++i) {
    long long u, v;
    cin >> u >> v;
    ++degree[u];
    ++degree[v];
  }
  long long res = 1;
  for (long long i = 1; i <= n; ++i) {
    for (long long j = 1; j <= degree[i]; ++j) {
      res *= j;
      res %= mod;
    }
  }
  cout << res * 4 % mod << '\n';
}
