#include <bits/stdc++.h>
using namespace std;
int a[1005][1005], b[1005][1005], c[1005][1005], d[1005][1005], e[1005][1005],
    f[1005][1005], g[1005][1005], h[1005][1005];
int main() {
  int n, m;
  cin >> n >> m;
  string s[n];
  bool visit[n + 1][m + 1];
  for (int i = 0; i <= n; ++i) {
    if (i != n) cin >> s[i];
    for (int j = 0; j <= m; j++) {
      if (i == 0 || j == 0)
        a[i][j] = 0, b[i][j] = 0, c[i][j] = 0, d[i][j] = 0;
      else if (s[i - 1][j - 1] == '*')
        a[i][j] = a[i][j - 1] + 1, b[i][j] = b[i - 1][j] + 1,
        visit[i][j] = true;
      else
        a[i][j] = 0, b[i][j] = 0, visit[i][j] = false;
      e[i][j] = 0;
      f[i][j] = 0;
      f[i][j] = 0;
      h[i][j] = 0;
    }
  }
  vector<pair<int, pair<int, int> > > vec;
  for (int i = n + 1; i > 0; --i) {
    for (int j = m + 1; j > 0; j--) {
      if (i == n + 1 || j == m + 1)
        a[i][j] = 0, b[i][j] = 0, c[i][j] = 0, d[i][j] = 0;
      else {
        if (s[i - 1][j - 1] == '*') {
          d[i][j] = d[i][j + 1] + 1;
          c[i][j] = c[i + 1][j] + 1;
        } else {
          d[i][j] = 0;
          c[i][j] = 0;
        }
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      int p = min(a[i][j], min(b[i][j], min(c[i][j], d[i][j])));
      if (p > 1) {
        e[i + 1 - p][j] += p - 1;
        f[i + p - 1][j] -= p - 1;
        g[i][j + 1 - p] += p - 1;
        h[i][j + p - 1]--;
        vec.push_back(make_pair(i, make_pair(j, p)));
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    int x = 0;
    for (int j = 1; j <= m; j++) {
      x += g[i][j];
      if (x > 0) visit[i][j] = false;
      x += h[i][j];
    }
  }
  for (int i = 1; i <= m; i++) {
    int x = 0;
    for (int j = 1; j <= n; j++) {
      x += e[j][i];
      if (x > 0) visit[j][i] = false;
      x += f[j][i];
    }
  }
  bool is = false;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (visit[i][j]) is = true;
    }
  }
  if (is)
    cout << "-1\n";
  else {
    int l = vec.size();
    cout << l << endl;
    for (int j = 0; j < l; j++) {
      cout << vec[j].first << " " << vec[j].second.first << " "
           << vec[j].second.second - 1 << endl;
    }
  }
  return 0;
}
