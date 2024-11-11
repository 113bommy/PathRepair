#include <bits/stdc++.h>
using namespace std;
const int MAXI = numeric_limits<int>::max() / 2;
const int MINI = numeric_limits<int>::min() / 2;
const long long MAXL = numeric_limits<long long>::max() / 2;
const long long MINL = numeric_limits<long long>::min() / 2;
long long mpow(long long x, long long n, long long m) {
  long long ans = 1;
  while (n > 0) {
    if ((n & 1) == 1) ans *= x;
    ans %= m;
    n >>= 1;
    x *= x;
    x %= m;
  }
  return ans;
}
static const int N = 1010, K = 110;
int dp[N][K][2];
int r[N];
int main(int argc, char* argv[]) {
  int n, k, m;
  cin >> n >> k >> m;
  int i, j, l;
  r[0] = 1;
  for ((i) = (1); (i) < (n + 1); ++(i)) (r[i] = r[i - 1] * 10) %= k;
  dp[n][0][0] = 1;
  for ((i) = (n); (i) >= (1); --(i)) {
    for ((j) = (0); (j) < (k); ++(j)) {
      for ((l) = (0); (l) < (10); ++(l)) {
        if (i == 1 && l == 0) continue;
        int nj = j + l * r[n - i];
        nj %= k;
        (dp[i - 1][nj][1] += dp[i][j][1]) %= m;
        if (nj == 0 && l != 0)
          (dp[i - 1][nj][1] += dp[i][j][0]) %= m;
        else
          (dp[i - 1][nj][0] += dp[i][j][0]) %= m;
      }
    }
  }
  int ans = 0;
  for ((j) = (0); (j) < (k); ++(j)) {
    ans += dp[0][j][1];
    ans %= m;
  }
  cout << ans << endl;
  return 0;
}
