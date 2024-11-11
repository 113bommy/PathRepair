#include <bits/stdc++.h>
using namespace std;
long long ncr[75][75];
int main() {
  for (int i = 1; i <= 60; i++) {
    for (int j = 0; j <= i; j++) {
      if (j == 1)
        ncr[i][j] = i;
      else if (j == i || j == 0)
        ncr[i][j] = 1;
      else
        ncr[i][j] = ncr[i - 1][j] + ncr[i - 1][j - 1];
    }
  }
  long long n, m, t, ans = 0;
  cin >> n >> m >> t;
  for (long long x = 4; x <= n; x++) {
    long long y = t - x;
    if (x >= 4 && y >= 1) {
      ans += (ncr[n][x] * ncr[m][y]);
    }
  }
  cout << ans << endl;
  return 0;
}
