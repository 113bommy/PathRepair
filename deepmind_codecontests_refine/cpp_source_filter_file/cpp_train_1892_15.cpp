#include <bits/stdc++.h>
using namespace std;
int mapint(char cc) { return int(cc) - 96; }
char inttoc(int xx) { return char(xx + 96); }
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int done[229] = {0}, occ[29] = {0};
    vector<pair<int, int>> vv[229];
    pair<int, int> p[29];
    int n, m, mex = 0, yh = 1;
    cin >> n >> m;
    char arr[2002][2002];
    for (int i = 1; i <= n; i++) {
      p[i].first = 0;
      p[i].second = 0;
    }
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        cin >> arr[i][j];
        if (arr[i][j] != '.') {
          occ[mapint(arr[i][j])]++;
          mex = max(mex, mapint(arr[i][j]));
          p[mapint(arr[i][j])].first = i;
          p[mapint(arr[i][j])].second = j;
          if (done[mapint(arr[i][j])] == 0) {
            vv[mapint(arr[i][j])].push_back({i, j});
            done[mapint(arr[i][j])] = 1;
          }
        }
      }
    }
    for (int i = 1; i <= mex; i++) {
      if (p[i].first == 0 and p[i].second == 0) {
        vv[i].push_back({0, 0});
        vv[i].push_back({0, 0});
      }
      vv[i].push_back({p[i].first, p[i].second});
    }
    for (int i = 1; i <= mex; i++) {
      if (abs(vv[i][0].first == vv[i][1].first) or
          abs(vv[i][0].second == vv[i][1].second)) {
      } else {
        yh = 0;
      }
    }
    if (yh == 0) {
      cout << "NO" << '\n';
    } else {
      int no = 0;
      for (int i = mex; i >= 1; i--) {
        int cnt = 0;
        if (vv[i][0].first == 0 and vv[i][0].second == 0 and
            vv[i][1].first == 0 and vv[i][1].second == 0) {
          vv[i][0].first = vv[i + 1][0].first;
          vv[i][0].second = vv[i + 1][0].second;
          vv[i][1].first = vv[i + 1][1].first;
          vv[i][1].second = vv[i + 1][1].second;
        }
        if (abs(vv[i][0].first == vv[i][1].first)) {
          for (int j = vv[i][0].second; j <= vv[i][1].second; j++) {
            if (arr[vv[i][0].first][j] == '*' or
                arr[vv[i][0].first][j] == inttoc(i)) {
              arr[vv[i][0].first][j] = '*';
            } else {
              no = 1;
            }
          }
        } else {
          for (int j = vv[i][0].first; j <= vv[i][1].first; j++) {
            if (arr[j][vv[i][0].second] == '*') {
              arr[j][vv[i][0].second] = '*';
            } else if (arr[j][vv[i][0].second] == inttoc(i)) {
              arr[j][vv[i][0].second] = '*';
              cnt++;
            } else {
              no = 1;
            }
          }
          if (cnt == occ[mex]) {
          } else {
            no = 1;
          }
        }
      }
      if (no == 1) {
        cout << "NO" << '\n';
      } else {
        cout << "YES" << '\n';
        cout << mex << '\n';
        for (int i = 1; i <= mex; i++) {
          cout << vv[i][0].first << " " << vv[i][0].second << " "
               << vv[i][1].first << " " << vv[i][1].second << '\n';
        }
      }
    }
  }
}
