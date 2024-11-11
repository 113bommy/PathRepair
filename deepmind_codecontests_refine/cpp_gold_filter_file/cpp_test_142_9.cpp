#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long m, n;
  cin >> m >> n;
  vector<vector<long long>> arr(m, vector<long long>(n));
  vector<long long> adj(n, -1);
  for (long long i = 0; i < m; i++) {
    for (long long j = 0; j < n; j++) {
      cin >> arr[i][j];
      adj[j] = max(adj[j], arr[i][j]);
    }
  }
  long long a = INT_MAX;
  for (long long i = 0; i < n; i++) {
    a = min(a, adj[i]);
  }
  if (m <= n - 1) {
    cout << a;
    return;
  }
  long long x = -1;
  for (long long i = 0; i < m; i++) {
    sort(arr[i].begin(), arr[i].end());
    x = max(x, arr[i][n - 2]);
  }
  cout << min(x, a);
  return;
}
int32_t main() {
  long long t;
  cin >> t;
  while (t--) {
    solve();
    cout << "\n";
  }
}
