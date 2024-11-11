#include <bits/stdc++.h>
using namespace std;
const long long maxn = 1050;
long long cnk[maxn][maxn];
const long long mod = 1e9 + 7;
long long dp[maxn];
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long m, n;
  cin >> m >> n;
  cnk[0][0] = 1;
  for (long long i = 1; i < maxn; i++) {
    cnk[i][0] = 1;
    for (long long j = 1; j <= i; j++) {
      for (long long k = 0; k < 2; k++) {
        cnk[i][j] += cnk[i - 1][j - k];
        cnk[i][j] %= mod;
      }
    }
  }
  dp[0] = 1;
  for (long long i = 1; i < maxn; i++) {
    for (long long j = 0; j < i; j++) {
      dp[i] += cnk[i - 1][j] * dp[i - j - 1] % mod;
      dp[i] %= mod;
    }
  }
  vector<long long> mass;
  for (long long i = 0; i < m; i++) {
    mass.push_back(i);
  }
  vector<vector<long long> > united;
  united.push_back(mass);
  vector<string> s(n);
  for (long long i = 0; i < n; i++) {
    cin >> s[i];
    vector<vector<long long> > united1;
    for (long long j = 0; j < united.size(); j++) {
      vector<long long> go_to[2];
      for (long long u = 0; u < united[j].size(); u++) {
        long long ind = united[j][u];
        go_to[s[i][ind] - '0'].push_back(ind);
      }
      if (go_to[0].size()) {
        united1.push_back(go_to[0]);
      }
      if (go_to[1].size()) {
        united1.push_back(go_to[1]);
      }
    }
    united = united1;
  }
  long long ans = 1;
  for (long long i = 0; i < united.size(); i++) {
    ans = ans * dp[united[i].size()] % mod;
  }
  cout << ans;
  return 0;
}
