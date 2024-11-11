#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  int in[1000][1000];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> in[i][j];
    }
  }
  static int row[1000][1000] = {}, col[1000][1000] = {}, rs[1000] = {},
             cs[1000] = {};
  for (int i = 0; i < n; i++) {
    vector<int> v;
    for (int j = 0; j < m; j++) {
      v.push_back(in[i][j]);
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    for (int j = 0; j < m; j++) {
      row[i][j] = lower_bound(v.begin(), v.end(), in[i][j]) - v.begin();
    }
    rs[i] = v.size();
  }
  for (int j = 0; j < m; j++) {
    vector<int> v;
    for (int i = 0; i < n; i++) {
      v.push_back(in[i][j]);
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    for (int i = 0; i < n; i++) {
      col[i][j] = lower_bound(v.begin(), v.end(), in[i][j]) - v.begin();
    }
    cs[j] = v.size();
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (j > 0) cout << " ";
      cout << max(row[i][j], col[i][j]) +
                  max(rs[i] - row[i][j], cs[j] - col[i][j]);
    }
    cout << endl;
  }
  return 0;
}
