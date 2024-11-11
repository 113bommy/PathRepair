#include <bits/stdc++.h>
using namespace std;
const double EPS = 1e-9;
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long n, x;
  cin >> n >> x;
  vector<long long> a(n);
  for (long long i = (0); i < ((n)); ++i) cin >> a[i];
  vector<long long> sum(n + 1, 0);
  for (long long i = (0); i < ((n)); ++i) sum[i + 1] = sum[i] + a[i];
  set<long long> dp[55][55];
  dp[0][0].insert((1LL << 51) - 1);
  for (long long i = (0); i < ((x)); ++i) {
    for (long long j = (0); j < ((n)); ++j) {
      for (long long k = (0); k < ((j + 1)); ++k) {
        for (auto itr = (dp[i][k]).begin(); itr != (dp[i][k]).end(); ++itr)
          dp[i + 1][j + 1].insert(*itr & (sum[j + 1] - sum[k]));
      }
    }
  }
  cout << *dp[x][n].rbegin() << endl;
  return 0;
}
