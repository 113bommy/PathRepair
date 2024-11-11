#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const long long mod = 1e9 + 7;
const int N = 85;
int a[N], pre[N];
int f[N][N][N * N];
int main() {
  int n;
  scanf("%d", &n);
  int m = 1;
  for (int i = 1; i <= n; i++) {
    int x;
    scanf("%d", &x);
    if (x)
      m++;
    else
      a[m]++;
  }
  int g = n - (m - 1), w = n * (n - 1) / 2;
  for (int i = 1; i <= m; i++) pre[i] = pre[i - 1] + a[i];
  memset(f, 0x3f, sizeof f);
  f[0][0][0] = 0;
  for (int i = 1; i <= m; i++) {
    for (int j = 0; j <= g; j++) {
      for (int k = 0; k <= w; k++) {
        int v = k - abs(pre[i] - j);
        if (k >= 1) f[i][j][k] = f[i][j][k - 1];
        if (v < 0) continue;
        for (int u = 0; u <= j; u++) {
          f[i][j][k] = min(f[i][j][k], f[i - 1][u][v] + (j - u) * (j - u));
        }
      }
    }
  }
  for (int i = 0; i <= n * (n - 1) / 2; i++) {
    int ans = (pre[m] * pre[m] - f[m][g][i]) / 2;
    printf("%d%c", ans, " \n"[i == n * (n - 1) / 2]);
  }
  return 0;
}
