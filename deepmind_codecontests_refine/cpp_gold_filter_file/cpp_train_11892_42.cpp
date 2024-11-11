#include <bits/stdc++.h>
using namespace std;
const int MOD(1000000007);
const int INF((1 << 30) - 1);
const int MAXN(2005);
long long C[MAXN][MAXN];
int main() {
  int n, m, k;
  scanf("%d%d%d", &n, &m, &k);
  C[0][0] = C[1][0] = C[1][1] = 1;
  for (int i = 2; i <= max(n, m); i++)
    for (int j = 0; j <= i; j++) {
      if (j == 0 || j == i)
        C[i][j] = 1;
      else
        C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD;
    }
  cout << C[n - 1][2 * k] * C[m - 1][2 * k] % MOD;
}
