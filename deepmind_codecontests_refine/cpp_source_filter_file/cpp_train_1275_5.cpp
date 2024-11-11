#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    vector<vector<char>> g(n + 2, vector<char>(m + 2, '#'));
    bool has_g = false;
    bool has_b = false;
    for (int i = 1; i <= n; i++) {
      string s;
      cin >> s;
      for (int j = 0; j < s.size(); j++) {
        g[i][j + 1] = s[j];
        if (s[j] == 'G') has_g = true;
        if (s[j] == 'B') has_b = true;
      }
    }
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        if (g[i][j] == 'B' and g[i + 1][j] == '.') g[i + 1][j] = '#';
        if (g[i][j] == 'B' and g[i - 1][j] == '.') g[i - 1][j] = '#';
        if (g[i][j] == 'B' and g[i][j + 1] == '.') g[i][j + 1] = '#';
        if (g[i][j] == 'B' and g[i][j - 1] == '.') g[i][j - 1] = '#';
      }
    }
    queue<pair<int, int>> q;
    vector<vector<int>> w(n + 1, vector<int>(m + 1, 0));
    if (g[n][m] != '#') {
      q.push({n, m});
      w[n][m] = 1;
    }
    while (!q.empty()) {
      pair<int, int> coord = q.front();
      int i = coord.first;
      int j = coord.second;
      q.pop();
      if (i > 1 and g[i - 1][j] != '#' and !w[i - 1][j]) {
        q.push({i - 1, j});
        w[i - 1][j] = 1;
      }
      if (i < n and g[i + 1][j] != '#' and !w[i + 1][j]) {
        q.push({i + 1, j});
        w[i + 1][j] = 1;
      }
      if (j > 1 and g[i][j - 1] != '#' and !w[i][j - 1]) {
        q.push({i, j - 1});
        w[i][j - 1] = 1;
      }
      if (j < m and g[i][j + 1] != '#' and !w[i][j + 1]) {
        q.push({i, j + 1});
        w[i][j + 1] = 1;
      }
    }
    bool ans = true;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        if (w[i][j] and g[i][j] == 'B') ans = false;
        if (!w[i][j] and g[i][j] == 'G') ans = false;
      }
    }
    if (ans)
      cout << "Yes" << endl;
    else
      cout << "No" << endl;
  }
}
