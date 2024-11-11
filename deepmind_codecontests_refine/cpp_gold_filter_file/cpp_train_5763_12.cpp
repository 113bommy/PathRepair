#include <bits/stdc++.h>
using namespace std;
long long n, m, ans = 2000000000000000000, px, py;
long long c[1005][1005], f[1005][1005], s[1005][1005], h[1005][1005];
long long D(long long x) { return x * x; }
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      cin >> c[i][j];
      f[0][0] += (D(2 + (i - 1) * 4) + D(2 + (j - 1) * 4)) * c[i][j];
    }
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      s[i][j] = s[i - 1][j] + c[i][j];
      h[i][j] = h[i][j - 1] + c[i][j];
    }
  for (int i = 1; i <= m; i++) {
    f[0][i] = f[0][i - 1];
    for (int j = 1; j <= m; j++) {
      if (i - 1 - j >= 0)
        f[0][i] -= s[n][j] * D((i - 1 - j) * 4 + 2);
      else
        f[0][i] -= s[n][j] * D((j - i) * 4 + 2);
      if (i - j >= 0)
        f[0][i] += s[n][j] * D((i - j) * 4 + 2);
      else
        f[0][i] += s[n][j] * D((j - i - 1) * 4 + 2);
    }
  }
  for (int i = 1; i <= n; i++) {
    f[i][0] = f[i - 1][0];
    for (int j = 1; j <= n; j++) {
      if (i - 1 - j >= 0)
        f[i][0] -= h[j][m] * D((i - 1 - j) * 4 + 2);
      else
        f[i][0] -= h[j][m] * D((j - i) * 4 + 2);
      if (i - j >= 0)
        f[i][0] += h[j][m] * D((i - j) * 4 + 2);
      else
        f[i][0] += h[j][m] * D((j - i - 1) * 4 + 2);
    }
  }
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      f[i][j] = f[i][j - 1] + f[i - 1][j] - f[i - 1][j - 1];
  for (int i = 0; i <= n; i++)
    for (int j = 0; j <= m; j++)
      if (f[i][j] < ans) {
        ans = f[i][j];
        px = i;
        py = j;
      }
  cout << ans << endl << px << " " << py;
  return 0;
}
