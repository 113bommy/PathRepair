#include <bits/stdc++.h>
using namespace std;
unsigned long long d[30 + 2][30 + 2], ans = 0;
int main() {
  int n, m, t;
  cin >> n >> m >> t;
  for (int i = 0; i < 32; i++)
    for (int j = 0; j < 32; j++)
      if (j == 0)
        d[j][i] = 1;
      else if (i < j)
        d[j][i] = 0;
      else if (i == j)
        d[j][i] = 1;
      else
        d[j][i] = d[j - 1][i - 1] + d[j][i - 1];
  for (int i = 4; i <= n; i++)
    if (((t - i) >= 1) && ((t - i) <= m)) ans += d[i][n] * d[t - i][m];
  cout << ans << endl;
  return 0;
}
