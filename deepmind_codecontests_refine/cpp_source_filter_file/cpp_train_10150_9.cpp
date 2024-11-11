#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int n, m;
vector<string> a;
vector<vector<int> > f, g;
void modadd(int &x, int y) { (x += y) >= mod ? x -= y : 0; }
int main() {
  cin >> n >> m;
  a.resize(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  if (a[0][0] != a[n - 1][m - 1]) {
    puts("0");
    return 0;
  }
  f.resize(n, vector<int>(n, 0));
  f[0][n - 1] = 1;
  for (int i = 1; 2 * i <= n + m - 2; ++i) {
    g = f;
    f.assign(n, vector<int>(n, 0));
    for (int j = 0; j < n; ++j) {
      int x = i - j;
      if (x < 0 || x >= m) continue;
      for (int k = 0; k < n; ++k) {
        int y = n + m - 2 - i - k;
        if (y < 0 || y >= m) continue;
        if (a[j][x] != a[k][y]) continue;
        if (j && k < n - 1) modadd(f[j][k], g[j - 1][k + 1]);
        if (j && y < m - 1) modadd(f[j][k], g[j - 1][k]);
        if (x && k < n - 1) modadd(f[j][k], g[j][k + 1]);
        if (x && y < m - 1) modadd(f[j][k], g[j][k]);
      }
    }
  }
  int ans = 0;
  if ((n + m) & 1) {
    for (int i = 1; i < n; ++i) {
      modadd(ans, f[i][i]);
      modadd(ans, f[i - 1][i]);
    }
    modadd(ans, f[0][0]);
  } else
    for (int i = 0; i < n; ++i) modadd(ans, f[i][i]);
  cout << ans;
  return 0;
}
