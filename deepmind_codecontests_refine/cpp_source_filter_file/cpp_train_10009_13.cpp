#include <bits/stdc++.h>
using namespace std;
int mat[1005][1005];
int val[1005][1005];
int hal[1005][1005];
int vmax[1005];
int hmax[1005];
pair<int, int> hlp[1005];
int res[1005][1005];
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> mat[i][j];
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      hlp[j] = {mat[i][j], j};
    }
    sort(hlp, hlp + m);
    int lt = hlp[0].first;
    hlp[0].first = 1;
    for (int j = 1; j < m; ++j) {
      if (hlp[j].first == lt) {
        hlp[j].first = hlp[j - 1].first;
      } else {
        lt = hlp[i].first;
        hlp[j].first = hlp[j - 1].first + 1;
      }
    }
    for (int j = 0; j < m; ++j) {
      hal[i][hlp[j].second] = hlp[j].first;
      hmax[i] = max(hmax[i], hal[i][hlp[j].second]);
    }
  }
  for (int j = 0; j < m; ++j) {
    for (int i = 0; i < n; ++i) {
      hlp[i] = {mat[i][j], i};
    }
    sort(hlp, hlp + n);
    int lt = hlp[0].first;
    hlp[0].first = 1;
    for (int i = 1; i < n; ++i) {
      if (hlp[i].first == lt) {
        hlp[i].first = hlp[i - 1].first;
      } else {
        lt = hlp[i].first;
        hlp[i].first = hlp[i - 1].first + 1;
      }
    }
    for (int i = 0; i < n; ++i) {
      val[hlp[i].second][j] = hlp[i].first;
      vmax[j] = max(vmax[j], val[hlp[i].second][j]);
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (val[i][j] == hal[i][j]) {
        res[i][j] = max(hmax[i], vmax[j]);
      } else if (val[i][j] < hal[i][j]) {
        res[i][j] = max(hmax[i], vmax[j] + hal[i][j] - val[i][j]);
      } else {
        res[i][j] = max(hmax[i] + val[i][j] - hal[i][j], vmax[j]);
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cout << res[i][j] << " ";
    }
    cout << "\n";
  }
  cout << "\n";
  return 0;
}
