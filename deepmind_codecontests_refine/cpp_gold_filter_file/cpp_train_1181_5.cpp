#include <bits/stdc++.h>
using namespace std;
const int MAXD = 11;
const int MAXN = 101;
const int MOD = 1000000007;
int n;
int a[MAXD];
long long c[MAXN][MAXN];
long long f[MAXD][MAXN];
inline void preProcess() {
  for (int i = 0; i <= n; ++i) {
    c[i][0] = c[i][i] = 1;
    for (int j = 1; j < n; ++j) c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % MOD;
  }
}
int main() {
  scanf("%d\n", &n);
  for (int i = 0; i <= 9; ++i) scanf("%d", &a[i]);
  preProcess();
  f[10][0] = 1;
  for (int i = 9; i >= 0; --i)
    for (int j = 0; j <= n; ++j)
      for (int k = 0; k <= j - a[i]; ++k) {
        if (i > 0)
          f[i][j] = (f[i][j] + f[i + 1][k] * c[j][j - k]) % MOD;
        else if (j > 0 && k > 0)
          f[i][j] = (f[i][j] + f[i + 1][k] * c[j - 1][j - k]) % MOD;
      }
  long long res = 0;
  for (int i = 1; i <= n; ++i) res = (res + f[0][i]) % MOD;
  printf("%I64d\n", res);
  fclose(stdin);
  fclose(stdout);
  return 0;
}
