#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
void pr_init() {}
long long dp[2005][27];
vector<vector<long long> > gp;
void solve() {
  long long t;
  cin >> t;
  for (long long te = 0; te < t; te++) {
    long long n;
    cin >> n;
    long long a[n + 1];
    gp.assign(27, vector<long long>());
    for (long long j = 1; j < n + 1; j++) {
      cin >> a[j];
      gp[a[j]].push_back(j);
    }
    for (long long i = 1; i < n + 1; i++) {
      for (long long j = 0; j < 27; j++) dp[i][j] = dp[i - 1][j];
      dp[i][a[i]]++;
    }
    long long len = 0;
    for (long long i = 1; i < 27; i++)
      if ((long long)gp[i].size() > 0) {
        for (long long k = 1; k <= 26; k++) {
          for (long long l = 0; l < (long long)gp[i].size(); l++) {
            for (long long z = 0; z <= l; z++) {
              len = max(len, l - z + 1 +
                                 2 * min(dp[gp[i][z] - 1][k],
                                         dp[n][k] - dp[gp[i][l]][k]));
            }
          }
        }
      }
    cout << len << endl;
  }
}
int32_t main() {
  pr_init();
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  auto start = high_resolution_clock::now();
  solve();
  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop - start);
  return 0;
}
