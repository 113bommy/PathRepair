#include <bits/stdc++.h>
using namespace std;
const int N = 1e6, MOD = 1e9 + 7;
long long i, j;
int c[2002][2002], m, n, k;
int main() {
  cin >> n >> m >> k;
  for (i = 1; i <= 2000; i++) {
    c[i][0] = c[i][i] = 1;
    for (j = 1; j < i; j++) c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % MOD;
  }
  cout << (1ll * c[n - 1][2 * k] * c[m - 1][2 * k]) % MOD;
  return 0;
}
