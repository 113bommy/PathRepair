#include <bits/stdc++.h>
using namespace std;
long long dp[101][100001];
vector<long long> pr;
vector<long long> t;
inline long long fine(long long l, long long r) {
  return t[r - 1] * (r - l + 1) - (pr[r] - pr[l - 1]);
}
void solve(long long lvl, long long l, long long r, long long optl,
           long long optr) {
  if (l >= r) {
    return;
  }
  long long m = (l + r) / 2;
  long long optm = -1;
  for (long long i = optl; i < optr; ++i) {
    if (i > m) {
      break;
    }
    if (dp[lvl][m] > dp[lvl - 1][i - 1] + fine(i, m)) {
      dp[lvl][m] = dp[lvl - 1][i - 1] + fine(i, m);
      optm = i;
    }
  }
  if (l + 1 == r) {
    return;
  }
  solve(lvl, l, m, optl, optm + 1);
  solve(lvl, m + 1, r, optm, optr);
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long n, m, p;
  cin >> n >> m >> p;
  vector<long long> d(n);
  for (long long i = 1; i < n; ++i) {
    cin >> d[i];
  }
  vector<long long> pref(n, 0);
  for (long long i = 1; i < n; ++i) {
    pref[i] = pref[i - 1] + d[i];
  }
  for (long long i = 0; i < m; ++i) {
    long long h, j;
    cin >> h >> j;
    t.push_back(j - pref[h - 1]);
  }
  sort(t.begin(), t.end());
  pr.assign(t.size() + 1, 0);
  for (long long i = 1; i <= t.size(); ++i) {
    pr[i] = pr[i - 1] + t[i - 1];
  }
  for (long long i = 0; i <= 100; ++i) {
    for (long long j = 0; j <= 100000; ++j) {
      dp[i][j] = 1e18;
    }
  }
  dp[0][0] = 0;
  for (long long i = 1; i <= p; ++i) {
    solve(i, 1, t.size() + 1, 1, t.size() + 1);
  }
  cout << dp[p][n];
}
