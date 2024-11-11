#include <bits/stdc++.h>
using namespace std;
pair<pair<int, int>, pair<int, int> > arr[110];
long long n;
vector<int> aa;
int dp[110][3000];
int go(int idx, int val) {
  if (idx == n + 1) return 0;
  if (dp[idx][val] != -1) {
    return dp[idx][idx];
  }
  int ans = 0;
  if (arr[idx].first.first > val + arr[idx].second.second) {
    ans = max(
        ans, go(idx + 1, val + arr[idx].second.second) + arr[idx].second.first);
  }
  ans = max(ans, go(idx + 1, val));
  return dp[idx][val] = ans;
}
void solve(int idx, int t) {
  if (idx == n + 1) return;
  if (dp[idx + 1][t] <
          dp[idx + 1][t + arr[idx].second.second] + arr[idx].second.first &&
      arr[idx].first.first > t + arr[idx].second.second) {
    aa.push_back(arr[idx].first.second);
    solve(idx + 1, t + arr[idx].second.second);
  } else {
    solve(idx + 1, t);
  }
}
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> arr[i].second.second >> arr[i].first.first >> arr[i].second.first;
    arr[i].first.second = i;
  }
  memset(dp, -1, sizeof(dp));
  sort(arr + 1, arr + n + 1);
  long long ans = go(1, 0);
  cout << ans << endl;
  solve(1, 0);
  cout << aa.size() << endl;
  for (int i = 0; i < aa.size(); i++) {
    cout << aa[i] << " ";
  }
  cout << endl;
}
