#include <bits/stdc++.h>
using namespace std;
const int N = 1000 + 5;
vector<int> vl[N], v[N];
int n, m, k, g[N][N];
void done() {
  long double s = n * (m - 1) + (n - 1) * m, a = 0;
  char c;
  for (int i = 0; i < s; ++i) {
    cin >> c;
    if (c == 'E') a += 1;
  }
  if ((a / s) >= (3. / 4.)) {
    cout << "YES" << endl;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) cout << 1 << " ";
      cout << '\n';
    }
    cout << '\n';
  } else
    cout << "NO" << endl;
  exit(0);
}
int main() {
  ios::sync_with_stdio(false);
  cin >> n >> m >> k;
  char c;
  if (k == 1) done();
  cout << "YES" << endl;
  for (int t = 1; t < n; ++t) {
    for (int i = 2; i <= m; ++i) cin >> c, vl[i].push_back(c);
    for (int i = 1; i <= m; ++i) cin >> c, v[i].push_back(c);
  }
  for (int i = 2; i <= m; ++i) cin >> c, vl[i].push_back(c);
  if (n >= m) {
    for (int i = 1; i <= m; ++i) {
      g[i][n] = 1;
      for (int j = n - 1; j; --j) {
        if (v[i].back() == 'E')
          g[i][j] = g[i][j + 1];
        else
          g[i][j] = 3 - g[i][j + 1];
        v[i].pop_back();
      }
    }
    for (int i = 2; i <= m; ++i) {
      int a = 0;
      for (int j = 1; j <= n; ++j)
        if (vl[i][j - 1] == 'E')
          a += (g[i][j] == g[i - 1][j]);
        else
          a += (g[i][j] != g[i - 1][j]);
      if (a <= (n / 2))
        for (int j = 1; j <= n; ++j) g[i][j] = 3 - g[i][j];
    }
  } else {
    for (int i = 1; i <= n; ++i) {
      g[1][i] = 1;
      for (int j = 2; j <= m; ++j)
        if (vl[j][i - 1] == 'E')
          g[j][i] = g[j - 1][i];
        else
          g[j][i] = 3 - g[j - 1][i];
    }
    for (int i = 2; i <= n; ++i) {
      int a = 0;
      for (int j = 1; j <= m; ++j)
        if (v[j][i - 2] == 'E')
          a += (g[j][i] == g[j][i - 1]);
        else
          a += (g[j][i] != g[j][i - 1]);
      if (a <= (m / 2))
        for (int j = 1; j <= m; ++j) g[j][i] = 3 - g[j][i];
    }
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) cout << g[j][i] << " ";
    cout << '\n';
  }
  return 0;
}
