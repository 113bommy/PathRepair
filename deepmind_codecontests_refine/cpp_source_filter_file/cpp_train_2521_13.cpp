#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
int n, m, k;
int C[1005 * 2][1005 * 2];
void Init() {
  C[0][0] = 1;
  for (int i = 1; i <= 2 * 1005 - 5; i++) {
    C[i][0] = 1;
    for (int j = 1; j <= i; j++) {
      C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD;
    }
  }
}
int main() {
  Init();
  cin >> n >> m >> k;
  cout << 1LL * (C[n - 1][2 * k] * C[m - 1][2 * k]) % MOD << endl;
  return 0;
}
