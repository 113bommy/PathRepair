#include <bits/stdc++.h>
using namespace std;
const long long maxn = 1e6 + 10;
const long long mod = 1e9 + 7;
long long h[maxn];
long long dp[maxn];
signed main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  long long n, k;
  cin >> n >> k;
  long long plus[] = {1, 2, 3, 5};
  cout << (6 * (n - 1) + 5) * k;
  for (long long i = 0; i < n; ++i) {
    for (long long j = 0; j < 4; ++j) {
      cout << (6 * i + plus[j]) * k << " ";
    }
    cout << "\n";
  }
}
