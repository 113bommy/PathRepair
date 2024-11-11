#include <bits/stdc++.h>
using namespace std;
void reversed(char &c1) { c1 = (c1 == '0') ? '1' : '0'; }
void solve() {
  int n, m;
  cin >> n >> m;
  string s[n];
  for (int i = 0; i < n; i++) cin >> s[i];
  int count = 0;
  vector<vector<int>> v;
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < m - 1; j++) {
      if (s[i][j] == '0') {
        vector<int> v1{i, j, i + 1, j, i + 1, j + 1};
        v.push_back(v1);
        reversed(s[i + 1][j]);
        reversed(s[i + 1][j + 1]);
        s[i][j] = '1';
        count++;
      }
    }
    if (s[i][m - 1] == '0') {
      vector<int> v1{i, m - 1, i + 1, m - 1, i + 1, m - 2};
      v.push_back(v1);
      count++;
      reversed(s[i + 1][m - 1]);
      reversed(s[i + 1][m - 2]);
    }
  }
  for (int j = 0; j < m - 1; j++) {
    if (s[n - 1][j] == '0') {
      vector<int> v1{n - 1, j, n - 2, j, n - 2, j + 1};
      v.push_back(v1);
      v1[1] = j + 1;
      v.push_back(v1);
      count += 2;
      reversed(s[n - 1][j + 1]);
    }
  }
  if (s[n - 1][m - 1] == '0') {
    count += 3;
    vector<int> v1{n - 1, m - 1, n - 1, m - 2, n - 2, m - 1};
    v.push_back(v1);
    v1[2] = n - 2;
    v.push_back(v1);
    v1[4] = n - 1;
    v1[5] = m - 2;
    v.push_back(v1);
  }
  cout << count << "\n";
  for (int i = 0; i < count; i++) {
    for (int j : v[i]) cout << j + 1 << " ";
    cout << "\n";
  }
}
int main() {
  int t;
  cin >> t;
  while (t--) solve();
}
