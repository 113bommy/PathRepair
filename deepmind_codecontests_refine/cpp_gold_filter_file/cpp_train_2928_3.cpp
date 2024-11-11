#include <bits/stdc++.h>
using namespace std;
template <typename T>
bool mmax(T &m, const T q) {
  if (m < q) {
    m = q;
    return true;
  } else
    return false;
}
template <typename T>
bool mmin(T &m, const T q) {
  if (m > q) {
    m = q;
    return true;
  } else
    return false;
}
const int MOD = 1e9 + 7;
const int MAXN = 1e5 + 5;
long long dp[201][201];
int main(int argc, char **argv) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, k, x;
  cin >> n >> k >> x;
  vector<int> a(n);
  for (int i = 0; i < (int)(n); ++i) cin >> a[i];
  for (int i = 0; i < (int)(k); ++i) dp[i][1] = a[i];
  for (int j = (int)(2); j <= (int)(x); ++j) {
    for (int i = (int)(j - 1); i <= (int)(n - 1); ++i) {
      for (int t = i - 1; t >= max(0, i - k); t--) {
        if (dp[t][j - 1]) mmax(dp[i][j], dp[t][j - 1] + a[i]);
      }
    }
  }
  long long ans = -1;
  for (int t = n - 1; t >= max(0, n - k); t--) {
    if (dp[t][x]) mmax(ans, dp[t][x]);
  }
  cout << ans << endl;
  return 0;
}
