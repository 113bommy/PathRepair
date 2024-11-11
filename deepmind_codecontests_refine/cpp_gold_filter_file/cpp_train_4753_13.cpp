#include <bits/stdc++.h>
using namespace std;
const long long inf = 1e6;
const long long N = 505;
long long dp[N][N], tt[N][N];
string s[N];
long long n, m, k;
long long solve(long long id, long long rem) {
  if (rem < 0) return inf;
  if (id >= n) return 0;
  long long &tmp = dp[id][rem];
  if (tmp != -1) return tmp;
  tmp = inf;
  for (long long k = 0; tt[id][k] != -1; k++)
    tmp = min(tmp, solve(id + 1, rem - k) + tt[id][k]);
  return tmp;
}
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> m >> k;
  memset(tt, 1, sizeof tt);
  for (long long i = 0; i < n; i++) {
    cin >> s[i];
    vector<long long> v;
    for (long long j = 0; j < m; j++) {
      if (s[i][j] == '1') v.push_back(j);
    }
    tt[i][v.size()] = 0;
    for (long long l = 0; l < v.size(); l++) {
      for (long long r = l; r < v.size(); r++) {
        long long cur = l + v.size() - r - 1;
        tt[i][cur] = min(tt[i][cur], v[r] - v[l] + 1);
      }
    }
    tt[i][v.size() + 1] = -1;
  }
  memset(dp, -1, sizeof dp);
  long long ans = solve(0, k);
  cout << ans << endl;
}
