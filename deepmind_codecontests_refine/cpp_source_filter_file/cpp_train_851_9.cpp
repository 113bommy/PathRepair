#include <bits/stdc++.h>
using namespace std;
long long int power(long long int a, long long int b) {
  long long int ans = 1;
  while (b) {
    if (b & 1LL) ans = (ans * a) % 1000000007;
    a = (a * a) % 1000000007;
    b = b >> 1LL;
  }
  return ans;
}
long long int n;
long long int a[2 * 100005];
long long int dp[2 * 100005][3];
long long int solve(long long int ind, long long int i2) {
  if (dp[ind][i2] != (long long int)1e18) {
    return dp[ind][i2];
  }
  if (ind == n + 1) {
    return 0;
  }
  if (ind + 3 + i2 > n + 1) {
    return (long long int)1e18;
  }
  long long int ans = (long long int)1e18;
  for (long long int j = 0; j < 3; j++) {
    ans = min(ans, solve(ind + 3 + i2, j));
  }
  ans += a[ind + 2 + i2] - a[ind];
  return dp[ind][i2] = ans;
}
pair<long long int, long long int> inds[2 * 100005];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  ;
  cin >> n;
  for (long long int i = 1; i < n + 1; i++) {
    cin >> a[i];
    inds[i].first = a[i];
    inds[i].second = i;
  }
  sort(a, a + n + 1);
  sort(inds, inds + n + 1);
  for (long long int i = 0; i < n + 1; i++) {
    for (long long int j = 0; j < 3; j++) {
      dp[i][j] = (long long int)1e18;
    }
  }
  long long int ans = min(solve(1, 0), min(solve(1, 1), solve(1, 2)));
  long long int steps = 0;
  long long int i = 1;
  cout << ans << " ";
  std::vector<pair<long long int, long long int> > v;
  while (i != n + 1) {
    int k = 0;
    if (dp[i][0] < dp[i][1] && dp[i][0] < dp[i][2]) {
      k = 0;
    }
    if (dp[i][1] < dp[i][2] && dp[i][1] < dp[i][0]) {
      k = 1;
    }
    if (dp[i][2] < dp[i][1] && dp[i][0] > dp[i][2]) {
      k = 2;
    }
    v.push_back(make_pair(i, 3 + k));
    steps++;
    i = i + 3 + k;
  }
  cout << steps << " \n";
  long long int team = 1;
  long long int ans1[2 * 100005] = {0};
  for (long long int k = 0; k < v.size(); k++) {
    for (long long int j = 0; j < v[k].second; j++) {
      ans1[inds[v[k].first + j].second] = team;
    }
    team++;
  }
  for (long long int i = 1; i < n + 1; i++) {
    cout << ans1[i] << " ";
  }
  return 0;
}
