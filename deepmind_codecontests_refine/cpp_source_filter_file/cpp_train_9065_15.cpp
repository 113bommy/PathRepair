#include <bits/stdc++.h>
using namespace std;
int n, m;
int up[1010][1010], dw[1010][1010], rgt[1010][1010], lft[1010][1010];
vector<string> s;
int biorow[1010][1010], biocol[1010][1010];
vector<vector<int> > ans;
bool bio[1010][1010];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> m;
  s.resize(n, "");
  for (int i = 0; i < n; ++i) {
    cin >> s[i];
  }
  for (int i = 0; i < n; ++i) {
    lft[i][0] = 0;
    for (int j = 1; j < m; ++j) {
      lft[i][j] = lft[i][j - 1] + (s[i][j - 1] == '*');
      if (s[i][j] != '*') {
        lft[i][j] = 0;
      }
    }
    rgt[i][m - 1] = 0;
    for (int j = m - 2; j >= 0; --j) {
      rgt[i][j] = rgt[i][j + 1] + (s[i][j + 1] == '*');
      if (s[i][j] != '*') {
        rgt[i][j] = 0;
      }
    }
  }
  for (int j = 0; j < m; ++j) {
    up[0][j] = 0;
    for (int i = 1; i < n; ++i) {
      up[i][j] = up[i - 1][j] + (s[i - 1][j] == '*');
      if (s[i][j] != '*') {
        up[i][j] = 0;
      }
    }
    dw[n - 1][j] = 0;
    for (int i = n - 2; i >= 0; --i) {
      dw[i][j] = dw[i + 1][j] + (s[i + 1][j] == '*');
      if (s[i][j] != '*') {
        dw[i][j] = 0;
      }
    }
  }
  0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      int sz = min(lft[i][j], rgt[i][j]);
      sz = min(sz, dw[i][j]);
      sz = min(sz, rgt[i][j]);
      if (sz) {
        biorow[i][j - sz]++;
        biorow[i][j + sz + 1]--;
        biocol[j][i - sz]++;
        biocol[j][i + sz + 1]--;
      } else {
        continue;
      }
      ans.push_back({i + 1, j + 1, sz});
    }
  }
  for (int i = 0; i < n; ++i) {
    int sum = 0;
    for (int j = 0; j < m; ++j) {
      sum += biorow[i][j];
      if (sum) {
        bio[i][j] = 1;
      }
    }
  }
  for (int j = 0; j < m; ++j) {
    int sum = 0;
    for (int i = 0; i < n; ++i) {
      sum += biocol[j][i];
      if (sum) {
        bio[i][j] = 1;
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (s[i][j] == '*' and !bio[i][j]) {
        cout << -1;
        return 0;
      }
    }
  }
  cout << ans.size() << "\n";
  for (auto i : ans) {
    cout << i[0] << " " << i[1] << " " << i[2] << "\n";
  }
}
