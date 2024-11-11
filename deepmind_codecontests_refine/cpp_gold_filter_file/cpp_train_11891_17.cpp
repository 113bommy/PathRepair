#include <bits/stdc++.h>
using namespace std;
const int N = 2048, MOD = 1e9 + 7;
int comb[N][N];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  for (int i = 0; i < N; ++i) {
    comb[i][0] = comb[i][i] = 1;
    for (int j = 1; j < i; ++j) {
      comb[i][j] = (comb[i - 1][j - 1] + comb[i - 1][j]) % MOD;
    }
  }
  int n, m, k;
  cin >> n >> m >> k;
  cout << 1LL * comb[n - 1][2 * k] * comb[m - 1][2 * k] % MOD << endl;
  return 0;
}
