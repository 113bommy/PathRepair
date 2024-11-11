#include <bits/stdc++.h>
using namespace std;
int n, a[2] = {+1, -1}, f[120][58][2];
char c[120];
int i, j, t, k;
string ss;
int main() {
  std::ios::sync_with_stdio(false);
  cin >> ss >> n;
  for (i = 1; i <= ss.size(); i++) c[i] = ss[i - 1];
  memset(f, -120960, 12000);
  f[0][0][0] = f[0][0][1] = 0;
  for (i = 1; i <= ss.size(); i++)
    for (j = 0; j <= n; j++)
      for (k = 0; k < 2; k++)
        for (t = 0; t <= j; t++)
          if ((t % 2 == 0) != (c[i] == 'F'))
            f[i][j][k] = max(f[i][j][k], f[i - 1][j - t][!k]);
          else
            f[i][j][k] = max(f[i][j][k], f[i - 1][j - t][k] + a[k]);
  cout << max(f[ss.size()][n][0], f[ss.size()][n][1]) << endl;
}
