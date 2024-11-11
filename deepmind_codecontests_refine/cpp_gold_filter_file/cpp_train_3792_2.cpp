#include <bits/stdc++.h>
using namespace std;
using lli = long long;
using ld = long double;
mt19937 rnd(time(nullptr));
const lli mod = 1e9 + 7;
inline void Solve() {
  lli n = 0;
  cin >> n;
  vector<lli> data(n);
  for (auto& it : data) cin >> it;
  lli result = 0;
  vector<map<lli, lli>> dp(n + 1);
  for (lli i = 0; i < n; i++) {
    dp[i + 1][+data[i]] = 1;
    dp[i + 1][-data[i]] = 1;
    for (auto it : dp[i]) {
      lli d = it.first;
      if (abs(d) > 10000) break;
      lli& value1 = dp[i + 1][d + data[i]];
      lli& value2 = dp[i + 1][abs(d - data[i])];
      value1 = (value1 + it.second) % mod;
      value2 = (value2 + it.second) % mod;
    }
    result = (result + dp[i + 1][0]) % mod;
  }
  cout << result;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cout << fixed << setprecision(20);
  Solve();
  return 0;
}
