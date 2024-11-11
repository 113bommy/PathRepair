#include <bits/stdc++.h>
using namespace std;
const int maxN = 150, MOD = 1e9 + 7;
const long long INF = LLONG_MAX >> 1;
vector<vector<int>> transp(const vector<vector<int>> &v) {
  vector<vector<int>> ret(v[0].size(), vector<int>(v.size()));
  for (int i = 0; i < v.size(); i++) {
    for (int j = 0; j < v[0].size(); j++) {
      ret[j][i] = v[i][j];
    }
  }
  return ret;
}
void prt(const vector<vector<int>> &c) {
  for (int i = 0; i < c.size(); i++) {
    for (int j = 0; j < c[i].size(); j++) {
      cout << c[i][j] << '\t';
    }
    cout << '\n';
  }
}
const int seq[2][4] = {{1, 3, 0, 2}, {2, 0, 3, 1}};
vector<vector<int>> solve(vector<vector<int>> m) {
  vector<vector<int>> res;
  if (m.size() == 4) {
    res = m;
    for (int i = 0; i < m[0].size(); i++) {
      for (int j = 0; j < 4; j++) res[j][i] = m[seq[i & 1][j]][i];
    }
    return res;
  }
  for (int i = 0, L = ceil(m.size() / 2.0); i < L; i++) {
    res.push_back(m[i]);
    if (i + L < m.size()) res.push_back(m[i + L]);
  }
  if (m.size() == 2 || m.size() == 3) {
    int mtp = res[1][0];
    for (int i = 0; i + 1 < m[1].size(); i++) res[1][i] = res[1][i + 1];
    res[1].back() = mtp;
  }
  return res;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int n, m;
  cin >> n >> m;
  if (n == 1 && m == 1) {
    cout << "YES\n1\n";
    return 0;
  }
  if (n == 3 && m == 3) {
    cout << "YES\n2 7 6\n9 5 1\n4 3 8\n";
    return 0;
  }
  if (n <= 3 && m <= 3) {
    cout << "NO\n";
    return 0;
  }
  vector<vector<int>> c(n);
  for (int i = 0; i < n; i++) {
    for (int j = 1; j <= m; j++) {
      c[i].push_back(i * m + j);
    }
  }
  cout << "YES\n";
  if (n == 4) {
    prt(solve(c));
    return 0;
  } else if (m == 4) {
    c = transp(c);
    c = solve(c);
    prt(transp(c));
    return 0;
  }
  for (int i = 0; i < 2; i++) {
    c = solve(c);
    c = transp(c);
  }
  prt(c);
}
