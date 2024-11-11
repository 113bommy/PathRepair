#include <bits/stdc++.h>
using namespace std;
int a[100][100];
int b[100][100];
int main() {
  int n, m, nr, k;
  cin >> n >> m >> nr >> k;
  for (int i = 1; i <= nr; i++) {
    int x, y;
    cin >> x >> y;
    a[x][y] = 1;
  }
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      b[i][j] = a[i][j] + b[i][j - 1] + b[i - 1][j] - b[i - 1][j - 1];
  long long sol = 0;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      for (int i2 = i; i2 <= n; i2++)
        for (int j2 = j; j2 <= m; j2++) {
          int v = b[i2][j2];
          v -= b[i - 1][j2];
          v -= b[i2][j - 1];
          v += b[i - 1][j - 1];
          if (v >= k) sol++;
        }
  cout << sol << '\n';
  return 0;
}
