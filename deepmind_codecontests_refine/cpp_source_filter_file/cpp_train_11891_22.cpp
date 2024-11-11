#include <bits/stdc++.h>
using namespace std;
long long int mod = 1e9 + 7, nCr[2010][2010];
int main() {
  for (int i = 0; i <= 2000; i++) {
    nCr[i][0] = 1;
    for (int j = 1; j <= i; j++) {
      nCr[i][j] = (nCr[i - 1][j - 1] + nCr[i - 1][j]) % mod;
    }
  }
  int n, m, k;
  cin >> n >> m >> k;
  cout << (nCr[n - 1][2 * k] * nCr[m - 1][2 * k]) << endl;
  return 0;
}
