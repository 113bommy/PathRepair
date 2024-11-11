#include <bits/stdc++.h>
using namespace std;
const long long mod = 998244353;
const int N = 200000 + 7;
int main() {
  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; i++) cin >> arr[i];
  sort(arr.begin(), arr.end());
  vector<bool> a2(n + 2, false);
  for (int i = 0; i < n; i++) {
    if (a2[arr[i] - 1] == false)
      a2[arr[i] - 1] = true;
    else if (a2[arr[i]] == false)
      a2[arr[i]] = true;
    else if (a2[arr[i] + 1] == false)
      a2[arr[i] + 1] = true;
  }
  int ans2 = 0;
  for (int i = 0; i <= n + 1; i++) {
    if (a2[i]) ans2++;
  }
  auto it = unique(arr.begin(), arr.end());
  arr.resize(distance(arr.begin(), it));
  n = arr.size();
  vector<int> dp(n + 1, 0);
  dp[1] = 1;
  for (int i = 1; i < n; i++) {
    if (arr[i] - arr[i - 1] > 2) {
      dp[i + 1] = 1 + dp[i];
    } else {
      if (i == 1)
        dp[i + 1] = 1;
      else if (arr[i] - arr[i - 2] > 2)
        dp[i + 1] = 1 + dp[i - 1];
      else
        dp[i + 1] = 1 + dp[i - 2];
    }
  }
  cout << dp[n] << " " << ans2 << "\n";
  return 0;
}
