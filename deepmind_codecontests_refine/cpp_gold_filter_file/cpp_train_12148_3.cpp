#include <bits/stdc++.h>
using namespace std;
bool sortbysec(const pair<int, int> &a, const pair<int, int> &b) {
  return (a.second < b.second);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m, i, j, c;
  string s, f = "YES";
  vector<string> v;
  cin >> n >> m;
  for (i = 0; i < n; i++) {
    cin >> s;
    v.push_back(s);
  }
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      if (v[i][j] == '*') continue;
      c = 0;
      if (i - 1 >= 0 && v[i - 1][j] == '*') c++;
      if (i - 1 >= 0 && j - 1 >= 0 && v[i - 1][j - 1] == '*') c++;
      if (i - 1 >= 0 && j + 1 < m && v[i - 1][j + 1] == '*') c++;
      if (j - 1 >= 0 && v[i][j - 1] == '*') c++;
      if (j + 1 < m && v[i][j + 1] == '*') c++;
      if (i + 1 < n && v[i + 1][j] == '*') c++;
      if (i + 1 < n && j - 1 >= 0 && v[i + 1][j - 1] == '*') c++;
      if (i + 1 < n && j + 1 < m && v[i + 1][j + 1] == '*') c++;
      if (c > 0 && c != v[i][j] - '0') f = "NO";
      if (!c && v[i][j] != '.') f = "NO";
    }
  }
  cout << f;
  return 0;
}
