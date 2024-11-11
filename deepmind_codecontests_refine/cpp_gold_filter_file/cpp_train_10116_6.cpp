#include <bits/stdc++.h>
using namespace std;
namespace cyl {
const long long inf = 1e18;
int n;
long long a[100005], dp[63][100005];
template <class T>
bool chkmin(T &x, T y) {
  return x > y ? x = y, 1 : 0;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%lld", &a[i]);
  sort(a + 1, a + n + 1);
  for (int i = 1; i <= n; ++i) a[i] = a[n] - a[i];
  for (int i = 0; i <= 62; ++i)
    for (int j = 0; j <= n; ++j) dp[i][j] = inf;
  dp[0][0] = 0;
  for (int i = 0; i < 62; ++i) {
    sort(a + 1, a + n + 1, [&](long long x, long long y) {
      return (x & (1ll << i) - 1) > (y & (1ll << i) - 1);
    });
    int cnt = 0, tot = 0;
    for (int j = 1; j <= n; ++j) tot += a[j] >> i & 1;
    for (int j = 0; j <= n; ++j) {
      cnt += a[j] >> i & 1;
      chkmin(dp[i + 1][cnt], dp[i][j] + j - cnt + tot - cnt);
      chkmin(dp[i + 1][tot - cnt + j], dp[i][j] + n - j - (tot - cnt) + cnt);
    }
  }
  cout << dp[62][0] << endl;
  return 0;
}
}  // namespace cyl
int main() { return cyl::main(); }
