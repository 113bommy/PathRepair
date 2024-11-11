#include <bits/stdc++.h>
using namespace std;
const int maxn = 33;
const int mod = (int)1e9 + 7;
int n, k;
int a[maxn];
double res, f[2][maxn][maxn];
int pre(int pos, int x, int y) {
  if (x <= pos && pos <= y)
    return (x + y - pos);
  else
    return pos;
}
int main() {
  cin >> n >> k;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (i > j)
        f[0][i][j] = 1.0;
      else
        f[0][i][j] = 0.0;
    }
  }
  for (int step = 1; step <= k; step++) {
    memset(f[1], 0, sizeof f[1]);
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        for (int x = 1; x <= n; x++) {
          for (int y = x; y <= n; y++) {
            f[1][i][j] += f[0][pre(i, x, y)][pre(j, x, y)];
          }
        }
        f[1][i][j] /= (n * (n + 1) / 2);
      }
    }
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        f[0][i][j] = f[1][i][j];
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      if (a[i] < a[j])
        res += f[1][i][j];
      else
        res += 1 - f[1][i][j];
    }
  }
  cout << fixed << setprecision(12) << res;
}
