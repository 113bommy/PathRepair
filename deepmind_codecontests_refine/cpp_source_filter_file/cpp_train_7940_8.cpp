#include <bits/stdc++.h>
using namespace std;
const int N = 5e5, F = 2147483646, K = 22;
int n, k, arr[N], b[N], ans;
void solve() {
  cin >> n >> k;
  for (int i = 1; i <= n; i++) cin >> arr[i];
  for (int i = 1; i <= k; i++) cin >> b[i];
  for (int i = 1; i < k; i++) {
    if (arr[b[i + 1]] - arr[b[i]] < b[i + 1] - b[i] - 1) {
      cout << -1;
      return;
    }
  }
  for (int i = 1; i <= n; i++) arr[i] -= i;
  b[0] = 0, b[k + 1] = n + 1;
  arr[0] = -1e9;
  arr[n + 1] = 2e9;
  ans = 0;
  for (int i = 0; i <= k; i++) {
    vector<int> lis;
    for (int j = b[i] + 1; j < b[i + 1]; j++) {
      if (arr[b[i]] > arr[j] || arr[j] > arr[b[i + 1]]) continue;
      auto it = upper_bound(lis.begin(), lis.end(), arr[j]);
      if (it == lis.end())
        lis.push_back(arr[j]);
      else
        *it = arr[j];
    }
    ans += b[i + 1] - b[i] - 1 - int(lis.size());
  }
  cout << ans;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);
  int T = 1;
  while (T--) {
    solve();
  }
  return 0;
}
