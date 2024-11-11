#include <bits/stdc++.h>
using namespace std;
long long int n1, n2, k1, k2;
const long long int md = 1e8;
long long int dp[3][13][101][101];
long long int rec(long long int index, long long int num, long long int cont,
                  long long int n1l, long long int n2l) {
  if (cont > 10) return 0;
  if (dp[num][cont][n1l][n2l] != -1) return dp[num][cont][n1l][n2l];
  if (index > n1 + n2) return 0;
  dp[num][cont][n1l][n2l] = 0;
  if (n1l == 0 && num == 1) {
    return dp[num][cont][n1l][n2l];
  }
  if (n2l == 0 && num == 2) {
    return dp[num][cont][n1l][n2l];
  }
  if ((num == 1 && cont > k1) || (num == 2 && cont > k2))
    return dp[num][cont][n1l][n2l];
  if (index == n1 + n2) {
    dp[num][cont][n1l][n2l] = (dp[num][cont][n1l][n2l] + (long long int)1) % md;
    return dp[num][cont][n1l][n2l];
  }
  if (num == (long long int)1) {
    dp[num][cont][n1l][n2l] =
        (dp[num][cont][n1l][n2l] + rec(index + 1, 2, 1, n1l - 1, n2l) +
         rec(index + 1, 1, cont + 1, n1l - 1, n2l)) %
        md;
  } else if (num == (long long int)2) {
    dp[num][cont][n1l][n2l] =
        (dp[num][cont][n1l][n2l] + rec(index + 1, 1, 1, n1l, n2l - 1) +
         rec(index + 1, 2, cont + 1, n1l, n2l - 1)) %
        md;
  }
  return dp[num][cont][n1l][n2l];
}
int main() {
  long long int i, j, k, x, y, t, m;
  cin >> n1 >> n2 >> k1 >> k2;
  for (j = 1; j <= 2; j++) {
    for (k = 1; k <= 11; k++) {
      for (x = 0; x <= n1; x++) {
        for (y = 0; y <= n2; y++) {
          dp[j][k][x][y] = -1;
        }
      }
    }
  }
  cout << rec(1, 1, 1, n1, n2) + rec(1, 2, 1, n1, n2) << endl;
}
