#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
int n, k;
long long m;
int d[110][110 * 110];
int c[110][110];
int precomputed[110][110];
int fastPow(long long x, long long n) {
  long long ret = 1;
  while (n) {
    if (n & 1) ret = (ret * x) % MOD;
    x = (x * x) % MOD;
    n >>= 1;
  }
  return ret;
}
void init() {
  c[0][0] = 1;
  for (int i = 0; i < 110; i++) {
    c[i][0] = 1;
    for (int j = 1; j <= i; j++)
      c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % MOD;
  }
  for (int i = 0; i < n; i++)
    for (int k = 0; k <= n; k++) {
      long long pwr = m / n;
      if (m % n > i) pwr++;
      precomputed[i][k] = fastPow(c[n][k], pwr);
    }
}
int main() {
  cin >> n >> m >> k;
  init();
  d[n][0] = 1;
  for (int i = n - 1; i >= 0; i--) {
    int bound = min((n - i) * n, k);
    for (int j = 0; j <= bound; j++) {
      int lim = min(j, n);
      for (int nxt = 0; nxt <= lim; nxt++) {
        d[i][j] +=
            (static_cast<long long>(d[i + 1][j - nxt]) * precomputed[i][nxt]) %
            MOD;
        while (d[i][j] >= MOD) d[i][j] -= MOD;
      }
    }
  }
  cout << d[0][k] << endl;
  return 0;
}
