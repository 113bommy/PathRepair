#include <bits/stdc++.h>
using namespace std;
struct item {
  long long t, d, p, id;
} arr[105];
bool cmp(const struct item &a, const struct item &b) {
  if (a.d < b.d)
    return true;
  else if (a.d == b.d)
    return a.t < b.t;
  else
    return false;
}
long long n;
long long dp[105][50005];
long long solve(long long idx, long long curr) {
  if (idx > n || curr >= arr[n].d) return 0;
  if (dp[idx][curr] != -1) return dp[idx][curr];
  long long ans = 0;
  ans = solve(idx + 1, curr);
  if (curr + arr[idx].t < arr[idx].d) {
    ans = max(ans, arr[idx].p + solve(idx + 1, curr + arr[idx].t));
  }
  return dp[idx][curr] = ans;
}
vector<long long> ans;
void go(long long idx, long long curr) {
  if (idx > n) return;
  if (solve(idx + 1, curr) == solve(idx, curr)) {
    return go(idx + 1, curr);
  }
  ans.push_back(arr[idx].id);
  go(idx + 1, curr + arr[idx].t);
}
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long hh;
  cin >> n;
  for (long long i = 1; i <= n; ++i) {
    cin >> arr[i].t >> arr[i].d >> arr[i].p;
    arr[i].id = i;
  }
  memset(dp, -1, sizeof(dp));
  sort(arr + 1, arr + 1 + n, cmp);
  cout << solve(1, 0) << "\n";
  go(1, 0);
  cout << ans.size() << "\n";
  for (auto i : ans) cout << i << " ";
  return 0;
}
