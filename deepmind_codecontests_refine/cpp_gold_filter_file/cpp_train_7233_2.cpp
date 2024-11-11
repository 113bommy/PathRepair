#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, q;
  cin >> n >> m >> q;
  vector<vector<int> > v(n, vector<int>(m, 0));
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j) cin >> v[i][j];
  vector<int> row(n, 0);
  for (int i = 0; i < n; ++i) {
    int sum = 0;
    for (int j = 0; j < m; ++j) {
      if (v[i][j])
        sum++;
      else
        sum = 0;
      row[i] = max(row[i], sum);
    }
  }
  for (int i = 0; i < q; ++i) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    v[a][b] ^= 1;
    row[a] = 0;
    int sum = 0;
    for (int j = 0; j < m; ++j) {
      if (v[a][j])
        sum++;
      else
        sum = 0;
      row[a] = max(row[a], sum);
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) ans = max(ans, row[i]);
    cout << ans << endl;
  }
}
