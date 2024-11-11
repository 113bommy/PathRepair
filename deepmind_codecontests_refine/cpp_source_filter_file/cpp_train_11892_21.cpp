#include <bits/stdc++.h>
using namespace std;
const long long N = 1e3 + 5;
const long long MOD = 1e9 + 7;
long long nCr[N][N];
void precompute() {
  nCr[0][0] = 1;
  for (long long i = 1; i < N; i++) {
    nCr[i][0] = 1;
    for (long long j = 1; j <= i; j++) {
      nCr[i][j] = nCr[i - 1][j - 1] + nCr[i - 1][j];
      nCr[i][j] %= MOD;
    }
  }
}
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  precompute();
  long long n, m, k;
  cin >> n >> m >> k;
  long long ans = nCr[n - 1][2 * k] * nCr[m - 1][2 * k];
  ans %= MOD;
  cout << ans;
  return 0;
}
