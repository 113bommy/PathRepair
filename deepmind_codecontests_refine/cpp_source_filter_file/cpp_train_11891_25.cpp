#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e3 + 5;
long long C[MAXN][MAXN];
int main() {
  long long m, n, i, j, k;
  C[0][0] = 1;
  for (i = 0; i < MAXN; i++) {
    C[i][0] = C[i][i] = 1;
    for (j = 1; j < i; j++) {
      C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % 1000000007;
    }
  }
  cin >> m >> n >> k;
  cout << (C[m - 1][k * 2] * C[n - 1][k * 2] % 1000000007) << endl;
}
