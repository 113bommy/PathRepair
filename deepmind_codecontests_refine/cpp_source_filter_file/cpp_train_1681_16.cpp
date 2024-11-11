#include <bits/stdc++.h>
const int mod = 1000000007;
const long long inf = 1LL << 60;
using namespace std;
vector<vector<int> > r, g, c;
vector<int> mxr, mxc;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  r.assign(n, vector<int>(m));
  c.assign(n, vector<int>(m));
  g.assign(n, vector<int>(m));
  mxr.assign(n, 0);
  mxc.assign(m, 0);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> g[i][j];
    }
  }
  for (int i = 0; i < n; i++) {
    vector<pair<int, int> > v(m);
    for (int j = 0; j < m; j++) {
      v[j] = {g[i][j], j};
    }
    sort(v.begin(), v.end());
    for (int j = 0; j < m; j++) {
      if (j) {
        if (v[j].first == v[j - 1].first)
          r[i][v[j].second] = r[i][v[j - 1].second];
        else
          r[i][v[j].second] = r[i][v[j - 1].second] + 1;
      } else
        r[i][v[j].second] = 1;
      mxr[j] = max(mxr[j], r[i][v[j].second]);
    }
  }
  for (int j = 0; j < m; j++) {
    vector<pair<int, int> > v(n);
    for (int i = 0; i < n; i++) {
      v[i] = {g[i][j], i};
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < n; i++) {
      if (i) {
        if (v[i].first == v[i - 1].first)
          c[v[i].second][j] = c[v[i - 1].second][j];
        else
          c[v[i].second][j] = c[v[i - 1].second][j] + 1;
      } else
        c[v[i].second][j] = 1;
      mxc[j] = max(mxc[j], c[v[i].second][j]);
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int diff = abs(c[i][j] - r[i][j]);
      if (c[i][j] > r[i][j]) {
        cout << max(mxc[j], mxr[i] + diff) << " ";
      } else {
        cout << max(mxc[j] + diff, mxr[i]) << " ";
      }
    }
    cout << endl;
  }
  return 0;
}
