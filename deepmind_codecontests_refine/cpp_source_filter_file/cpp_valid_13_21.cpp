#include <bits/stdc++.h>
using LL = long long;
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  int t;
  cin >> t;
  ;
  while (t--) {
    int n, m, k;
    cin >> n >> m >> k;
    if (m == 1 && k > 0) {
      cout << "NO\n";
      continue;
    }
    int g[n][m];
    if (n & 1) {
      int x = m / 2;
      if ((m & 1) || k < x) {
        cout << "NO\n";
        continue;
      }
      k -= x;
      int p = 1;
      for (int j = 0; j < m; j += 2) {
        g[0][j] = g[0][j + 1] = p + 2;
        p ^= 1;
      }
      p = 0;
      for (int i = 1; i < n; i += 2) {
        for (int j = 0; j < m; ++j) {
          g[i][j] = g[i + 1][j] = p;
          p ^= 1;
        }
        p ^= 1;
      }
      for (int i = 1; i < n && k > 0; i += 2) {
        p = 0;
        for (int j = 0; j < m && k > 0; j += 2) {
          if (j + 1 >= m) continue;
          g[i][j] = g[i][j + 1] = p + 2;
          g[i + 1][j] = g[i + 1][j + 1] = (p ^ 1) + 2;
          k -= 2;
          p ^= 1;
        }
      }
      if (k > 0) {
        cout << "NO\n";
        continue;
      }
    } else {
      if (k & 1) {
        cout << "NO\n";
        continue;
      }
      int p = 0;
      for (int i = 0; i < n; i += 2) {
        p = (i / 2) & 1;
        for (int j = 0; j < m; ++j) {
          g[i][j] = g[i + 1][j] = p;
          p ^= 1;
        }
      }
      for (int i = 0; i < n && k > 0; i += 2) {
        p = 0;
        for (int j = 0; j < m && k > 0; j += 2) {
          if (j + 1 >= m) continue;
          g[i][j] = g[i][j + 1] = p + 2;
          g[i + 1][j] = g[i + 1][j + 1] = (p ^ 1) + 2;
          k -= 2;
          p ^= 1;
        }
      }
      if (k > 0) {
        cout << "NO\n";
        continue;
      }
    }
    cout << "YES\n";
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) cout << char(g[i][j] + 'a');
      cout << '\n';
    }
  }
}
