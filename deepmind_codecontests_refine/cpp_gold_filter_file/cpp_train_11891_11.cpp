#include <bits/stdc++.h>
using namespace std;
const int MOD = pow(10, 9) + 7;
const int MAXN = 1010;
int main() {
  int n, m, k;
  cin >> n >> m >> k;
  if (n < 3 || m < 3) {
    cout << 0 << endl;
    return 0;
  }
  if (2 * k > n - 1 || 2 * k > m - 1) {
    cout << 0 << endl;
    return 0;
  }
  int binom[MAXN][MAXN] = {0};
  binom[0][0] = 1;
  for (int i = 1; i < MAXN; i++) {
    for (int j = 0; j <= i; j++) {
      if (j == 0) {
        binom[i][j] = 1;
        continue;
      }
      binom[i][j] = (binom[i - 1][j - 1] + binom[i - 1][j]) % MOD;
    }
  }
  cout << ((long long)binom[n - 1][2 * k] * binom[m - 1][2 * k]) % MOD << endl;
}
