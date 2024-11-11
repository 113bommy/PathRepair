#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  int m, n;
  cin >> m >> n;
  vector<vector<bool>> st(m, vector<bool>(n));
  for (int i = 0; i < m; ++i) {
    int t;
    cin >> t;
    while (t--) {
      int s;
      cin >> s;
      st[i][s - 1] = true;
    }
  }
  string ans = "possible";
  for (int i = 0; i < m; ++i) {
    for (int j = i + 1; j < m; ++j) {
      bool ok = false;
      for (int k = 0; k < n; ++k) {
        ok |= st[i][k] & st[j][k];
      }
      if (!ok) {
        ans = "impossible";
      }
    }
  }
  cout << ans;
  return 0;
}
