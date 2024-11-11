#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 23;
long long f[maxn][3][2];
int a[maxn], n;
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  if (n == 1) {
    return 0 * printf("%d", a[1]);
  }
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j < 3; j++) f[i][j][0] = f[i][j][1] = -1e18;
  }
  f[0][0][0] = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 3; j++) {
      for (int k = 0; k < 2; k++) {
        f[i + 1][(j + 1) % 3][k] =
            max(f[i + 1][(j + 1) % 3][k], f[i][j][k] - a[i + 1]);
        f[i + 1][j][k] = max(f[i + 1][j][k], f[i][j][k] + a[i + 1]);
        f[i + 2][j][k | 1] =
            max(f[i + 2][j][k | 1], f[i][j][k] + a[i + 1] + a[i + 2]);
        f[i + 2][(j + 2) % 3][k | 1] =
            max(f[i + 2][(j + 2) % 3][k | 1], f[i][j][k] - a[i + 1] - a[i + 2]);
      }
    }
  }
  cout << f[n][(1 - n % 3 + 3) % 3][1];
}
