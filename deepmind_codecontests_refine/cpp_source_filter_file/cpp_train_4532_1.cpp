#include <bits/stdc++.h>
using namespace std;
int main() {
  long r, c, n, k;
  cin >> r >> c >> n >> k;
  long f[100][100];
  for (long i = 0; i <= r; ++i)
    for (long j = 0; j <= c; ++j) f[i][j] = 0;
  long a, b;
  for (long i = 0; i < n; ++i) {
    cin >> a >> b;
    f[a][b] = 1;
  }
  for (long i = 2; i <= r; ++i)
    for (long j = 1; j <= c; ++j)
      f[i][j] = f[i - 1][j] + f[i][j - 1] - f[i - 1][j - 1] + f[i][j];
  long ans = 0, t;
  for (long i = 1; i <= r; ++i)
    for (long i2 = i; i2 <= r; ++i2)
      for (long j = 1; j <= c; ++j)
        for (long j2 = j; j2 <= c; ++j2) {
          t = f[i2][j2] - f[i - 1][j2] - f[i2][j - 1] + f[i - 1][j - 1];
          if (t >= k) ++ans;
        }
  cout << ans << endl;
  return 0;
}
