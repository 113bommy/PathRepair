#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cout.tie(0);
  cin.tie(0);
  ;
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    vector<vector<int> > v(n, vector<int>(m));
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++) cin >> v[i][j];
    vector<vector<int> > cnt(n + m - 1, vector<int>(2));
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++) cnt[j + i][v[i][j]]++;
    int ans = 0;
    for (int i = 0; i <= n + m - 2; i++) {
      int j = n + m - 2 - i;
      if (i <= j) continue;
      ans = min(cnt[i][0] + cnt[j][0], cnt[j][1] + cnt[i][1]);
    }
    cout << ans << endl;
  }
  return 0;
}
