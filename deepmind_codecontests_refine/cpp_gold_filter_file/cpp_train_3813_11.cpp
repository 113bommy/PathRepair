#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, m, k;
  cin >> n >> m >> k;
  long long grid[n + 5][m + 5];
  for (long long i = 1; i <= n; i++) {
    for (long long j = 1; j <= m; j++) {
      cin >> grid[i][j];
    }
  }
  long long ans = 0, r = 0;
  for (long long j = 1; j <= m; j++) {
    vector<long long> cum(n + 5, 0);
    long long p = 0, q = 0;
    for (long long i = 1; i <= n; i++) {
      cum[i] = cum[i - 1];
      if (grid[i][j] == 1) {
        cum[i]++;
      }
    }
    long long cur_ans = 0;
    for (long long i = 1; i <= n; i++) {
      if (grid[i][j] == 1) {
        long long x = min(n, i + k - 1);
        if (p == 0) {
          p = 1;
          cur_ans = cum[x] - cum[i - 1];
          q = cum[i - 1];
        }
        long long y = cum[x] - cum[i - 1];
        if (y > cur_ans) {
          cur_ans = y;
          q = cum[i - 1];
        }
      }
    }
    ans = ans + cur_ans;
    r = r + q;
  }
  cout << ans << ' ' << r;
  return 0;
}
