#include <bits/stdc++.h>
using namespace std;
int n, m;
char c;
vector<vector<char>> v;
vector<char> neighbor(int i, int j) {
  vector<char> res;
  if (i > 0 && i < n - 1) {
    res.push_back(v[i - 1][j]);
    res.push_back(v[i + 1][j]);
  } else if (i > 0)
    res.push_back(v[i - 1][j]);
  else if (i < n - 1)
    res.push_back(v[i + 1][j]);
  if (j > 0 && i < m - 1) {
    res.push_back(v[i][j - 1]);
    res.push_back(v[i][j + 1]);
  } else if (j > 0)
    res.push_back(v[i][j - 1]);
  else if (j < m - 1)
    res.push_back(v[i][j + 1]);
  return res;
}
int main() {
  cin >> n >> m >> c;
  for (int i = 0; i < n; i++) {
    vector<char> vt;
    for (int j = 0; j < m; j++) {
      char t;
      cin >> t;
      vt.push_back(t);
    }
    v.push_back(vt);
  }
  set<char> s;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (v[i][j] == c) {
        for (auto g : neighbor(i, j)) {
          if (g != c && g != '.') s.insert(g);
        }
      }
    }
  }
  cout << s.size();
}
