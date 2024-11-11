#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
long long i, j, n, m, k, comb[2005][2005];
int main() {
  ios_base::sync_with_stdio(0);
  comb[1][0] = comb[1][1] = 1;
  for (i = 2; i <= 2000; ++i)
    for (j = comb[i][0] = 1; j <= i; ++j)
      comb[i][j] = (comb[i - 1][j] + comb[i - 1][j - 1]) % MOD;
  cin >> n >> m >> k;
  cout << (comb[n - 1][2 * k] * comb[m - 1][2 * k]) % MOD << '\n';
  return 0;
}
