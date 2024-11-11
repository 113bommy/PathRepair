#include <bits/stdc++.h>
using namespace std;
int n, m, k, dn[2010][1010], dm[2010][1010];
const int M = 1000000007;
int main() {
  scanf("%d %d %d", &n, &m, &k);
  for (int j = 1; j < n; j++) dn[1][j] = 1 + dn[1][j - 1];
  for (int i = 2; i <= 2 * k; i++)
    for (int j = 1; j < n; j++)
      dn[i][j] = (dn[i - 1][j - 1] + dn[i][j - 1]) % M;
  for (int j = 1; j < m; j++) dm[1][j] = 1 + dm[1][j - 1];
  for (int i = 2; i <= 2 * k; i++)
    for (int j = 1; j < m; j++)
      dm[i][j] = (dm[i - 1][j - 1] + dm[i][j - 1]) % M;
  printf("%d\n", (int)(((long long)dn[2 * k][n - 1]) *
                       ((long long)dm[2 * k][m - 1]) % M));
  return 0;
}
