#include <bits/stdc++.h>
using namespace std;
const long long N = 1e12;
void f(long long& x) {
  if (x > N) x = N;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cerr.tie(nullptr);
  long long n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  vector<vector<long long> > l(n, vector<long long>(30, -1));
  for (long long i = 0; i < n; ++i) {
    for (long long j = 0; j <= ('z' - 'a'); ++j) {
      for (long long t = 0; t <= i; ++t) {
        if (s[t] == (j + 'a')) {
          l[i][j] = max(l[i][j], t);
        }
      }
    }
  }
  vector<vector<long long> > dp(n, vector<long long>(n + 5, 0));
  for (long long i = 0; i < n; ++i) {
    dp[i][1] = 1;
  }
  for (long long j = 2; j <= n; ++j) {
    for (long long i = 0; i < n; ++i) {
      if (i - j + 1 < 0) continue;
      for (long long t = 0; t <= ('z' - 'a'); ++t) {
        if (l[i - 1][t] == -1) continue;
        dp[i][j] += dp[l[i - 1][t]][j - 1];
        f(dp[i][j]);
      }
    }
  }
  long long sol = 0, cnt = 0;
  for (long long j = n; j >= 1; --j) {
    for (long long t = 0; t <= 'z' - 'a'; ++t) {
      if (l[n - 1][t] == -1) continue;
      long long cur = min(k - cnt, dp[l[n - 1][t]][j]);
      sol += cur * (n - j);
      cnt += cur;
    }
  }
  if (cnt < k) {
    ++cnt;
    sol += n;
  }
  if (cnt < k)
    cout << "-1\n";
  else
    cout << sol << '\n';
}
