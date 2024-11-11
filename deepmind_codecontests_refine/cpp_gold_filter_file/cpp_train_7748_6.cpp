#include <bits/stdc++.h>
using namespace std;
const long long A = 100000000000000LL, N = 2001, M = 1000000007;
long long k, i, j, n, m, d[N][N], o;
int main() {
  cin >> n >> m;
  for (i = 1; i <= n; i++) d[0][i] = 1;
  for (i = 0; i < m - 1; i++)
    for (j = 1; j <= n; j++) {
      k = 0;
      while (k += j) {
        if (k > n) break;
        d[i + 1][k] += d[i][j];
        d[i + 1][k] %= M;
      }
    }
  for (i = 1; i <= n; i++) o += d[m - 1][i];
  cout << o % M;
}
