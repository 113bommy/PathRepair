#include <bits/stdc++.h>
using namespace std;
const long long inf = 0x3f3f3f3f;
const double PI = acos(-1.0);
const double eps = 1e-9;
const int maxn = 2e5 + 5;
long long n, m, k, x, y;
long long a[maxn], sum[maxn], dp[maxn], mx[maxn];
int main() {
  std::ios::sync_with_stdio(0);
  cin >> n >> m >> k;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  for (int i = 1; i <= m; ++i) {
    cin >> x >> y;
    mx[x] = max(mx[x], y);
  }
  sort(a + 1, a + 1 + n);
  for (int i = 1; i <= k; ++i) sum[i] = sum[i - 1] + a[i];
  for (int i = 1; i <= k; ++i) {
    for (int j = 0; j <= i; ++j) {
      dp[i] = max(dp[i], dp[j] + sum[j + mx[i - j]] - sum[j]);
    }
  }
  cout << sum[k] - dp[k] << endl;
  return 0;
}
