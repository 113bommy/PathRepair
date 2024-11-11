#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<int> > a(n, vector<int>(m));
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j) cin >> a[i][j], --a[i][j];
  long long ans = 0;
  for (int j = 0; j < m; ++j) {
    vector<int> count(n);
    for (int i = 0; i < n; ++i)
      if (a[i][j] % m == j) {
        int p = a[i][j] / m;
        if (p < n) {
          if (p <= i)
            ++count[i - p];
          else
            ++count[n - p + i];
        }
      }
    int mn = m;
    for (int i = 0; i < n; ++i) mn = min(mn, i + n - count[i]);
    ans += mn;
  }
  cout << ans << endl;
  return 0;
}
