#include <bits/stdc++.h>
using namespace std;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
long long ans = 0;
long long n, k;
vector<long long> prefix[3005];
void solve(long long l, long long r, vector<long long> dp) {
  if (l == r) {
    long long sz = (long long)prefix[l].size() - 1;
    for (long long i = 0; i <= sz; i++)
      ans = max(ans, dp[k - i] + prefix[l][i]);
    return;
  }
  long long mid = (l + r) / 2;
  vector<long long> dp_l, dp_r;
  dp_l = dp;
  dp_r = dp;
  for (long long i = mid + 1; i <= r; i++) {
    long long sz = (long long)prefix[i].size() - 1, val = prefix[i].back();
    for (long long j = k; j >= sz; j--)
      dp_l[j] = max(dp_l[j], dp_l[j - sz] + val);
  }
  for (long long i = l; i <= mid; i++) {
    long long sz = (long long)prefix[i].size() - 1, val = prefix[i].back();
    for (long long j = k; j >= sz; j--)
      dp_r[j] = max(dp_r[j], dp_r[j - sz] + val);
  }
  solve(l, mid, dp_l);
  solve(mid + 1, r, dp_r);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> k;
  for (long long i = 1; i <= n; i++) {
    long long s;
    cin >> s;
    prefix[i].resize(s + 1);
    for (long long j = 1; j <= s; j++) {
      cin >> prefix[i][j];
      prefix[i][j] += prefix[i][j - 1];
    }
  }
  vector<long long> dp(k + 1);
  for (long long i = 1; i <= k; i++) dp[i] = -1e18;
  solve(1, n, dp);
  cout << ans << "\n";
}
