#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int INF = 1e9;
const int MOD = 1e9 + 7;
bool subsetSum(vector<int>& arr, int target, int n) {
  bool dp[2][target + 1];
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= target; j++) {
      if (j == 0)
        dp[i % 2][j] = 1;
      else if (i == 0)
        dp[i % 2][j] = 0;
      else if (arr[i] <= j)
        dp[i % 2][j] = (dp[(i + 1) % 2][j] || dp[(i + 1) % 2][j - arr[i]]);
      else
        dp[i % 2][j] = dp[(i + 1) % 2][j];
    }
  }
  return dp[n % 2][target];
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    n *= 2;
    int p[n + 1];
    vector<int> pos(n + 1);
    for (int i = 1; i <= n; i++) {
      cin >> p[i];
      pos[p[i]] = i;
    }
    int right = n + 1;
    int ele = n;
    vector<int> arr;
    while (ele > 0) {
      int position = pos[ele];
      if (position < right) {
        arr.emplace_back(right - position);
        right = position;
      }
      ele--;
    }
    int length = arr.size();
    bool ans = subsetSum(arr, n / 2, length);
    if (ans)
      cout << "YES"
           << "\n";
    else
      cout << "NO"
           << "\n";
  }
}
