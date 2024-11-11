#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  vector<vector<int>> ar(2, vector<int>());
  vector<int> pref;
  vector<int> suf;
  for (int q = 0; q < t; ++q) {
    int m;
    cin >> m;
    ar[0].resize(m);
    ar[1].resize(m);
    pref.resize(m);
    suf.resize(m);
    int sum1 = 0;
    int sum2 = 0;
    for (int i = 0; i < 2; ++i) {
      for (int j = 0; j < m; ++j) {
        cin >> ar[i][j];
        if (i == 0)
          sum1 += ar[i][j];
        else
          sum2 += ar[i][j];
      }
    }
    suf[m - 1] = ar[1][m - 1];
    for (int i = m - 2; i > -1; --i) {
      suf[i] = ar[1][i] + suf[i + 1];
    }
    pref[0] = ar[0][0];
    int ans = 1e9;
    for (int i = 0; i < m; ++i) {
      pref[i] = ar[0][i] + pref[i - 1];
    }
    for (int i = 0; i < m; ++i) {
      ans = min(ans, max(sum1 - pref[i], sum2 - suf[i]));
    }
    cout << ans << "\n";
  }
}
