#include <bits/stdc++.h>
using namespace std;
void prepare() {}
inline int get_(int i, int j, vector<vector<int> > &used) {
  if (i < 0 || i >= used.size() || j < 0 || j >= used[0].size()) return -1;
  return used[i][j];
}
void solve() {
  int n, m;
  cin >> n >> m;
  string s;
  cin >> s;
  vector<char> color(1);
  vector<vector<char> > v(n, vector<char>(s.size()));
  vector<vector<int> > used(n, vector<int>(s.size()));
  for (int j = 0; j < s.size(); ++j) {
    v[0][j] = s[j];
    if (v[0][j] == '0') used[0][j] = -1;
  }
  for (int i = 1; i < n; ++i) {
    cin >> s;
    for (int j = 0; j < s.size(); ++j) {
      v[i][j] = s[j];
      if (v[i][j] == '0') used[i][j] = -1;
    }
  }
  int id = 1;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < v[0].size(); ++j)
      if (!used[i][j]) {
        int d = i + 1, r = j + 1;
        while (d < n && v[i][j] == v[d][j]) ++d;
        while (r < v[0].size() && v[i][j] == v[i][r]) ++r;
        for (int q = i; q < d; ++q)
          for (int p = j; p < r; ++p) used[q][p] = id;
        color.push_back(v[i][j]);
        ++id;
      }
  }
  vector<vector<int> > g(id, vector<int>(8));
  ;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < v[0].size(); ++j)
      if (used[i][j] > 0 && v[i][j] != '0') {
        int d = i + 1, r = j + 1;
        while (d < n && used[i][j] == used[d][j]) ++d;
        while (r < used[0].size() && used[i][j] == used[i][r]) ++r;
        id = used[i][j];
        for (int q = i; q < d; ++q)
          for (int p = j; p < r; ++p) v[q][p] = '0';
        g[id][0] = get_(d - 1, j - 1, used);
        g[id][1] = get_(i, r, used);
        g[id][2] = get_(i - 1, j, used);
        g[id][3] = get_(d, r - 1, used);
        g[id][4] = get_(i, j - 1, used);
        g[id][5] = get_(d - 1, r, used);
        g[id][6] = get_(i - 1, r - 1, used);
        g[id][7] = get_(d, j, used);
      }
  }
  id = 1;
  int dp = 1, cp = 0;
  for (int i = 0; i < m; ++i) {
    if (g[id][cp * 4 + dp] != -1)
      id = g[id][cp * 4 + dp];
    else {
      if (cp == 0)
        cp = 1;
      else {
        cp = 0;
        if (dp == 0)
          dp = 2;
        else if (dp == 1)
          dp = 3;
        else if (dp == 2)
          dp = 1;
        else
          dp = 0;
      }
    }
  }
  cout << color[id] << endl;
}
int main() {
  prepare();
  solve();
  return 0;
}
