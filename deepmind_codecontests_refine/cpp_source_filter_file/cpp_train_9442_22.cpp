#include <bits/stdc++.h>
using namespace std;
using lli = long long;
using ld = long double;
mt19937 rnd(time(nullptr));
const lli LG = 56;
lli n = 0, k = 0;
vector<lli> values;
bool Check(lli mask) {
  vector<vector<bool>> dp(n, vector<bool>(k, false));
  for (int i = 0, sum = 0; i < n; i++) {
    sum += values[i];
    dp[i][0] = ((sum | mask) == sum);
  }
  for (lli a = 1; a < n; a++) {
    for (lli b = 1; b < k; b++) {
      lli sum = 0;
      for (lli c = a; c >= 1; c--) {
        sum += values[c];
        if ((dp[c - 1][b - 1]) && ((sum | mask) == sum)) {
          dp[a][b] = true;
          break;
        }
      }
    }
  }
  return dp[n - 1][k - 1];
}
inline void Solve() {
  cin >> n >> k;
  values.resize(n);
  for (auto &it : values) cin >> it;
  lli result = 0;
  for (lli j = LG - 1; j >= 0; j--) {
    if (Check((result | (1LL << j)))) result |= (1LL << j);
  }
  cout << result;
}
signed main() {
  cout << fixed << setprecision(20);
  Solve();
  return 0;
}
