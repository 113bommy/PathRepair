#include <bits/stdc++.h>
using namespace std;
long long int nCr[1002][1002];
int main() {
  ios::sync_with_stdio(0);
  ;
  int n, m, k;
  cin >> n >> m >> k;
  nCr[0][0] = 1;
  for (int i = 1; i <= 1000; i++) {
    nCr[i][0] = 1;
    for (int j = 1; j <= 1000; j++) {
      nCr[i][j] = (nCr[i - 1][j] + nCr[i - 1][j - 1]) % 1000000007;
    }
  }
  cout << (((2 * k <= n - 1) ? nCr[n - 1][2 * k] : 0) *
           ((2 * k <= m - 1) ? nCr[m - 1][2 * k] : 0)) %
              1000000007;
}
