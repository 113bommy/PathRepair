#include <bits/stdc++.h>
using namespace std;
int c[1010][1010];
long long f[110][1010];
int x[110], y[110];
int mod = 100000007;
int m, sum[110];
long long res;
int main() {
  int i, j, k;
  memset(f, 0, sizeof(f));
  for (i = 0; i < 1010; i++) {
    for (j = 0; j <= i; j++) {
      if (i == 0 || i == j) {
        c[i][j] = 1;
      } else {
        c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
        c[i][j] %= mod;
      }
    }
  }
  while (scanf("%d", &m) != EOF) {
    sum[0] = 0;
    for (i = 1; i <= m; i++) {
      scanf("%d", &x[i]);
      sum[i] = sum[i - 1] + x[i];
    }
    for (i = 1; i <= m; i++) {
      scanf("%d", &y[i]);
    }
    res = 1;
    for (i = 1; i <= m; i++) {
      res = res * c[sum[m] - sum[i - 1]][x[i]];
      res %= mod;
    }
    memset(f, 0, sizeof(f));
    f[0][0] = 1;
    for (i = 0; i < m; i++) {
      for (j = 0; j <= sum[i]; j++) {
        if (f[i][j] == 0) continue;
        for (k = 0; k <= sum[i + 1] - j && k <= y[i + 1]; k++) {
          f[i + 1][j + k] += (f[i][j] * c[sum[i + 1] - j][k]) % mod;
          f[i + 1][j + k] %= mod;
        }
      }
    }
    cout << ((f[m][sum[m]] * res) % mod) << endl;
  }
  return 0;
}
