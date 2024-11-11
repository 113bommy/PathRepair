#include <bits/stdc++.h>
using namespace std;
long long inf = 3e18;
long long a[(int)1e5], dp[(int)1e5][3];
bool dpb[(int)1e5][3];
int n, p[3];
long long best(int i, int j) {
  if (j == 3) return 0;
  if (i == n) {
    return -inf;
  }
  if (dpb[i][j]) return dp[i][j];
  dpb[i][j] = 1;
  long long mx = best(i + 1, j), q = 0;
  for (int k = 0; k < 3 - j; ++k) {
    q += a[i] * p[j + k];
    mx = max(mx, q + best(i + 1, j + k + 1));
  }
  return dp[i][j] = mx;
}
int main() {
  cin >> n >> p[0] >> p[1] >> p[2];
  for (int i = 0; i < n; ++i) cin >> a[i];
  cout << best(0, 0);
  return 0;
}
