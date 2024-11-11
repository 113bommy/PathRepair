#include <bits/stdc++.h>
using namespace std;
vector<int> adj[100001];
void solve() {
  int n;
  cin >> n;
  int t[n];
  for (int i = 0; i < n; i++) cin >> t[i];
  int ans[n];
  int sum[n];
  ans[0] = 20;
  sum[0] = 20;
  for (int i = 1; i < n; i++) {
    int it1 = (upper_bound(t, t + n, t[i] - 90) - t);
    int it2 = (upper_bound(t, t + n, t[i] - 1440) - t);
    if (sum[i - 1] - (it2 > 0) * sum[it2 - 1] >= 120) {
      ans[i] = 0;
      sum[i] = sum[i - 1];
      continue;
    }
    if (sum[i - 1] - (it1 > 0) * sum[it1 - 1] >= 50) {
      ans[i] = 0;
      sum[i] = sum[i - 1];
      continue;
    }
    if (sum[i - 1] - (it2 > 0) * sum[it2 - 1] >= 100) {
      ans[i] = 120 - (sum[i - 1] - (it2 > 0) * sum[it2 - 1]);
    } else if ((sum[i - 1] - (it1 > 0) * sum[it1 - 1]) >= 30) {
      ans[i] = 50 - (sum[i - 1] - (it1 > 0) * sum[it1 - 1]);
    } else
      ans[i] = 20;
    sum[i] = sum[i - 1] + ans[i];
  }
  for (int i = 0; i < n; i++) cout << ans[i] << endl;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
