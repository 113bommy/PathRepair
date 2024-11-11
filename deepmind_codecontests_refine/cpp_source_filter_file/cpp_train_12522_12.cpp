#include <bits/stdc++.h>
using namespace std;
const int N = 5005;
int f[N][N];
string s, t;
int res, i, j, n, m;
int main() {
  cin >> n >> m;
  cin >> s;
  cin >> t;
  s = ' ' + s;
  t = ' ' + t;
  res = 0;
  for (i = 1; i <= n; i++)
    for (j = 1; j <= m; j++) {
      f[i][j] = max(f[i - 1][j], f[i][j - 1]) - 1;
      if (s[i] == t[j]) f[i][j] = max(f[i][j], f[i - 1][j - 1] + 2);
      res = max(res, f[i][j]);
    }
  cout << res;
  return 0;
}
