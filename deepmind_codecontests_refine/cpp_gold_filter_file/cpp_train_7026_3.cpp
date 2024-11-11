#include <bits/stdc++.h>
using namespace std;
bool a[4001][4001] = {0};
int cc[4001] = {0};
int main() {
  int n, m, res = 100000000;
  cin >> n >> m;
  for (int q = 1; q <= m; q++) {
    int i, j;
    cin >> i >> j;
    a[i][j] = 1;
    a[j][i] = 1;
    cc[i]++;
    cc[j]++;
  }
  for (int p = 1; p <= n; ++p)
    for (int b = p + 1; b <= n; ++b)
      if (a[p][b])
        for (int c = b + 1; c <= n; ++c)
          if (a[p][c] && a[b][c]) res = min(cc[p] + cc[b] + cc[c], res);
  if (res == 100000000)
    cout << -1;
  else
    cout << res - 6;
  return 0;
}
