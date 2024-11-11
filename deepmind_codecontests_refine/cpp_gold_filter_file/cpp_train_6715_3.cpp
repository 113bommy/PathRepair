#include <bits/stdc++.h>
using namespace std;
const int N = 1000010;
const int nn = (N - 10) / 2;
const int M = 1000000007;
int n, k, a[N];
long long l;
vector<int> v;
long long times(int p, int k) {
  int pl = l % n;
  if (pl == 0) pl = n;
  int t = int(p <= pl);
  long long ts = (l - 1) / n + t;
  return max(0LL, ts - k + 1);
}
int main() {
  ios::sync_with_stdio(0);
  cin >> n >> l >> k;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    v.push_back(a[i]);
  }
  sort(v.begin(), v.end());
  v.erase(unique(v.begin(), v.end()), v.end());
  for (int i = 1; i <= n; ++i)
    a[i] = lower_bound(v.begin(), v.end(), a[i]) - v.begin() + 1;
  vector<vector<int> > dp(k + 5);
  vector<vector<int> > sm(k + 5);
  for (int i = 1; i <= k; ++i) dp[i].resize(n + 5);
  for (int i = 1; i <= k; ++i) sm[i].resize(n + 5);
  for (int j = 1; j <= n; ++j) {
    dp[1][j] = 1;
    sm[1][a[j]]++;
  }
  for (int j = 1; j <= n; ++j) sm[1][j] += sm[1][j - 1];
  for (int i = 2; i <= k; ++i) {
    for (int j = 1; j <= n; ++j) {
      dp[i][j] = sm[i - 1][a[j]] % M;
    }
    for (int j = 1; j <= n; ++j) {
      sm[i][a[j]] += dp[i][j];
      sm[i][a[j]] %= M;
    }
    for (int j = 1; j <= n; ++j) {
      sm[i][j] += sm[i][j - 1];
      sm[i][j] %= M;
    }
  }
  int ans = 0;
  for (int kk = 1; kk <= k; ++kk) {
    for (int i = 1; i <= n; ++i)
      ans = (ans + (1LL * dp[kk][i] * (times(i, kk) % M)) % M) % M;
  }
  cout << ans << '\n';
}
