#include <bits/stdc++.h>
using namespace std;
const int maxn = 50;
pair<long long, long long> dp[maxn][maxn];
long long n;
string A;
long long a[maxn];
long long ans[maxn];
long long up[maxn][maxn];
long long b[maxn];
int main() {
  ios_base::sync_with_stdio(false);
  cin >> n >> A;
  b[0] = 1;
  for (long long y = 2 * n; y > 0; y--) {
    a[y] = A[y - 1] - '0';
  }
  for (long long y = 1; y <= n; y++) b[y] = 10LL * b[y - 1];
  for (long long y = 2 * n; y; y--) {
    for (long long i = 0; i <= min(n, 2 * n - y + 1); i++) {
      pair<long long, long long> d, c;
      d = c = pair<long long, long long>(0, 0);
      if (i)
        d = pair<long long, long long>(a[y] * b[i - 1] + dp[y + 1][i - 1].first,
                                       dp[y + 1][i - 1].second);
      if (2 * n - y + 1 - i > 0)
        c = pair<long long, long long>(
            dp[y + 1][i].first, dp[y + 1][i].second + a[y] * b[2 * n - y - i]);
      if (d.second + d.first < c.second + c.first) swap(c, d), up[y][i] = 1;
      dp[y][i] = d;
    }
  }
  long long i = n;
  for (long long y = 1; y <= 2 * n; y++) {
    if (up[y][i] == 0 && i > 0) ans[y] = 1, i--;
  }
  for (long long y = 1; y <= 2 * n; y++) {
    if (ans[y] == 1)
      cout << "H";
    else
      cout << "M";
  }
}
