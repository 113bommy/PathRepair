#include <bits/stdc++.h>
using namespace std;
const int N = 1010;
const int MOD = (int)1e9 + 7;
const double PI = 2 * acos(0);
int n, m, k;
int c[N][N];
int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> m >> k;
  for (int i = (0), _b = (max(n, m)); i <= _b; ++i) c[i][0] = 1;
  for (int i = (1), _b = (max(n, m)); i <= _b; ++i)
    for (int j = (1), _b = (i); j <= _b; ++j)
      c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % MOD;
  cout << (1ll * c[n - 1][2 * k] * c[m - 1][2 * k]) % MOD << "\n";
  return 0;
}
