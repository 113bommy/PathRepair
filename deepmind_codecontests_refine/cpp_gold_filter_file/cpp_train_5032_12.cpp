#include <bits/stdc++.h>
using namespace std;
int a[11][101], b[11][101], c[11][101];
int main() {
  int n, m, carr;
  cin >> n >> m >> carr;
  vector<pair<int, int> > p;
  string s;
  for (int i = 0; i < n; i++) {
    cin >> s;
    for (int j = 0; j < m; j++) cin >> a[i][j] >> b[i][j] >> c[i][j];
  }
  int mx = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      p.clear();
      for (int k = 0; k < m; k++)
        p.push_back(make_pair(b[j][k] - a[i][k], c[i][k]));
      sort(p.begin(), p.end());
      int left = carr;
      int prof = 0;
      for (int k = m - 1; k >= 0 && left > 0 && p[k].first > 0; k--) {
        prof += min(p[k].second, left) * p[k].first;
        left -= min(p[k].second, left);
      }
      if (prof > mx) mx = prof;
    }
  }
  cout << mx << endl;
  return 0;
}
