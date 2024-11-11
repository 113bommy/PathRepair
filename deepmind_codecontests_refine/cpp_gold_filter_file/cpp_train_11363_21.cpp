#include <bits/stdc++.h>
const int Inf = 2 * 1000 * 1000 * 1000;
long long LINF = (long long)4e18;
using namespace std;
long long dp[505][505];
long long dinam(long long i, long long j) {
  if (i + 2 > j) {
    return i * (i + 1);
  }
  if (i + 2 == j) {
    return i * (i + 1) * (i + 2);
  }
  if (dp[i][j] != -1) return dp[i][j];
  long long tmp = 1e18;
  for (long long k = i + 2; k < j; k++) {
    tmp = min(tmp, dinam(i, k) + dinam(k, j));
  }
  return dp[i][j] = tmp;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  memset(dp, -1, sizeof(dp));
  cout << dinam(1, n);
  return 0;
}
