#include <bits/stdc++.h>
using namespace std;
const int mxn = 2005;
const int inf = 2E9 + 9;
int n, m, p;
int a[mxn];
int b[mxn];
inline long long calc(int i, int j) { return abs(a[i] - b[j]) + abs(b[j] - p); }
long long f[mxn][mxn];
signed main() {
  ios::sync_with_stdio(false);
  cin >> n >> m >> p;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  for (int i = 1; i <= m; ++i) cin >> b[i];
  sort(a + 1, a + n + 1);
  sort(b + 1, b + m + 1);
  memset(f, 0x3f, sizeof f);
  for (int i = 0; i <= m; ++i) f[0][i] = 0;
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j)
      f[i][j] = min(f[i][j - 1], max(f[i - 1][j - 1], calc(i, j)));
  cout << f[n][m] << endl;
}
