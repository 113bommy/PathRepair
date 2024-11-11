#include <bits/stdc++.h>
using namespace std;
long long int n, m, k;
long long int combi[105][105], p[3][105], ans[105][105];
long long int power(long long int a, long long int x) {
  long long int res = 1;
  for (; x; x >>= 1, (a *= a) %= 1000000007)
    if (x & 1) (res *= a) %= 1000000007;
  return res;
}
int main() {
  long long int i, j, l, a, b, c;
  cin >> n >> m >> k;
  for (i = 0; i <= n; ++i) {
    for (j = 0; j <= i; ++j) {
      if (j == 0) {
        combi[i][j] = 1;
      } else {
        combi[i][j] = (combi[i - 1][j - 1] + combi[i - 1][j]) % 1000000007;
      }
    }
  }
  a = m % n;
  for (i = 0; i <= n; ++i) {
    p[0][i] = power(combi[n][i], m / n);
    p[1][i] = p[0][i] * combi[n][i] % 1000000007;
  }
  ans[0][0] = 1;
  for (i = 1; i <= n; ++i) {
    for (j = 0; j <= k; ++j) {
      for (l = 0; l <= j && l <= n; l++) {
        if (i <= a) {
          ans[i][j] = (ans[i][j] + (ans[i - 1][j - l] * p[1][l]) % 1000000007) %
                      1000000007;
        } else {
          ans[i][j] = (ans[i][j] + (ans[i - 1][j - l] * p[0][l]) % 1000000007) %
                      1000000007;
        }
      }
    }
  }
  cout << ans[n][k];
  return 0;
}
