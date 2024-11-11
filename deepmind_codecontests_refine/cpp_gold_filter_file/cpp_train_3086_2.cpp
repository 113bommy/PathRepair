#include <bits/stdc++.h>
using namespace std;
unsigned n, d, P, op;
unsigned A[5006];
unsigned C[5006][5006], dp[5006][5006], S[5006];
void solve() {
  cin >> n >> d >> P;
  C[0][0] = 1;
  for (unsigned i = (1), iend = (n); i <= iend; ++i) {
    C[i][0] = 1;
    for (unsigned j = (1), jend = (i); j <= jend; ++j)
      C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % P;
  }
  dp[1][0] = 1;
  S[1] = 1;
  for (unsigned i = (2), iend = (n); i <= iend; ++i) {
    for (unsigned k = (1), kend = (i - 1); k <= kend; ++k) {
      for (unsigned j = (1), jend = (i); j <= jend; ++j) {
        dp[i][j] =
            (dp[i][j] + dp[i - k][j - 1] * 1ll * S[k] % P * C[i - 2][k - 1]) %
            P;
      }
    }
    for (unsigned j = (0), jend = (d - 1); j <= jend; ++j)
      S[i] = (S[i] + dp[i][j]) % P;
  }
  unsigned as = 0;
  for (unsigned i = (1), iend = (n); i <= iend; ++i)
    for (unsigned j = (0), jend = (d); j <= jend; ++j)
      for (unsigned k = (0), kend = (d); k <= kend; ++k)
        if (j + k <= d) as = (as + dp[i][j] * 1ll * dp[n - i + 1][k]) % P;
  for (unsigned i = (1), iend = (n); i <= iend; ++i)
    for (unsigned j = (0), jend = (d - 1); j <= jend; ++j)
      for (unsigned k = (0), kend = (d - 1); k <= kend; ++k)
        as = (as + P - dp[i][j] * 1ll * dp[n - i][k] % P) % P;
  cout << as * 2ll * n % P * (n - 1) % P << endl;
}
signed main() { solve(); }
