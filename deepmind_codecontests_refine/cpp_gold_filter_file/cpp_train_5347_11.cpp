#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
int n, k;
long long m;
int c[110][110], g[110], f[110][10011];
int pwd(int a, long long n) {
  int ret = 1;
  while (n)
    if (n & 1LL)
      n--, ret = (long long)ret * a % MOD;
    else
      n >>= 1, a = (long long)a * a % MOD;
  return ret;
}
int main() {
  cin >> n >> m >> k;
  f[0][0] = 1;
  for (int i = (0); i <= (n); i++) c[i][0] = 1;
  for (int i = (1); i <= (n); i++)
    for (int j = (1); j <= (i); j++)
      c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % MOD;
  for (int i = (1); i <= (n); i++) {
    for (int j = (0); j <= (n); j++) g[j] = pwd(c[n][j], (m - i) / n + 1);
    for (int j = (0); j <= (min(k, i * n)); j++) {
      for (int l = (0); l <= (n); l++)
        if (j >= l)
          f[i][j] = (f[i][j] + (long long)f[i - 1][j - l] * g[l]) % MOD;
    }
  }
  cout << f[n][k] << endl;
  return 0;
}
