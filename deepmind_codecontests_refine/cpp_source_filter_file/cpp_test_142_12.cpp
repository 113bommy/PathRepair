#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  long long t;
  cin >> t;
  while (t--) {
    long long m, n;
    cin >> m >> n;
    vector<vector<long long>> p(m + 1, vector<long long>(n + 1, 0));
    vector<long long> max_fr(n + 1, -1);
    for (long long i = 1; i < m + 1; i++)
      for (long long j = 1; j < n + 1; j++) {
        cin >> p[i][j];
        max_fr[j] = max(max_fr[j], p[i][j]);
      }
    long long sec = -1;
    long long ans = 1e8;
    for (long long i = 1; i < n + 1; i++) ans = min(ans, max_fr[i]);
    if (m <= n - 1) {
      cout << ans << "\n";
      continue;
    }
    long long val = -1;
    for (long long i = 1; i < m + 1; i++) {
      sort(p[i].begin(), p[i].end());
      val = max(val, p[i][n - 1]);
    }
    ans = min(ans, val);
    cout << ans << "\n";
  }
}
